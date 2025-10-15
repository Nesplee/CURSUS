/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Megaphone.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 13:42:38 by dinguyen          #+#    #+#             */
/*   Updated: 2025/10/13 13:47:05 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEGAPHONE_HPP
# define MEGAPHONE_HPP

# include <iostream>
# include <string>
# include <cctype>

class	Megaphone {

private:

public:
	Megaphone();
	~Megaphone();
	std::string	toUpperCase(const std::string &text);
};

#endif
