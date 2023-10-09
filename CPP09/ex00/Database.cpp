/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Database.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 14:13:09 by jduval            #+#    #+#             */
/*   Updated: 2023/10/09 11:38:41 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Database.hpp"
#include <cstdlib>
#include <iostream>
#include "regex.h"

#define ERROR_DATE 1
#define NEGATIVE_VALUE 2
#define OUT_OF_RANGE 3

static const char	*ErrorOpeningFiles[2] =
{
	"btc: Open: Error occured during INPUT file opening, please make sure your file exist and it's readable.\n",
	"btc: Open: Error occured during DATA file opening, please verify that data.csv exist and it's readable.\n"
};

static const char	*RegexUtils[2] = 
{
	"^[0-9]{4}-\\b(0[1-9]|1[0-2])\\b-\\b(0[1-9]|[12][0-9]|3[01])\\b,([0-9]+\\.[0-9]+$|[0-9]+$)",
	"^[0-9]{4}-\\b(0[1-9]|1[0-2])\\b-\\b(0[1-9]|[12][0-9]|3[01])\\b \\| -?([0-9]+\\.[0-9]+$|[0-9]+$)"
};

static const int	Dates[12] = {31, 0, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

/*============================================================================*/
/*===========================Constructors/Destructors=========================*/

Database::Database(){}

Database::~Database()
{
	if (this->DataFile.is_open() == true)
		this->DataFile.close();
	if (this->InputFile.is_open() == true)
		this->InputFile.close();
}

Database::Database(Database const &src)
{
	(void)src;
}

Database	&Database::operator=(Database const &rhs)
{
	(void) rhs;
	return (*this);
}

/*===========================================================================*/
/*===========================Opening Files===================================*/

Database	&Database::openDataBaseFile(void)
{
	this->DataFile.open(DATAFILE, std::ifstream::in);
	if (DataFile.fail() == true)
	{
		if (this->InputFile.is_open() == true)
			this->InputFile.close();
		throw (std::runtime_error(ErrorOpeningFiles[1]));
	}
	return (*this);
}

Database	&Database::openInputFile(char *file)
{
	this->InputFile.open(file, std::ifstream::in);
	if (InputFile.fail() == true)
	{
		if (this->DataFile.is_open() == true)
			this->DataFile.close();
		throw (std::runtime_error(ErrorOpeningFiles[0]));
	}
	return (*this);
}

/*===========================================================================*/
/*===========================Creating Database===============================*/

static void	ExtractData(Database &Data, std::string &DataExtracted, regex_t &DataRegex);

void	Database::createDatabase(void)
{
	this->verifyDataHeader();
	this->parsingDatabase();
	if (this->Data.empty() == true)
		throw (std::runtime_error("btc: Database: File is empty.\n"));
	return ;
}

void	Database::parsingDatabase(void)
{
	regex_t		DataRegex;
	std::string	DataExtract;

	if (regcomp(&DataRegex, RegexUtils[0], REG_EXTENDED) != 0)
		throw (std::runtime_error("btc: Database: Error in creation of the data Regex.\n"));
	while (getline(this->DataFile, DataExtract))
	{
		if (this->DataFile.fail() == true)
		{
			regfree(&DataRegex);
			throw (std::runtime_error("btc: Database: An error occurred during the reading.\n"));
		}
		else
		{
			ExtractData(*this, DataExtract, DataRegex);
			if (this->DataFile.eof() == true)
				break ;
		}
	}
	regfree(&DataRegex);
	return ;
}

static bool	ValidateDate(std::string Date);

static void	ExtractData(Database &Data, std::string &DataExtracted, regex_t &DataRegex)
{
	if (regexec(&DataRegex, DataExtracted.c_str(), 0, NULL, 0) == REG_NOMATCH)
	{
		std::cerr << "btc: Database: Error Format => \'" << DataExtracted << '\'' << std::endl;
		regfree(&DataRegex);
		throw (std::runtime_error(""));
	}
	else
	{
		std::string	const Date(DataExtracted, 0, 10);
		double	const Value = strtod(&(DataExtracted.c_str())[11], NULL);

		if (errno == ERANGE)
		{
			regfree(&DataRegex);
			throw (std::runtime_error("btc: Database: Value overflow.\n"));
		}
		if (ValidateDate(Date) == false)
		{
			regfree(&DataRegex);
			throw (std::runtime_error("btc: Database: Date isn't valid.\n"));
		}
		if (Data.setData(Date, Value) == false)
		{
			regfree(&DataRegex);
			throw (std::runtime_error("btc: Database: Can't have the same date twice.\n"));
		}
	}
}

void	Database::verifyDataHeader(void)
{
	std::string	Header;

	getline(this->DataFile, Header);
	if (this->DataFile.fail() == true && this->DataFile.eof() == false)
		throw (std::runtime_error("btc: Database: An error occured during the reading of the Datafile.\n"));
	if (Header.compare("date,exchange_rate") != 0)
		throw (std::runtime_error("btc: Database: Wrong Header format in database file.\n"));
	return ;
}

/*============================================================================*/
/*==========================MakeRepresentativeValue===========================*/

void	Database::findInputsInDatabase(void)
{
	this->verifyInputHeader();
	this->visualizeDataRelation();
	return ;
}

