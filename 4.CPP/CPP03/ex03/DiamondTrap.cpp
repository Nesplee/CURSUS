/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 09:34:51 by dinguyen          #+#    #+#             */
/*   Updated: 2025/11/22 16:18:53 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(const std::string &name) : ClapTrap(name + "_clap_name"),
		ScavTrap(name), FragTrap(name) {
	_name = name;
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 30;
	std::cout<<"DiamondTrap "<<_name<<" constructor called"<<std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other) : ClapTrap(other), ScavTrap(other),
	FragTrap(other) {
	_name = other._name;
	std::cout<<"DiamondTrap "<<_name<<" copy constructor called"<<std::endl;
}

DiamondTrap&	DiamondTrap::operator=(const DiamondTrap &other) {
	if (this != &other) {
		ClapTrap::operator=(other);
		ScavTrap::operator=(other);
		FragTrap::operator=(other);
		_name = other._name;
	}
	std::cout<<"DiamondTrap copy assignment operator called"<<std::endl;
	return (*this);
}

DiamondTrap::~DiamondTrap() {
	std::cout<<"DiamondTrap destructor called"<<std::endl;
}

void	DiamondTrap::whoAmI() {
	std::cout<<"I am "<<_name<<" and my ClapTrap name is ";
	std::cout<<ClapTrap::_name<<std::endl;
}
