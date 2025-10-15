/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 12:17:05 by dinguyen          #+#    #+#             */
/*   Updated: 2025/09/01 12:27:45 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

int main(void)
{
	std::cout<<"\n === TEST CONSTRUCTEUR ==="<<std::endl;
	ClapTrap	robot("Pikachu");
	ClapTrap	robot2("Charizard");
	ClapTrap	robot3("Blastoise");

	std::cout<<"\n === TEST ATTACK ==="<<std::endl;
	robot.attack("Charizard");
	robot2.takeDamage(5);
	robot2.attack("Pikachu");
	robot.takeDamage(2);
	robot3.attack("Pikachu");
	robot.takeDamage(3);
	robot.attack("Charizard");
	robot2.takeDamage(30);
	robot.attack("Blastoise");
	robot3.takeDamage(30);
	robot.beRepaired(150);
	robot2.attack("Pikachu");
	robot3.attack("Pikachu");
	return (0);
}
