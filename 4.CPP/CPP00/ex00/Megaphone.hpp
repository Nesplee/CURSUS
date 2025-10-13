/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Megaphone.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 09:12:14 by dinguyen          #+#    #+#             */
/*   Updated: 2025/10/06 09:14:06 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEGAPHONE_HPP
# define MEGAPHONE_HPP

# include <iostream>
# include <string>
# include <cctype>

class	 Megaphone {

public:
	Megaphone();
	~Megaphone();
	std::string	toUpperCase(const std::string &text) const;

};

#endif
