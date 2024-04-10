/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 13:15:30 by ppotier           #+#    #+#             */
/*   Updated: 2023/11/29 14:34:15 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Serializer.hpp"

/*reinterpret_cast est un opérateur de conversion de type en C++. 
Il est utilisé pour effectuer des conversions de type entre des 
pointeurs ou d'autres types non liés sans changer la représentation 
binaire des données. Contrairement à static_cast, reinterpret_cast 
permet des conversions entre n'importe quel type de pointeur, mais 
cela peut être potentiellement dangereux et peut entraîner un comportement 
indéfini si les types ne sont pas compatibles.*/

int main() {
 
    Data data;
   
    uintptr_t serializedPointer = Serializer::serialize(&data);
    std::cout << "serialized pointer: " << serializedPointer << std::endl;
    std::cout << "------------------" << std::endl;
    Data* deserializedPointer = Serializer::deserialize(serializedPointer);

	if (deserializedPointer == &data) {
    	std::cout << "Original value: " << data.getValue() << std::endl;
    	std::cout << "Deserialized value: " << deserializedPointer->getValue() << std::endl;
	}
	else
		std::cout << "Adress non equal" << std::endl;
    return 0;
}