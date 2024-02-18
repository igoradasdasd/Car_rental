/*
 * data.h
 *
 *  Created on: 18 февр. 2024 г.
 *      Author: axtea
 */

#ifndef INCLUDE_DATA_H_
#define INCLUDE_DATA_H_

#include <map>
#include "car.h"
#include "client.h"

class Manager;
class Senior_Manager;
//класс, содержащий перечень клиентов и машин
class Data
{
	friend Manager;
	friend Senior_Manager;

	std::map<std::string, Client> list_of_clients;
	std::map<std::string, Car> list_of_cars;

};






#endif /* INCLUDE_DATA_H_ */
