/*
 * data.cpp
 *
 *  Created on: 25 февр. 2024 г.
 *      Author: axtea
 */

#include "../include/personal.h"

template
void Data::read_from_file(std::string clients_f, std::map<std::string, Client> list);


template
void Data::read_from_file(std::string clients_f, std::map<std::string, Car> list);

void Data::read_data(std::string file, std::string car_f)
{
	read_from_file(file, list_of_clients);
	read_from_file(file, list_of_cars);
}

/*
void Data::read_clients_from_file(std::string clients_f)
{

}
*/


