/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 11:07:42 by dinguyen          #+#    #+#             */
/*   Updated: 2025/09/01 12:30:30 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(const std::string &name) :
	_name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout<<"ClapTrap constructor called with name "<<_name<<" in parameter"<<std::endl;
}

ClapTrap::~ClapTrap() {
	std::cout<<"ClapTrap destructor called"<<std::endl;
}

void ClapTrap::attack(const std::string& target) {
	if (_hitPoints > 0 && _energyPoints > 0) {
		std::cout<<"ClapTrap ";
		std::cout<<_name;
		std::cout<<" attacks ";
		std::cout<<target;
		std::cout<<", causing ";
		std::cout<<_attackDamage;
		std::cout<<" points of damage!"<<std::endl;
		_energyPoints = _energyPoints - 1;
	}
	else if (_energyPoints <= 0)
		std::cout<<"No points available to attack!"<<std::endl;
	else
		std::cout<<"Attack not possible: "<<_name<<" is dead"<<std::endl;
	std::cout<<"Current hit points    : "<<_hitPoints<<std::endl;
	std::cout<<"Current energy points : "<<_energyPoints<<std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount) {
	if (_hitPoints > 0) {
		std::cout<<"ClapTrap ";
		std::cout<<_name;
		std::cout<<" took ";
		std::cout<<amount;
		std::cout<<" points of damage!"<<std::endl;
		_hitPoints = _hitPoints - amount;
	}
	if (_hitPoints <= 0) {
		_hitPoints = 0;
		std::cout<<"ClapTrap is already dead!"<<std::endl;
	}
	else
		std::cout<<_hitPoints<<" left!"<<std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount) {
	if (_hitPoints > 0 && _energyPoints > 0) {
		std::cout<<"ClapTrap ";
		std::cout<<_name;
		std::cout<<" repairs itself of ";
		std::cout<<amount;
		std::cout<<" points!"<<std::endl;
		_hitPoints = _hitPoints + amount;
		_energyPoints = _energyPoints - 1;
		std::cout<<"Current hit points    : "<<_hitPoints<<std::endl;
		std::cout<<"Current energy points : "<<_energyPoints<<std::endl;
	}
	else if (_energyPoints <= 0)
		std::cout<<"Not enough points to repair!"<<std::endl;
	else
		std::cout<<"ClapTrap is already dead!"<<std::endl;
}
