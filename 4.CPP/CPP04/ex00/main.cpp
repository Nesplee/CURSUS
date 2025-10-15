/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 13:57:43 by dinguyen          #+#    #+#             */
/*   Updated: 2025/09/04 13:58:40 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	const WrongAnimal* wrong = new WrongCat();
	std::cout << "\n=== TYPE TESTS ===" << std::endl;
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	std::cout << wrong->getType() << " " << std::endl;
	std::cout << "\n=== SOUND TESTS ===" << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();
	wrong->makeSound();
	std::cout << "\n=== CLEANUP ===" << std::endl;
	delete meta;
	delete j;
	delete i;
	delete wrong;
	return (0);
}
