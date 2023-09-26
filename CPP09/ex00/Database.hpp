/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Database.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 13:52:33 by jduval            #+#    #+#             */
/*   Updated: 2023/09/26 15:12:35 by jduval           ###   ########.fr       */
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
		std::map<std::string, float>	Data;
		std::ifstream					DataFile;
		std::ifstream					InputFile;

		Database(Database const &src);
		Database	&operator=(Database const &rhs);

	public :

		Database();
		~Database();

		Database	&openDataBaseFile(void);
		Database	&openInputFile(char *arg);
		//void		createDatabase(void);
		//void		findInputsInDatabase(void);

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
};

#endif
