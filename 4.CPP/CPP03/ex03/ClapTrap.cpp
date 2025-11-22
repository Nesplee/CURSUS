/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 17:55:33 by dinguyen          #+#    #+#             */
/*   Updated: 2025/11/19 19:38:24 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(const std::string &name) : _name(name), _hitPoints(10),
		_energyPoints(10), _attackDamage(0) {
		std::cout<<"ClapTrap default constructor called with name: "<<_name;
		std::cout<<std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other) : _name(other._name), _hitPoints(other._hitPoints),
		_energyPoints(other._energyPoints), _attackDamage(other._attackDamage) {
		std::cout<<"ClapTrap copy constructor called"<<std::endl;
}

ClapTrap&	ClapTrap::operator=(const ClapTrap& other) {
	std::cout<<"ClapTrap copy assignment operator called"<<std::endl;
	if (this != &other) {
		(*this)._name = other._name;
		(*this)._hitPoints = other._hitPoints;
		this->_energyPoints = other._energyPoints;
		_attackDamage = other._attackDamage;
	}
	return (*this);
}

ClapTrap::~ClapTrap() {
	std::cout<<"ClapTrap destructor called"<<std::endl;
}

void	ClapTrap::attack(const std::string &target) {
	if (_hitPoints <= 0) {
		std::cout<<"I'm dead, I can't attack anything"<<std::endl;
		return ;
	}
	if (_energyPoints > 0) {
		_energyPoints--;
		std::cout<<"ClapTrap "<<_name<<" attacks "<<target<<", causing ";
		std::cout<<_attackDamage<<" points of damage!"<<std::endl;
	} else {
		std::cout<<"Not enough energy points to attack!"<<std::endl;
	}
}

void	ClapTrap::beRepaired(unsigned int amount) {
	if (_hitPoints <= 0) {
		std::cout<<"Can't repair anything when already brokennnnnnnn"<<std::endl;
		return ;
	}
	if (_energyPoints > 0) {
		_energyPoints--;
		std::cout<<"ClapTrap "<<_name<<" repairs itself and regains "<<amount;
		std::cout<<" hit points!"<<std::endl;
		_hitPoints = _hitPoints + amount;
	} else {
		std::cout<<"Not enough energy points to repair!"<<std::endl;
	}
}

void	ClapTrap::takeDamage(unsigned int amount) {
	_hitPoints = _hitPoints - amount;
	if (_hitPoints < 0) {
		_hitPoints = 0;
		std::cout<<"ClapTrap "<<_name<<" took "<<amount<<" points of damage! ";
		std::cout<<"Hit points fall to 0 and died."<<std::endl;
	} else {
		std::cout<<"ClapTrap "<<_name<<" took "<<amount<<" points of damage! ";
		std::cout<<_hitPoints<<" hit points left"<<std::endl;
	}
}
