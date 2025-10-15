/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 09:42:21 by dinguyen          #+#    #+#             */
/*   Updated: 2025/09/04 09:52:47 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"
#include <iostream>
#include <string>

int	main(void)
{
	std::cout<<std::endl;
	std::cout<<" ===== TESTS CONSTRUCTORS ====="<<std::endl;
	ClapTrap	clap("Clapie");
	ScavTrap	scav("Scavie");
	FragTrap	frag("Fragie");
	DiamondTrap	diamond("Diamie");
	std::cout<<std::endl;
	std::cout<<" ===== TESTS INITIALS VALUES ====="<<std::endl;
	std::cout << "DiamondTrap " << "Diamie" << " stats:" << std::endl;
	std::cout << "Points de vie    : 100 (FragTrap)" << std::endl;
	std::cout << "Points d'énergie : 50 (ScavTrap)" << std::endl;
	std::cout << "Dégâts d'attaque : 30 (FragTrap)" << std::endl;
	std::cout<<std::endl;
	std::cout<<" ===== TESTS ATTACKS ====="<<std::endl;
	clap.attack("Target");
	scav.attack("Target");
	frag.attack("Target");
	diamond.attack("Target");
	std::cout<<std::endl;
	std::cout<<" ===== TESTS SPECIAL ABILITIES ====="<<std::endl;
	scav.guardGate();
	frag.highFivesGuys();
	diamond.whoAmI();
	diamond.guardGate();
	diamond.highFivesGuys();
	std::cout<<std::endl;
	std::cout<<" ===== TESTS DAMAGES ====="<<std::endl;
	clap.takeDamage(5);
	scav.takeDamage(15);
	frag.takeDamage(25);
	diamond.takeDamage(35);
	std::cout<<std::endl;
	std::cout<<" ===== TESTS REPAIRS ====="<<std::endl;
	clap.beRepaired(3);
	scav.beRepaired(10);
	frag.beRepaired(20);
	diamond.beRepaired(30);
	std::cout<<std::endl;
	std::cout << "===== TESTS LIMITS =====" << std::endl;
	for (int i = 0; i < 10; i++) {
		diamond.attack("Target");
		clap.takeDamage(2);
	}
	return (0);
}
