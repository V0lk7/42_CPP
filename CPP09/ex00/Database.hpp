/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Database.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 13:52:33 by jduval            #+#    #+#             */
/*   Updated: 2023/10/09 11:38:42 by jduval           ###   ########.fr       */
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

		void		verifyDataHeader(void);
		void		verifyInputHeader(void);
		void		parsingDatabase(void);
		void		visualizeDataRelation(void);

	public :

		Database();
		~Database();

		Database	&openDataBaseFile(void);
		Database	&openInputFile(char *arg);
		double		getValue(std::string Date);
		void		findInputsInDatabase(void);

		std::map<std::string, double>::iterator	getIteratorBegin(void);
		std::map<std::string, double>::iterator	getIteratorEnd(void);
		void		createDatabase(void);
		bool		setData(std::string const Date, double const Value);
};

std::ostream	&operator<<(std::ostream &o, Database &rhs);

#endif
