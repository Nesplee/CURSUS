/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 12:45:16 by dinguyen          #+#    #+#             */
/*   Updated: 2025/10/13 19:06:44 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	std::cout<<"=== randomChump (Stack) ==="<<std::endl;
	randomChump("Stackie");
	std::cout<<"Stackie est détruit automatiquement"<<std::endl;
	std::cout<<"=== newZombie (Heap) ==="<<std::endl;
	Zombie*	zombie = newZombie("Heapie");
	zombie->announce();
	std::cout<<"Heapie existe encore ici! ==> Appel de delete"<<std::endl;
	delete zombie;
	std::cout<<"\n=== Fin du programme ==="<<std::endl;
	return (0);
}
