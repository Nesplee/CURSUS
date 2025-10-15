/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hordeZombie.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 13:29:00 by dinguyen          #+#    #+#             */
/*   Updated: 2025/10/13 19:05:18 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	hordeZombie(int N, const std::string name)
{
	Zombie*	horde = new Zombie[N];
	for (int i = 0; i < N; i++) {
		horde[i].setName(name);
	}
	return (horde);
}
