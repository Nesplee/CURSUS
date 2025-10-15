/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fileReplacer.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 17:03:19 by dinguyen          #+#    #+#             */
/*   Updated: 2025/08/16 17:36:25 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILEREPLACER_HPP
# define FILEREPLACER_HPP

# include <iostream>
# include <string>
# include <fstream>


class	FileReplacer
{

public:
	FileReplacer(const std::string filename, const std::string s1, const std::string s2);
	~FileReplacer();
	bool	processFile();

private:
	const std::string	_filename;
	std::string			_s1;
	std::string			_s2;
	bool				_openFiles(std::ifstream& infile, std::ofstream& outfile);
	std::string			_readAllContent(std::ifstream& infile);
	std::string			_replaceInText(const std::string& content);

};

#endif
