/*
 * data1.h
 *
 *  Created on: 9 мар. 2024 г.
 *      Author: axtea
 */

#ifndef INCLUDE_DATA_H_
#define INCLUDE_DATA_H_

#include <map>
#include <vector>

#include "car.h"
#include "client.h"
#include "manager.h"
#include "senior_manager.h"


//класс, содержащий перечень клиентов и машин
class Data final
{
	friend class Manager;
	friend class Senior_manager;
public:
	Data() = default;
private:
	std::map<std::string, Client> list_of_clients;
	std::map<std::string, Car> list_of_cars;

};





#endif /* INCLUDE_DATA_H_ */
