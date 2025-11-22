/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 09:42:21 by dinguyen          #+#    #+#             */
/*   Updated: 2025/11/22 16:21:01 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"


int main(void)
{
	std::cout << "=== CONSTRUCTION ===" << std::endl;
	DiamondTrap diamond("Warrior");
	std::cout << "\n=== DIAMONDTRAP TESTS ===" << std::endl;
	diamond.attack("Enemy");
	diamond.takeDamage(40);
	diamond.beRepaired(20);
	diamond.whoAmI();
	std::cout << "\n=== SPECIAL ABILITIES ===" << std::endl;
	diamond.guardGate();
	diamond.highFiveGuys();
	std::cout << "\n=== ENERGY TEST ===" << std::endl;
	for (int i = 0; i < 52; i++) {
		if (i >= 49) std::cout << "Attack " << (i+1) << ": ";
		diamond.attack("Target");
	}
	std::cout << "\n=== COPY TEST ===" << std::endl;
	DiamondTrap original("Hero");
	original.takeDamage(30);
	original.whoAmI();
	DiamondTrap copy(original);
	copy.whoAmI();
	std::cout << "\n=== ASSIGNMENT TEST ===" << std::endl;
	DiamondTrap assigned("Temp");
	assigned = original;
	assigned.whoAmI();
	std::cout << "\n=== DESTRUCTION ===" << std::endl;
	return 0;
}
