/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 08:54:19 by dinguyen          #+#    #+#             */
/*   Updated: 2025/11/22 14:34:52 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(const std::string &name) : ClapTrap(name) {
	std::cout<<"FragTrap "<<_name<<" constructor called"<<std::endl;
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other) {
	std::cout<<"FragTrap "<<_name<<" copy constructor called"<<std::endl;
}

FragTrap&	FragTrap::operator=(const FragTrap &other) {
	if (this != &other) {
		ClapTrap::operator=(other);
	}
	std::cout<<"FragTrap copy assignment operator called"<<std::endl;
	return (*this);
}

FragTrap::~FragTrap() {
	std::cout<<"FragTrap "<<_name<<" destructor called"<<std::endl;
}

void	FragTrap::attack(const std::string &target) {
	if (_hitPoints <= 0) {
		std::cout<<"I'm dead, I can't attack anything"<<std::endl;
		return ;
	}
	if (_energyPoints > 0) {
		_energyPoints--;
		std::cout<<"FragTrap "<<_name<<" attacks "<<target<<", causing ";
		std::cout<<_attackDamage<<" points of damage!"<<std::endl;
	} else {
		std::cout<<"Not enough energy points to attack!"<<std::endl;
	}
}

void	FragTrap::highFiveGuys(void) {
	if (_hitPoints <= 0) {
		std::cout<<"I'm dead. Can't give high five to anyone"<<std::endl;
		return ;
	} else {
		std::cout<<"FragTrap "<<_name<<" requests high five! "<<std::endl;
		std::cout<<"Do you want to high five "<<_name<<" ? (y/n)"<<std::endl;
		char	choice;
		while (true) {
			std::cin>>choice;
			std::cin.ignore(1000, '\n');
			if (choice == 'y' || choice == 'Y') {
				std::cout<<" HIGHHH FIVE! "<<_name<<" is happy!"<<std::endl;
				break ;
			} else if (choice == 'n' || choice == 'N') {
				std::cout<<"No high five for "<<_name<<"... let's jump from the bridge"<<std::endl;
				break ;
			} else {
				std::cout<<"Invalid choice. "<<_name<<" is confused"<<std::endl;
			}
		}
	}
}
