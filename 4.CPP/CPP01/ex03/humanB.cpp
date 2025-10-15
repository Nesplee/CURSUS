/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   humanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 10:36:13 by dinguyen          #+#    #+#             */
/*   Updated: 2025/08/16 10:59:39 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "humanB.hpp"

HumanB::HumanB(const std::string &name) : _weaponType(0), _name(name) {
	std::cout<<"HumanB constructor called"<<std::endl;
}

HumanB::~HumanB() {
	std::cout<<"HumanB destructor called"<<std::endl;
}

void	HumanB::attack(void) const {
	if (_weaponType != 0) {
		std::cout<<_name;
		std::cout<<" attacks with their ";
		std::cout<<_weaponType->getType()<<std::endl;
	} else {
		std::cout<<_name;
		std::cout<<" has no weapon!"<<std::endl;
	}
}

void	HumanB::setWeapon(Weapon& weaponType) { _weaponType = &weaponType; }
