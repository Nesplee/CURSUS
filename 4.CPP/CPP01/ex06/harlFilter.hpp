/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   harlFilter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 10:14:46 by dinguyen          #+#    #+#             */
/*   Updated: 2025/08/18 10:21:07 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARLFILTER_HPP
# define HARLFILTER_HPP

# include <iostream>
# include <string>

class	HarlFilter
{

public:
	HarlFilter();
	~HarlFilter();

	void	complain(std::string level) const;
	void	filter(std::string level);

private:
	void	_debug(void) const;
	void	_info(void) const;
	void	_warning(void) const;
	void	_error(void) const;
	int		_getLevelIndex(std::string level) const;
};


#endif
