/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fileReplacer.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 17:05:00 by dinguyen          #+#    #+#             */
/*   Updated: 2025/08/16 17:33:52 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fileReplacer.hpp"

//	CONSTRUCTOR & DESTRUCTOR

FileReplacer::FileReplacer(const std::string filename, const std::string s1, const std::string s2) :
	_filename(filename), _s1(s1), _s2(s2) {
	std::cout<<"FileReplacer constructor called"<<std::endl;
}

FileReplacer::~FileReplacer() {
	std::cout<<"FileReplacer destructor called"<<std::endl;
}

//	PRIVATES METHODS
bool	FileReplacer::_openFiles(std::ifstream& infile, std::ofstream& outfile)
{
	infile.open(_filename.c_str());
	if (!infile.is_open())
	{
		std::cout<<"Error: file not fount"<<std::endl;
		return (false);
	}
	std::string	outname = _filename + ".replace";
	outfile.open(outname.c_str());
	if (!outfile.is_open())
	{
		std::cout<<"Error: couldn't create file"<<std::endl;
		infile.close();
		return (false);
	}
	return (true);
}

std::string	FileReplacer::_readAllContent(std::ifstream& infile)
{
	std::string	allContent = "";
	std::string	line;
	while (std::getline(infile, line))
		allContent = allContent + line + "\n";
	return (allContent);
}

std::string	FileReplacer::_replaceInText(const std::string& content)
{
	std::string	result;
	size_t		i = 0;

	while (i < content.length())
	{
		if (content.substr(i, _s1.length()) == _s1)
		{
			result = result + _s2;
			i = i + _s1.length();
		} else {
			result = result + content[i];
			i++;
		}
	}
	return (result);
}

//	PUBLIC METHOD
bool	FileReplacer::processFile()
{
	std::ifstream	infile;
	std::ofstream	outfile;

	if (!_openFiles(infile, outfile)) { return (false); }
	std::string		content = _readAllContent(infile);
	std::string		newContent = _replaceInText(content);
	outfile<<newContent;
	infile.close();
	outfile.close();
	return (true);
}
