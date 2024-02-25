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
#include "../include/Manager.h"
#include "../include/Senior_Manager.h"

//класс, содержащий перечень клиентов и машин
class Data
{
	friend Manager;
	friend Senior_manager;

	std::map<std::string, Client> list_of_clients;
	std::map<std::string, Car> list_of_cars;
};






#endif /* INCLUDE_DATA_H_ */
