/*
 * Senior_manager.cpp
 *
 *  Created on: 18 февр. 2024 г.
 *      Author: axtea
 */
#include "../include/senior_manager.h"

/*
Senior_manager::Senior_manager(std::string f_name, std::string l_name, size_t pass):
	Manager(f_name,  l_name,  pass){};

*/

Senior_manager::Senior_manager(std::string f_name, std::string l_name, size_t pass):
	Manager(f_name,  l_name, pass, SENIOR_MANAGER){};

void Senior_manager::action(Data& data)
{
	char repeat = 'Y';
	int p;
	std::cout << "Select action: 0 - give or get a car, 1 - edit list of cars or clients,";
	std::cin >> p;
	while ('Y' == repeat)
	{
		switch(p)
		{
		case 0:
			data.work();
			break;
		case 1:
			data.edit_data();	// редактирование списка машин и клиентов
			break;
		default:
			std::cout << "Error input" << std::endl;
			break;
		}
		std::cout << "Enter 'Y' to continue senior manager session" ;
		std::cin >> repeat;
	}
}

