/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 09:34:51 by dinguyen          #+#    #+#             */
/*   Updated: 2025/09/04 09:39:05 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(const std::string &name)
	: ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), _name(name) {
		_hitPoints = FragTrap::_hitPoints;
		_energyPoints = ScavTrap::_energyPoints;
		_attackDamage = FragTrap::_attackDamage;
		std::cout<<"DiamondTrap constructor called"<<std::endl;
}

DiamondTrap::~DiamondTrap() {
	std::cout<<"DiamondTrap destructor called"<<std::endl;
}

void	DiamondTrap::whoAmI() {
	std::cout<<"I am ";
	std::cout<<_name;
	std::cout<<" and my ClapTrap name is ";
	std::cout<<ClapTrap::_name<<std::endl;
}
