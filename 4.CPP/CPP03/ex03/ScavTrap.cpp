/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 11:15:34 by dinguyen          #+#    #+#             */
/*   Updated: 2025/11/22 14:30:59 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name) {
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	_keeperMode = false;
	std::cout<<"ScavTrap "<<_name<<" constructor called"<<std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other) {
	_keeperMode = other._keeperMode;
	std::cout<<"ScavTrap copy constructor called"<<std::endl;
}

ScavTrap&	ScavTrap::operator=(const ScavTrap &other) {
	if (this != &other) {
		ClapTrap::operator=(other);
		_keeperMode = other._keeperMode;
		std::cout<<"ScavTrap copy assignment operator called"<<std::endl;
	}
	return (*this);
}

ScavTrap::~ScavTrap() {
	std::cout<<"ScavTrap "<<_name<<" destructor called"<<std::endl;
}

void	ScavTrap::attack(const std::string &target) {
	if (_hitPoints <= 0) {
		std::cout<<"I'm dead, I can't attack anything"<<std::endl;
		return ;
	}
	if (_energyPoints > 0) {
		_energyPoints--;
		std::cout<<"ScavTrap "<<_name<<" attacks "<<target<<", causing ";
		std::cout<<_attackDamage<<" points of damage!"<<std::endl;
	} else {
		std::cout<<"Not enough energy points to attack!"<<std::endl;
	}
}

void	ScavTrap::guardGate(void) {
	if (_hitPoints <= 0) {
		std::cout<<"I'm dead. Gate keeper mode impossible when dead"<<std::endl;
	} else if (_keeperMode == 1) {
		std::cout<<"Gate keeper mode desactivate."<<std::endl;
		_keeperMode = false;
	} else {
		_keeperMode = true;
		std::cout<<"ScavTrap "<<_name<<" is now in Gate keeper mode"<<std::endl;
	}
}

