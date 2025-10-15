/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 10:51:24 by dinguyen          #+#    #+#             */
/*   Updated: 2025/08/16 10:56:21 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "weapon.hpp"
#include "humanA.hpp"
#include "humanB.hpp"

int	main(void)
{
	Weapon	hache;
	hache.setType("Hache");

	HumanA	hA(hache, "Isaiah");
	hA.attack();
	HumanB	hB("Tom");
	hB.attack();
	Weapon	club;
	club.setType("Club");
	hB.setWeapon(club);
	hB.attack();
	return (0);
}
