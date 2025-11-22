/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 12:17:05 by dinguyen          #+#    #+#             */
/*   Updated: 2025/11/19 19:29:19 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>
#include <string>

int main(void)
{
	ClapTrap	clap("Clapie");
	for (int i = 0; i < 11; i++) {
		clap.attack("Joe");
	}
	ClapTrap	clop("Clopie");
	for (int i = 0; i< 11; i++) {
		clop.takeDamage(2);
	}
	clop.beRepaired(30);
	for (int i = 0; i < 11; i++) {
		clop.attack("Clapie");
	}
	return (0);
}
