/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 09:14:30 by dinguyen          #+#    #+#             */
/*   Updated: 2025/09/04 09:15:30 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>
#include <string>

int	main(void)
{
	std::cout<<std::endl;
	std::cout<<" ===== TESTS CONSTRUCTORS ====="<<std::endl;
	ClapTrap	clap("Clapie");
	FragTrap	frag("Fragie");
	std::cout<<std::endl;
	std::cout<<" ===== TESTS ATTACKS ====="<<std::endl;
	clap.attack("Fragie");
	frag.takeDamage(5);
	frag.attack("Clapie");
	clap.takeDamage(9);
	std::cout<<std::endl;
	std::cout<<" ===== TESTS HIGH FIVES ====="<<std::endl;
	frag.highFivesGuys();
	std::cout<<std::endl;
	std::cout<<" ===== TESTS REPAIRS ====="<<std::endl;
	clap.beRepaired(15);
	frag.beRepaired(20);
	std::cout<<std::endl;
	std::cout << "=== TESTS LIMITS ===" << std::endl;
	for (int i = 0; i < 10; i++) {
		frag.attack("Target");
		clap.takeDamage(2);
	}
	return (0);
}
