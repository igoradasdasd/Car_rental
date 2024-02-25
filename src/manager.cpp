/*
 * manager.cpp
 *
 *  Created on: 18 февр. 2024 г.
 *      Author: axtea
 */

#include "../include/manager.h"

size_t Manager::id_count = 0;

Manager::Manager(std::string f_name, std::string l_name, size_t pass):
		Person(f_name, l_name), password(pass)
		{++id_count, id = id_count;};

void Manager::ShowMenu()
{
	int action;
	std::cout << "Select the action: " << std::endl;
	std::cout << "1 - Get a car" << std::endl;
	std::cout << "2 - Give a car" << std::endl;
//	std::
}



