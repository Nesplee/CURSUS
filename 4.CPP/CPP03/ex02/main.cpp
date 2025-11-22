/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 09:14:30 by dinguyen          #+#    #+#             */
/*   Updated: 2025/11/22 14:38:03 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"


int main(void)
{
	std::cout << "=== CONSTRUCTION ===" << std::endl;
	FragTrap robot("Robot");
	std::cout << "\n=== BASIC TESTS ===" << std::endl;
	robot.attack("Enemy");
	robot.takeDamage(30);
	robot.beRepaired(20);
	std::cout << "\n=== ENERGY EXHAUSTION ===" << std::endl;
	for (int i = 0; i < 101; i++) {
		if (i >= 99) std::cout << "Attack " << (i+1) << ": ";
		robot.attack("Target");
	}
	std::cout << "\n=== DEATH TEST ===" << std::endl;
	robot.takeDamage(200);
	robot.attack("Ghost");
	robot.highFiveGuys();
	std::cout << "\n=== COPY TEST ===" << std::endl;
	FragTrap original("Original");
	FragTrap copy(original);
	copy.attack("Test");
	FragTrap	frag("Fraggie");
	std::cout << "\n=== HIGH FIVE TEST ===" << std::endl;
	frag.highFiveGuys();
	std::cout << "\n=== DESTRUCTION ===" << std::endl;
	return 0;
}
