/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 17:40:32 by dinguyen          #+#    #+#             */
/*   Updated: 2025/10/13 19:04:15 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie*	horde = hordeZombie(5, "Walker");
	for (int i = 0; i < 5; i++) {
		std::cout<<"Zombie "<<i<<std::endl;
		horde[i].announce();
	}
	delete[] horde;
	return (0);
}
