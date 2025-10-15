/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 08:54:19 by dinguyen          #+#    #+#             */
/*   Updated: 2025/09/04 09:11:04 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(const std::string &name) : ClapTrap(name) {
	std::cout<<"FragTrap constructor called"<<std::endl;
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
}

FragTrap::~FragTrap() {
	std::cout<<"FragTrap destructor called"<<std::endl;
}

void	FragTrap::attack(const std::string &target) {
	if (_energyPoints > 0 && _hitPoints > 0) {
		std::cout<<"FragTrap ";
		std::cout<<_name;
		std::cout<<" attacks, causing ";
		std::cout<<_attackDamage;
		std::cout<<" points of damage!"<<std::endl;
		_energyPoints = _energyPoints - 1;
	}
	else if (_energyPoints <= 0) {
		std::cout<<"Not enough points to attack!"<<std::endl;
	}
	else {
		std::cout<<_name<<" can't attack. Because he's dead."<<std::endl;
	}
	std::cout<<"Current hit points    : "<<_hitPoints<<std::endl;
	std::cout<<"Current energy points : "<<_energyPoints<<std::endl;
}

void	FragTrap::highFivesGuys(void) {
	std::cout<<"FragTrap ";
	std::cout<<_name;
	std::cout<<" requests a positive high five! ✋"<<std::endl;
}
