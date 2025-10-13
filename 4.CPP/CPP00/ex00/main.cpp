/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 09:18:47 by dinguyen          #+#    #+#             */
/*   Updated: 2025/10/06 09:22:48 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Megaphone.hpp"

int	main(int ac, char **av)
{
	if (ac == 1) {
		std::cout<<"* LOUD AND UNBEARABLE FEEDBACK NOISE *"<<std::endl;
		return (0);
	}
	Megaphone	Converter;
	int			i = 1;
	while (i < ac)
	{
		std::string	result = Converter.toUpperCase(av[i]);
		std::cout<<result;
		if (i < ac - 1)
			std::cout<<" ";
		i++;
	}
	std::cout<<std::endl;
	return (0);
}
