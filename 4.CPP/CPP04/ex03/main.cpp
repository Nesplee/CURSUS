/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 14:18:59 by dinguyen          #+#    #+#             */
/*   Updated: 2025/11/30 20:56:27 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "MateriaSource.hpp"
#include <iostream>

void	printInventory(const Character& c) {
	std::cout<<"Inventory of "<<c.getName()<<" : ";
	for (int i = 0; i < 4; i++) {
		AMateria*	item = c.getInventoryItem(i);
		if (item)
			std::cout<<item->getType()<<" / ";
		else
			std::cout<<"empty /";
	}
	std::cout<<std::endl;
}

bool isEquipped(const Character& c, AMateria* m) {
	for (int i = 0; i < 4; ++i)
		if (c.getInventoryItem(i) == m)
			return true;
	return false;
}

int	main(void) {

	std::cout<<" ==================================================== "<<std::endl;
	std::cout<<"                     CONSTRUCTION "<<std::endl;
	std::cout<<" ==================================================== "<<std::endl;
	Ice ice1;
	Ice ice2(ice1);
	Ice ice3;
	std::cout<<std::endl;
	ice3 = ice1;
	Cure cure1;
	Cure cure2(cure1);
	Cure cure3;
	cure3 = cure1;
	std::cout<<std::endl;
	Character char1("Yooou");
	Character char2(char1);
	Character char3;
	char3 = char1;
	std::cout<<std::endl;
	MateriaSource src1;
	MateriaSource src2(src1);
	MateriaSource src3;
	src3 = src1;
	std::cout<<std::endl;
	std::cout<<" ==================================================== "<<std::endl;
	std::cout<<"            LEARN & CREATE MATERIAS "<<std::endl;
	std::cout<<" ==================================================== "<<std::endl;
	for (int i = 0; i < 5; i++) {
		if (i % 2 == 0)
			src1.learnMateria(new Ice());
		else
			src1.learnMateria(new Cure());
	}
	AMateria* m1 = src1.createMateria("ice");
	AMateria* m2 = src1.createMateria("cure");
	AMateria* m3 = src1.createMateria("unknown");
	std::cout<<"m1 type: ";
	if (m1)
		std::cout<<m1->getType()<<std::endl;
	else
		std::cout<<"null"<<std::endl;
	std::cout<<"m2 type: ";
	if (m2)
		std::cout<<m2->getType()<<std::endl;
	else
		std::cout<<"null"<<std::endl;
	std::cout<<"m3 type: ";
	if (m3)
		std::cout<<m3->getType()<<std::endl;
	else
		std::cout<<"null"<<std::endl;
	std::cout<<" ==================================================== "<<std::endl;
	std::cout<<"             TEST INVENTORY LIMITS "<<std::endl;
	std::cout<<" ==================================================== "<<std::endl;
	Character bob("Bob");
	bob.equip(m1);
	bob.equip(m2);
	AMateria* tmp1 = new Ice();
	bob.equip(tmp1);
	AMateria* tmp2 = new Cure();
	bob.equip(tmp2);
	AMateria* tmp3 = new Ice();
	bob.equip(tmp3);
	printInventory(bob);
	std::cout<<" ==================================================== "<<std::endl;
	std::cout<<"             TEST USE AND UNEQUIP "<<std::endl;
	std::cout<<" ==================================================== "<<std::endl;
	Character alice("Alice");
	AMateria* tmpIce = new Ice();
	AMateria* tmpCure = new Cure();
	AMateria* tmpIce2 = new Ice();
	AMateria* tmpCure2 = new Cure();
	alice.equip(tmpIce);
	alice.equip(tmpCure);
	alice.equip(tmpIce2);
	alice.equip(tmpCure2);
	AMateria* tmpExtra = new Ice();
	alice.equip(tmpExtra);
	printInventory(alice);
	alice.unequip(1);
	printInventory(alice);
	alice.unequip(1);
	alice.use(1, alice);
	alice.equip(tmpCure);
	printInventory(alice);
	alice.unequip(-1);
	alice.unequip(4);
	alice.equip(0);
	alice.use(-1, alice);
	alice.use(4, alice);
	std::cout<<" ==================================================== "<<std::endl;
	std::cout<<"             TEST DEEP COPY "<<std::endl;
	std::cout<<" ==================================================== "<<std::endl;
	Character clone(alice);
	printInventory(clone);
	AMateria* tmp6 = new Ice();
	clone.equip(tmp6);
	printInventory(clone);
	printInventory(alice);
	std::cout<<" ==================================================== "<<std::endl;
	std::cout<<"             TEST DESTRUCTION "<<std::endl;
	std::cout<<" ==================================================== "<<std::endl;
	if (m3)
		delete m3;
	return (0);
}

