/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 18:15:32 by dinguyen          #+#    #+#             */
/*   Updated: 2025/08/18 10:29:27 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "harlFilter.hpp"

int main(int argc, char** argv)
{
	if (argc != 2) {
		std::cout << "Usage: " << argv[0] << " <level>" << std::endl;
		std::cout << "Levels: DEBUG, INFO, WARNING, ERROR" << std::endl;
		return 1;
	}
	HarlFilter	harl;
	std::string	level = argv[1];
	harl.filter(level);
	return 0;
}
