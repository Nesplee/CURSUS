/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 10:43:00 by dinguyen          #+#    #+#             */
/*   Updated: 2025/11/30 19:53:08 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	const WrongAnimal* k = new WrongCat();

	std::cout<<" ============================== "<<std::endl;
	std::cout<<" TESTS W/ RIGHTANIMALS"<<std::endl;
	std::cout<<" ============================== "<<std::endl;
	std::cout<<j->getType()<< std::endl;
	std::cout<<i->getType()<< std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();
	std::cout<<" ============================== "<<std::endl;
	std::cout<<" TESTS W/ WRONGANIMALS"<<std::endl;
	std::cout<<" ============================== "<<std::endl;
	std::cout<<k->getType()<<" "<<std::endl;
	k->makeSound();
	delete meta;
	delete j;
	delete i;
	delete k;
	return (0);
}
