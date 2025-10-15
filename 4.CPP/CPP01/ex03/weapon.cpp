/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 10:14:41 by dinguyen          #+#    #+#             */
/*   Updated: 2025/10/14 14:04:47 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "weapon.hpp"

Weapon::Weapon() {
	std::cout<<"Weapon constructor called"<<std::endl;
}

Weapon::~Weapon() {
	std::cout<<"Weapon destructor called"<<std::endl;
}

const std::string&	Weapon::getType() const { return (_type); }

void	Weapon::setType(const std::string &type) { _type = type; }
