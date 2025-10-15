/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 08:03:43 by dinguyen          #+#    #+#             */
/*   Updated: 2025/08/18 10:20:17 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "harl.hpp"

Harl::Harl() {
	std::cout<<"Harl constructor called"<<std::endl;
}

Harl::~Harl() {
	std::cout<<"Harl destructor called"<<std::endl;
}

//	PRIVATES METHODSHarl:
void	Harl::_debug(void) const {
	std::cout<<"[DEBUG] : ";
	std::cout<<"I love having extra bacon for my ";
	std::cout<<"7XL-double-cheese-triple-pickle-special-ketchup burger. ";
	std::cout<<"I really do!";
	std::cout<<std::endl;
}

void	Harl::_info(void) const {
	std::cout<<"[INFO] : ";
	std::cout<<"I cannot believe adding extra bacon costs more money. ";
	std::cout<<"You didn’t put enough bacon in my burger! ";
	std::cout<<"If you did, I wouldn’t be asking for more!";
	std::cout<<std::endl;
}

void	Harl::_warning(void) const {
	std::cout<<"[WARNING] : ";
	std::cout<<"I think I deserve to have some extra bacon for free. ";
	std::cout<<"I’ve been coming for years, ";
	std::cout<<"whereas you started working here just last month.";
	std::cout<<std::endl;
}

void	Harl::_error(void) const {
	std::cout<<"[ERROR] : ";
	std::cout<<"This is unacceptable! I want to speak to the manager now.";
	std::cout<<std::endl;
}

void	Harl::complain(std::string level) const {
	std::string	levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	void	(Harl::*functions[4])(void) const = { &Harl::_debug, &Harl::_info, &Harl::_warning, &Harl::_error };
	int		i = 0;
	while (i < 4)
	{
		if (levels[i] == level)
		{
			((*this).*functions[i])();
			return ;
		}
		i++;
	}
	std::cout << "[Probably complaining about insignificant problems]" << std::endl;
}
