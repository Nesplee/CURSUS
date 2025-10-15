/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 11:51:43 by dinguyen          #+#    #+#             */
/*   Updated: 2025/09/03 14:53:31 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name) {
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout<<"ScavTrap constructor called"<<std::endl;
}

ScavTrap::~ScavTrap() {
	std::cout<<"ScavTrap destructor called"<<std::endl;
}

void	ScavTrap::attack(const std::string &target) {
	if (_energyPoints > 0 && _hitPoints > 0)
	{
		std::cout<<"ScavTrap ";
		std::cout<<_name;
		std::cout<<" attacks ";
		std::cout<<target;
		std::cout<<" causing ";
		std::cout<<_attackDamage;
		std::cout<<" points of damage!";
		std::cout<<std::endl;
		_energyPoints = _energyPoints - 1;
	}
	else if (_energyPoints <= 0) {
		std::cout<<"Not enough points to attack!"<<std::endl;
	}
	else
		std::cout<<"Attack not possible: "<<_name<<" is dead"<<std::endl;
	std::cout<<"Current hit points    : "<<_hitPoints<<std::endl;
	std::cout<<"Current energy points : "<<_energyPoints<<std::endl;
}

void	ScavTrap::guardGate(void) {
	std::cout<<"ScavTrap ";
	std::cout<<_name;
	std::cout<<" is now in Gate keeper mode!"<<std::endl;
}
