/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 10:43:00 by dinguyen          #+#    #+#             */
/*   Updated: 2025/11/30 20:03:23 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"

int	main(void) {
	const int	size = 10;
	Animal*	animals[size];
	std::cout<<" ====================================================== "<<std::endl;
	std::cout<<"          CONSTRUCTION OF AN ARRAY OF ANIMALS"<<std::endl;
	std::cout<<" ====================================================== "<<std::endl;
	for (int i = 0; i < size / 2; i++)
		animals[i] = new Dog();
	for (int i = size / 2; i < size; i++)
		animals[i] = new Cat();
	std::cout<<" ====================================================== "<<std::endl;
	std::cout<<"          SOUND TEST OF THE ARRAY"<<std::endl;
	std::cout<<" ====================================================== "<<std::endl;
	for (int i = 0; i < size; i++)
		animals[i]->makeSound();
	std::cout<<" ====================================================== "<<std::endl;
	std::cout<<"                     TEST OF THE DOG DEEP COPY "<<std::endl;
	std::cout<<" ====================================================== "<<std::endl;
	Dog	originalDog;
	originalDog.setIdea(0, "Chase the cat");
	Dog	copyDog(originalDog);
	Dog	copyDog2;
	copyDog.setIdea(2, "Eat that same cat");
	copyDog2 = copyDog;
	std::cout<<std::endl;
	std::cout<<"Original Dog Idea : "<<originalDog.getIdea(0)<<std::endl;
	std::cout<<"Copy Dog 1 Idea 1 : "<<copyDog.getIdea(0)<<std::endl;
	std::cout<<"Copy Dog 1 Idea 3 : "<<copyDog.getIdea(2)<<std::endl;
	std::cout<<"Copy Dog 2 Idea 1 : "<<copyDog2.getIdea(0)<<std::endl;
	std::cout<<"Copy Dog 2 Idea 3 : "<<copyDog2.getIdea(2)<<std::endl;
	std::cout<<"Original Dog Idea 3 : "<<originalDog.getIdea(2)<<std::endl;
	std::cout<<" ====================================================== "<<std::endl;
	std::cout<<"                     TEST OF THE CAT DEEP COPY "<<std::endl;
	std::cout<<" ====================================================== "<<std::endl;
	Cat	originalCat;
	originalCat.setIdea(0, "Dodge the dog");
	Cat	copyCat(originalCat);
	copyCat.setIdea(2, "Be eaten by the same dog");
	Cat	copyCat2 = copyCat;
	copyCat2.setIdea(3, "DEAddaSD");
	for (int i = 0; i < 4; i++) {
		std::string	result;
		std::cout<<" IDEA NUMBER "<<i<<std::endl;
		result = originalCat.getIdea(i);
		std::cout<<result<<std::endl;
		result = copyCat.getIdea(i);
		std::cout<<result<<std::endl;
		result = copyCat2.getIdea(i);
		std::cout<<result<<std::endl;
	}
	std::cout<<" ====================================================== "<<std::endl;
	std::cout<<"              DESTRUCTION OF THE ARRAY "<<std::endl;
	std::cout<<" ====================================================== "<<std::endl;
	for (int i = 0; i < size; i++) {
		delete animals[i];
	}
	std::cout<<"MeowWooffFBrainzsZ"<<std::endl;
	std::cout<<"auto-deletion of the animals created ...."<<std::endl;
	return(0);
}
