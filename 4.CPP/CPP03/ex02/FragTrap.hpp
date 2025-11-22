/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 08:52:40 by dinguyen          #+#    #+#             */
/*   Updated: 2025/11/22 13:49:44 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class	FragTrap : public ClapTrap {

public:
	FragTrap(const std::string &name);
	FragTrap(const FragTrap &other);
	FragTrap&	operator=(const FragTrap &other);
	~FragTrap();

	void	attack(const std::string &target);
	void	highFiveGuys(void);

private:

};

#endif
