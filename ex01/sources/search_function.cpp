/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_function.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 10:07:25 by jduval            #+#    #+#             */
/*   Updated: 2023/07/21 18:55:44 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "utils.hpp"

/*
Affiche les contacts enregistrés sous la forme d’une liste de 4 colonnes : index,
first name, last name et nickname.
◦ Chaque colonne doit faire 10 caractères de long. Elles doivent être séparées
par un pipe (’|’). Leur texte est aligné à droite. Si le texte dépasse la largeur
de la colonne, il faut le tronquer et remplacer le dernier caractère affiché par
un point (’.’).
◦ Ensuite, le programme demande à l’utilisateur d’entrer l’index du contact à afficher. Si l’index ou son format sont incorrects, gérez cela de manière pertinente.
Sinon, affichez les informations du contact, une par ligne.
*/

static void	display_contact(PhoneBook &book)
{
	int	part_displayable;

	part_displayable = number_of_contacts / 2;
	if (part_displayable == 0)
		part_displayable = 1;
	for (int i = 0; i < part_displayable)
	{
		Contact	&contact = get_contact(i);
		if (contact.get_id() == -1)
			continue ;
		else
			contact.display_base_search();
	}
}

int	search_input(PhoneBook &book)
{
	int	index;
	std::string	input;

	if (is_phonebook_empty(book) == true)
	{
		std::cout << search_request[1] << std::endl;
		return (0);
	}
	display_contact(book);
	while (getline(std::cin, input))
	{
		if (input == user_pathern[3])
		{
			std::cout << user_pathern[4] << std::endl;
			return (0);
		}
		try
			index = std::stoi(input);
		catch (const std::out_of_range &overflow)
		{
			std::cout << overflow.what() << bad_input[4] << number_of_contact << std::endl;
			continue ;
		}
	}
	return (0);
}
