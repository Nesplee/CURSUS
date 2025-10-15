/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 13:19:08 by dinguyen          #+#    #+#             */
/*   Updated: 2025/08/15 17:53:19 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie() {}
Zombie::Zombie(const std::string &name) : _name(name) {
	std::cout<<"Zombie constructor called with name: "<<_name<<std::endl;
}

Zombie::~Zombie() {
	std::cout<<"Zombie destructor called for Zombie: "<<_name<<std::endl;
}

void	Zombie::announce(void) const {
	std::cout<<_name<<": BraiiiiiiinnnzzzZ..."<<std::endl;
}

void	Zombie::setName(const std::string &name) { _name = name; }
