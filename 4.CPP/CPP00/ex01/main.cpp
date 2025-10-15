/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 17:05:11 by dinguyen          #+#    #+#             */
/*   Updated: 2025/10/13 17:09:30 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main()
{
	PhoneBook	phoneBook;
	std::string	command;
	std::cout<<" ============================================== "<<std::endl;
	std::cout<<"       Welcome to your AWESOME phone book!"<<std::endl;
	std::cout<<" ============================================== "<<std::endl;
	while (true) {
		std::cout<<"Enter a command: ADD, SEARCH or EXIT"<<std::endl;
		std::getline(std::cin, command);
		if (command == "ADD")
			phoneBook.addContact();
		else if (command == "SEARCH")
			phoneBook.searchContact();
		else if (command == "EXIT")
		{
			std::cout<<"Goodbye !"<<std::endl;
			break ;
		}
		else
			std::cout<<"Invalid command"<<std::endl;
	}
	return (0);
}
