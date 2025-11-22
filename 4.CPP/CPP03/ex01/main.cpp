/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 12:52:26 by dinguyen          #+#    #+#             */
/*   Updated: 2025/11/22 13:16:16 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main(void)
{
	std::cout << "=== CONSTRUCTION ===" << std::endl;
	ScavTrap guardian("Guardian");
	ScavTrap sentinel("Sentinel");

	std::cout << "\n=== ENERGY EXHAUSTION ===" << std::endl;
	for (int i = 0; i < 51; i++) {
		guardian.attack("Bandit");
	}

	std::cout << "\n=== DAMAGE RESISTANCE ===" << std::endl;
	for (int i = 0; i < 6; i++) {
		sentinel.takeDamage(20);
	}

	std::cout << "\n=== DEAD ACTIONS ===" << std::endl;
	sentinel.attack("Ghost");
	sentinel.beRepaired(50);
	sentinel.guardGate();

	std::cout << "\n=== REPAIR TEST ===" << std::endl;
	ScavTrap medic("Medic");
	medic.takeDamage(30);
	for (int i = 0; i < 3; i++) {
		medic.beRepaired(10);
	}

	std::cout << "\n=== GATE KEEPER MODE ===" << std::endl;
	ScavTrap gatekeeper("Gatekeeper");
	gatekeeper.guardGate();
	gatekeeper.guardGate();
	gatekeeper.guardGate();

	std::cout << "\n=== MIXED COMBAT ===" << std::endl;
	ScavTrap warrior("Warrior");
	warrior.attack("Enemy1");
	warrior.takeDamage(40);
	warrior.beRepaired(20);
	warrior.guardGate();
	warrior.takeDamage(90);
	warrior.attack("Enemy2");
	warrior.guardGate();

	std::cout << "\n=== COPY CONSTRUCTOR ===" << std::endl;
	ScavTrap original("Original");
	original.takeDamage(50);
	original.guardGate();
	ScavTrap copy(original);
	copy.attack("Target");
	copy.guardGate();

	std::cout << "\n=== ASSIGNMENT OPERATOR ===" << std::endl;
	ScavTrap assigned("Temp");
	assigned = original;
	assigned.attack("NewTarget");
	assigned.guardGate();

	std::cout << "\n=== DESTRUCTION ===" << std::endl;
	return 0;
}
