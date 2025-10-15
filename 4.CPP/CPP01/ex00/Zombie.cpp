/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 12:23:15 by dinguyen          #+#    #+#             */
/*   Updated: 2025/08/15 13:28:08 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

//	CONSTRUCTEUR && DESTRUCTEUR
Zombie::Zombie(const std::string &name) : _name(name) {
	std::cout<<"Zombie constructor called with name: "<<_name<<std::endl;
}

Zombie::~Zombie() {
	std::cout<<"Zombie destructor called for Zombie: "<<_name<<std::endl;
}

void	Zombie::announce(void) const {
	std::cout<<_name<<": BraiiiiiiinnnzzzZ..."<<std::endl;
}
