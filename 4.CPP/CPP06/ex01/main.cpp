/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 20:13:42 by dinguyen          #+#    #+#             */
/*   Updated: 2025/12/02 20:29:35 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"
#include "Serializer.hpp"

int main() {
	Data data;
	data.value = 42;
	data.name = "Hello serialization!";
	std::cout<<"Adresse originale : "<<&data<<std::endl;
	uintptr_t raw = Serializer::serialize(&data);
	Data* ptr = Serializer::deserialize(raw);
	std::cout<<"Adresse après conversion : "<<ptr<<std::endl;
	if (ptr == &data)
		std::cout<<"Conversion OK !"<<std::endl;
	else
		std::cout<<"Erreur de conversion !"<<std::endl;
	std::cout<<"Valeur : "<<ptr->value<<std::endl;
	std::cout<<"Nom    : "<<ptr->name<<std::endl;
	return (0);
}
