/*
 * personal.h
 *
 *  Created on: 25 февр. 2024 г.
 *      Author: axtea
 */

#ifndef INCLUDE_PERSONAL_H_
#define INCLUDE_PERSONAL_H_

#include <map>

#include "car.h"
#include "client.h"
#include "../include/Manager.h"
#include "../include/Senior_Manager.h"

class Personal
{
public:
	Manager* search_by_id(size_t in_id);

private:
	std::map<size_t, Manager> list_of_Manager;
	std::map<size_t, Senior_manager> list_of_Senior_Manager;
};




#endif /* INCLUDE_PERSONAL_H_ */