/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   harlFilter.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 10:15:08 by dinguyen          #+#    #+#             */
/*   Updated: 2025/08/18 10:32:28 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "harlFilter.hpp"

HarlFilter::HarlFilter() {
	std::cout<<"Harl constructor called"<<std::endl;
}

HarlFilter::~HarlFilter() {
	std::cout<<"Harl destructor called"<<std::endl;
}

//	PRIVATES METHODS
void	HarlFilter::_debug(void) const {
	std::cout<<"[DEBUG] : ";
	std::cout<<"I love having extra bacon for my ";
	std::cout<<"7XL-double-cheese-triple-pickle-special-ketchup burger. ";
	std::cout<<"I really do!";
	std::cout<<std::endl;
}

void	HarlFilter::_info(void) const {
	std::cout<<"[INFO] : ";
	std::cout<<"I cannot believe adding extra bacon costs more money. ";
	std::cout<<"You didn’t put enough bacon in my burger! ";
	std::cout<<"If you did, I wouldn’t be asking for more!";
	std::cout<<std::endl;
}

void	HarlFilter::_warning(void) const {
	std::cout<<"[WARNING] : ";
	std::cout<<"I think I deserve to have some extra bacon for free. ";
	std::cout<<"I’ve been coming for years, ";
	std::cout<<"whereas you started working here just last month.";
	std::cout<<std::endl;
}

void	HarlFilter::_error(void) const {
	std::cout<<"[ERROR] : ";
	std::cout<<"This is unacceptable! I want to speak to the manager now.";
	std::cout<<std::endl;
}

void	HarlFilter::complain(std::string level) const {
	std::string	levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	void	(HarlFilter::*functions[4])(void) const = { &HarlFilter::_debug, &HarlFilter::_info, &HarlFilter::_warning, &HarlFilter::_error };
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

int	HarlFilter::_getLevelIndex(std::string level) const
{
	std::string	levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int			i         = 0;

	while (i < 4)
	{
		if (levels[i] == level)
			return (i);
		i++;
	}
	return (-1);
}

void	HarlFilter::filter(std::string level)
{
	int	levelIndex = _getLevelIndex(level);

	switch	(levelIndex) {
		case 0:
		_debug();
		// fallthrough
		case 1:
		_info();
		// fallthrough
		case 2:
		_warning();
		// fallthrough
		case 3:
		_error();
		break ;
	default:
		std::cout << "[Probably complaining about insignificant problems]" << std::endl;
		break ;
	}
}
