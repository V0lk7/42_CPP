/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Database.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 13:52:33 by jduval            #+#    #+#             */
/*   Updated: 2023/10/01 16:04:24 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATABASE_HPP
# define DATABASE_HPP

# include <map>
# include <fstream>

# define DATAFILE "data.csv"

class Database
{
	private :
		std::map<std::string, double>	Data;
		std::ifstream					DataFile;
		std::ifstream					InputFile;

		Database(Database const &src);
		Database	&operator=(Database const &rhs);

		bool		verifyDataHeader(void);
		bool		verifyInputHeader(void);
		int			parsingDatabase(void);

	public :

		Database();
		~Database();

		Database	&openDataBaseFile(void);
		Database	&openInputFile(char *arg);
		void		createDatabase(void);
		bool		setData(std::string const Date, double const Value);
		double		getValue(std::string Date);
		void		findInputsInDatabase(void);
		int			visualizeDataRelation(void);

		std::map<std::string, double>::iterator	getIteratorBegin(void);
		std::map<std::string, double>::iterator	getIteratorEnd(void);

		class InputFileFailed : public std::exception
		{
			public :
				virtual char const	*what(void) const throw();
		};
		class DataFileFailed : public std::exception
		{
			public :
				virtual char const	*what(void) const throw();
		};
		class WrongHeaderDatabase : public std::exception
		{
			public :
				virtual char const	*what(void) const throw();
		};
		class WrongHeaderInput : public std::exception
		{
			public :
				virtual char const	*what(void) const throw();
		};
		class ErrorReadingDataFile : public std::exception
		{
			public :
				virtual char const	*what(void) const throw();
		};
		class ErrorReadingInputFile : public std::exception
		{
			public :
				virtual char const	*what(void) const throw();
		};
		class EmptyDataFile : public std::exception
		{
			public :
				virtual char const	*what(void) const throw();
		};
		class RegCompFailed : public std::exception
		{
			public :
				virtual char const	*what(void) const throw();
		};
		class RegExecFailed : public std::exception
		{
			public :
				virtual char const	*what(void) const throw();
		};
		class ValueOutOfRange : public std::exception
		{
			public :
				virtual char const	*what(void) const throw();
		};
		class SameDate : public std::exception
		{
			public :
				virtual char const	*what(void) const throw();
		};
};


std::ostream	&operator<<(std::ostream &o, Database &rhs);

#endif
