/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 11:53:37 by dinguyen          #+#    #+#             */
/*   Updated: 2025/11/25 15:52:52 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# include <string>

class	Brain {

public:
	Brain();
	Brain(const Brain &other);
	Brain&	operator=(const Brain &other);
	~Brain();

	std::string	getIdea(int index) const;
	void	setIdea(int index, const std::string &idea);

private:
	std::string	_ideas[100];

};

#endif
