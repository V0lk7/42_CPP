/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Database.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 14:13:09 by jduval            #+#    #+#             */
/*   Updated: 2023/09/30 16:44:55 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Database.hpp"
#include "UserMessages.hpp"
#include <cstdlib>
#include <iostream>
#include "regex.h"

#define ERROR_READING 1
#define ERROR_REGCOMP 3 
#define ERROR_REGEXEC 4
#define OUT_OF_RANGE 5
#define SAME_DATE 6

static const char	*RegexUtils[2] = 
{
	"^[0-9]{4}-\\b(0[1-9]|1[0-2])\\b-\\b(0[1-9]|[12][0-9]|3[01])\\b,([0-9]+\\.[0-9]+$|[0-9]+$)",
	"/^[0-9]{4}-\\b(0[1-9]|1[0-2])\\b-\\b(0[1-9]|[12][0-9]|3[01])\\b \\| ([0-9]+\\.[0-9]+$|[0-9]+$)"
};

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
		throw (Database::DataFileFailed());
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
		throw (Database::InputFileFailed());
	}
	return (*this);
}

/*===========================================================================*/
/*===========================Creating Database===============================*/

static bool	ExtractData(Database &Data, std::string &DataExtracted, regex_t &DataRegex);
static void	ErrorExtractData(int flag);

void	Database::createDatabase(void)
{
	int	ErrorFlag;

	if (this->DataFile.fail() == true)
		throw (Database::DataFileFailed());
	if (this->verifyDataHeader() == false)
		throw (Database::WrongHeaderDatabase());
	ErrorFlag = this->parsingDatabase();
	if (ErrorFlag != 0)
		ErrorExtractData(ErrorFlag);
	if (this->Data.empty() == true)
		throw (Database::EmptyDataFile());
	return ;
}

int	Database::parsingDatabase(void)
{
	regex_t		DataRegex;
	std::string	DataExtract;
	int			flag = 0;

	if (regcomp(&DataRegex, RegexUtils[0], REG_EXTENDED) != 0)
		return (ERROR_REGCOMP);
	while (getline(this->DataFile, DataExtract))
	{
		if (this->DataFile.fail() == true && this->DataFile.eof() == false)
		{
			regfree(&DataRegex);
			throw (Database::ErrorReadingDataFile());
		}
		else if (this->DataFile.eof() == true)
			break ;
		else
		{
			flag = ExtractData(*this, DataExtract, DataRegex);
			if (flag != 0)
				break ;
		}
	}
	regfree(&DataRegex);
	return (flag);
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

bool	Database::verifyDataHeader(void)
{
	std::string	Header;

	getline(this->DataFile, Header);
	if (this->DataFile.fail() == true && this->DataFile.eof() == false)
		return (false);
	else if (Header.compare("date,exchange_rate") != 0)
		return (false);
	else
		return (true);
}

/*============================================================================*/
/*==========================MakeRepresentativeValue===========================*/

void	Database::findInputsInDatabase(void)
{
	int	ErrorFlag;

	if (this->DataFile.fail() == true)
		throw (Database::InputFileFailed());
	if (this->verifyInputHeader() == false)
		throw (Database::WrongHeaderInput());
	ErrorFlag = this->visualizeDataRelation();
	if (ErrorFlag != 0)
		ErrorExtractData(ErrorFlag);
	return ;
}

int	Database::visualizeDataRelation(void)
{
	regex_t		InputRegex;
	std::string	InputExtract;
	int			flag = 0;

	if (regcomp(&InputRegex, RegexUtils[1], REG_EXTENDED) != 0)
		return (ERROR_REGCOMP);
	while (getline(this->InputFile, InputExtract))
	{
		if (this->InputFile.fail() == true && this->InputFile.eof() == false)
		{
			regfree(&InputRegex);
			throw (Database::ErrorReadingInputFile());
		}
		else if (this->InputFile.eof() == true)
			break ;
		else
		{
			flag = ParseInput(*this, InputExtract, InputRegex);
			if (flag != 0)
				break ;
		}
	}
	regfree(&InputRegex);
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

/*===========================================================================*/

/*===========================Class Exceptions================================*/

char const	*Database::InputFileFailed::what(void) const throw()
{
	return (ErrorOpeningFiles[0]);
}

char const	*Database::DataFileFailed::what(void) const throw()
{
	return (ErrorOpeningFiles[1]);
}

char const	*Database::WrongHeaderDatabase::what(void) const throw()
{
	return (ErrorParsingFile[0]);
}

char const	*Database::ErrorReadingDataFile::what(void) const throw()
{
	return (ErrorParsingFile[1]);
}

char const	*Database::EmptyDataFile::what(void) const throw()
{
	return (ErrorParsingFile[2]);
}

char const	*Database::RegCompFailed::what(void) const throw()
{
	return (ErrorParsingFile[3]);
}

char const	*Database::RegExecFailed::what(void) const throw()
{
	return (ErrorParsingFile[4]);
}

char const	*Database::ValueOutOfRange::what(void) const throw()
{
	return (ErrorParsingFile[5]);
}

char const	*Database::SameDate::what(void) const throw()
{
	return (ErrorParsingFile[6]);
}

/*===========================================================================*/

/*===========================Utility functions===============================*/

static bool	ExtractData(Database &Data, std::string &DataExtracted, regex_t &DataRegex)
{
	if (regexec(&DataRegex, DataExtracted.c_str(), 0, NULL, 0) == REG_NOMATCH)
		return (ERROR_REGEXEC);
	else
	{
		std::string	const Date(DataExtracted, 0, 10);
		double	const Value = strtod(&(DataExtracted.c_str())[11], NULL);
		if (errno == ERANGE)
			return (OUT_OF_RANGE);
		if (Data.setData(Date, Value) == false)
			return (SAME_DATE);
		return (0);
	}
}

static void	ErrorExtractData(int flag)
{
	if (flag == ERROR_REGCOMP)
		throw (Database::RegCompFailed());
	else if (flag == ERROR_READING)
		throw (Database::ErrorReadingDataFile());
	else if (flag == ERROR_REGEXEC)
		throw (Database::RegExecFailed());
	else if (flag == OUT_OF_RANGE)
		throw (Database::ValueOutOfRange());
	else if (flag == SAME_DATE)
		throw (Database::SameDate());
	else
		return ;
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
