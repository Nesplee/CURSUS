/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 13:50:12 by dinguyen          #+#    #+#             */
/*   Updated: 2025/10/13 14:01:28 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Megaphone.hpp"

int	main(int ac, char **av) {

	if (ac == 1) {
		std::cout<<"* LOUD AND UNBEARABLE FEEDBACK NOISE *"<<std::endl;
		return (0);
	}
	Megaphone	Converter;
	std::string	result;
	for (int i = 1; i < ac; i++ ) {
		result = Converter.toUpperCase(av[i]);
		std::cout<<result;
		if (i < ac - 1) {
			std::cout<<" ";
		}
	}
	std::cout<<std::endl;
	return (0);
}
