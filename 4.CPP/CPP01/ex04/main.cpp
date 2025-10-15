/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 17:35:42 by dinguyen          #+#    #+#             */
/*   Updated: 2025/08/16 17:35:53 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fileReplacer.hpp"

int	main(int argc, char* argv[])
{
	if (argc != 4) {
		std::cout<<"Usage: "<<argv[0]<<" <filename> <s1> <s2>"<<std::endl;
		return (1);
	}
	std::string	filename = argv[1];
	std::string	s1       = argv[2];
	std::string	s2       = argv[3];
	if (filename.empty() || s1.empty()) {
		std::cout<<"Error: filename and s1 cannot be empty"<<std::endl;
		return (1);
	}
	FileReplacer	replacer(filename, s1, s2);
	if (replacer.processFile()) {
		std::cout<<"File processed successfully!"<<std::endl;
		return (0);
	} else {
		std::cout<<"Failed to process file"<<std::endl;
		return (1);
	}
}
