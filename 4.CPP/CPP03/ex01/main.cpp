/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 14:55:13 by dinguyen          #+#    #+#             */
/*   Updated: 2025/09/03 15:46:12 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>
#include <string>

int	main(void)
{
	std::cout<<std::endl;
	std::cout<<" ===== TESTS CONSTRUCTORS ====="<<std::endl;
	ClapTrap	clap("Clapie");
	ScavTrap	scav("Scavie");
	std::cout<<std::endl;
	std::cout<<" ===== TESTS ATTACKS ====="<<std::endl;
	clap.attack("Scavie");
	scav.takeDamage(5);
	scav.attack("Clapie");
	clap.takeDamage(9);
	std::cout<<std::endl;
	std::cout<<" ===== TESTS GUARDGATE ====="<<std::endl;
	scav.guardGate();
	std::cout<<std::endl;
	std::cout<<" ===== TESTS REPAIRS ====="<<std::endl;
	clap.beRepaired(15);
	scav.beRepaired(20);
	std::cout<<std::endl;
	std::cout << "=== TESTS LIMITS ===" << std::endl;
	for (int i = 0; i < 10; i++) {
		scav.attack("Target");
		clap.takeDamage(2);
	}
	return (0);
}
