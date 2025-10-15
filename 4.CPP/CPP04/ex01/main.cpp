/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 13:57:43 by dinguyen          #+#    #+#             */
/*   Updated: 2025/09/07 21:44:16 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	const int arraySize = 4;
	Animal* animals[arraySize];
	for(int i = 0; i < arraySize/2; i++)
		animals[i] = new Dog();
	for(int i = arraySize/2; i < arraySize; i++)
		animals[i] = new Cat();
	Dog originalDog;
	Dog copyDog = originalDog;
	delete j;
	delete i;
	for(int i = 0; i < arraySize; i++)
		delete animals[i];
	return 0;
}
