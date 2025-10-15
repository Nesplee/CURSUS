/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 13:17:39 by dinguyen          #+#    #+#             */
/*   Updated: 2025/08/15 17:52:21 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>

class	Zombie
{

public:
	Zombie();
	Zombie(const std::string &name);
	~Zombie();
	void	announce(void) const;
	void	setName(const std::string &name);

private:
	std::string	_name;
};

Zombie*	hordeZombie(int N, const std::string name);

# endif