void	Database::verifyInputHeader(void)
{
	std::string	Header;

	getline(this->InputFile, Header);
	if (this->DataFile.fail() == true && this->DataFile.eof() == false)
		throw (std::runtime_error("btc: Inputfile: An error occured during the reading of the InputFile.\n"));
	if (Header.compare("date | value") != 0)
		throw (std::runtime_error("btc: Inputfile: Wrong Header format in database file.\n"));
}

static void	ParseInput(Database &Data, std::string &InputExtracted, regex_t &InputRegex);

void	Database::visualizeDataRelation(void)
{
	regex_t		InputRegex;
	std::string	InputExtract;

	if (regcomp(&InputRegex, RegexUtils[1], REG_EXTENDED) != 0)
		throw (std::runtime_error("btc: Inputfile: Error in creation of the data Regex.\n"));
	while (getline(this->InputFile, InputExtract))
	{
		if (this->InputFile.fail() == true)
		{
			regfree(&InputRegex);
			throw (std::runtime_error("btc: Inputfile: An error occurred during the reading.\n"));
		}
		else
		{
			ParseInput(*this, InputExtract, InputRegex);
			if (this->InputFile.eof() == true)
				break ;
		}
	}
	regfree(&InputRegex);
	return ;
}

static void	DisplayErrorOutput(std::string Date, int flag);
static int	ValidDataInput(std::string Date, double Value);

static void ParseInput(Database &Data, std::string &InputExtracted, regex_t &InputRegex)
{
	if (regexec(&InputRegex, InputExtracted.c_str(), 0, NULL, 0) == REG_NOMATCH)
	{
		std::cout << "btc: InputFile: Error Format => \'" << InputExtracted << '\'' << std::endl;
		return ;
	}

	std::string	Date(InputExtracted, 0, 10);
	double		Value = strtod(&(InputExtracted.c_str())[13], NULL);
	double		ValueInData;
	int			Flag = 0;

	Flag = ValidDataInput(Date, Value);
	if (Flag != 0)
		DisplayErrorOutput(Date, Flag);
	else
	{
		ValueInData = Data.getValue(Date);
		if (ValueInData == -1.0)
			std::cout << InputExtracted << " => Data can't be find in the database." << std::endl;
		else
		{
			double Result = Value * ValueInData;
			if (Result == -1.0)
				std::cout << Date << " | " << "OverFlow value" << std::endl;
			else
				std::cout << Date << " | " << Value << " | " << Result << std::endl;
		}
	}
	return ;
}

/*===========================================================================*/
/*==============================Set/Get======================================*/

std::map<std::string, double>::iterator	Database::getIteratorBegin(void)
{
	return (this->Data.begin());
}

std::map<std::string, double>::iterator	Database::getIteratorEnd(void)
{
	return (this->Data.end());
}

bool	Database::setData(std::string const Date, double const Value)
{
	std::pair<std::map<std::string, double>::iterator,bool> Existing;
	Existing = this->Data.insert(std::make_pair(Date, Value));
	if (Existing.second == false)
		return (false);
	else
		return (true);
}

double	Database::getValue(std::string Date)
{
	std::map<std::string, double>::iterator	ItObject;

	ItObject = this->Data.find(Date);
	if (ItObject != this->Data.end())
		return (ItObject->second);
	else
		ItObject = this->Data.lower_bound(Date);
	if (ItObject != this->Data.begin())
		ItObject--;
	else 
		return (-1.0);
	return (ItObject->second);
}

/*===========================================================================*/
/*===========================Utility functions===============================*/

static int	ValidDataInput(std::string Date, double Value)
{
	if (ValidateDate(Date) == false)
		return (ERROR_DATE);
	if (errno == ERANGE || Value > 1000.0)
		return (OUT_OF_RANGE);
	if (Value < 0.0)
		return (NEGATIVE_VALUE);
	return (0);
}

static bool	ValidateDate(std::string Date)
{
	int		Year = static_cast<int>(strtod(Date.substr(0, 4).c_str(), NULL));
	int		Month = static_cast<int>(strtod(Date.substr(5, 2).c_str(), NULL));
	int		Day = static_cast<int>(strtod(Date.substr(8, 2).c_str(), NULL));
	bool	LeapYear = false;

	if ((Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0))
		LeapYear = true;
	if (Month != 2 && Month > 0)
	{
		if (Day > 0 && Day <= Dates[Month - 1])
			return (true);
		else
			return (false);
	}
	else if (Month == 2)
	{
		if (Day <= 0)
			return (false);
		else if (LeapYear == true && Day <= 29)
			return (true);
		else if (LeapYear == false && Day <= 28)
			return (true);
		else
			return (false);
	}
	else
		return (false);
}

static void	DisplayErrorOutput(std::string Date, int flag)
{
	if (flag == ERROR_DATE)
		std::cout << "btc: Date error => " << Date << '.' << std::endl;
	else if (flag == OUT_OF_RANGE)
		std::cout << "btc: Value out of range. [0-1000] range needed."<< std::endl;
	else
		std::cout << "btc: Negative value. [0-1000] range needed." << std::endl;
}

/*===========================================================================*/
/*===========================Overload Operator===============================*/

std::ostream	&operator<<(std::ostream &o, Database &rhs)
{
	std::map<std::string, double>::iterator ItBegin = rhs.getIteratorBegin();
	std::map<std::string, double>::iterator ItEnd = rhs.getIteratorEnd();

	while (ItBegin != ItEnd)
	{
		o << "Key = " << ItBegin->first << ", Value = " << ItBegin->second;
		ItBegin++;
		if (ItBegin != ItEnd)
			o << std::endl;
	}
	return (o);
}
