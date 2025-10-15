/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   humanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 10:20:41 by dinguyen          #+#    #+#             */
/*   Updated: 2025/08/16 10:36:01 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "humanA.hpp"

HumanA::HumanA(Weapon &weaponType, const std::string &name) : _weaponType(weaponType), _name(name) {
	std::cout<<"HumanA constructor called"<<std::endl;
}

HumanA::~HumanA() {
	std::cout<<"HumanA destructor called"<<std::endl;
}

void	HumanA::attack(void) {
	std::cout<<_name;
	std::cout<<" attacks with their ";
	std::cout<<_weaponType.getType();
	std::cout<<std::endl;

}
