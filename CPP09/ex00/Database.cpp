/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Database.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 14:13:09 by jduval            #+#    #+#             */
/*   Updated: 2023/09/26 15:12:36 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Database.hpp"
#include "UserMessages.hpp"

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

/*===========================Creating Database================================*/

/*void	Database::createDatabase(void)
{

}*/


/*===========================================================================*/

/*===========================Class Exceptions================================*/

char const	*Database::InputFileFailed::what(void) const throw()
{
	return (ErrorOpeningFiles[0].c_str());
}

char const	*Database::DataFileFailed::what(void) const throw()
{
	return (ErrorOpeningFiles[1].c_str());
}
