/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 12:21:53 by dinguyen          #+#    #+#             */
/*   Updated: 2025/08/15 13:28:27 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>
# include <cctype>

class	Zombie
{
public:
	Zombie(const std::string &name);
	~Zombie();
	void	announce(void) const;
private:
	std::string	_name;
};

void	randomChump(std::string name);
Zombie*	newZombie(std::string name);

#endif
