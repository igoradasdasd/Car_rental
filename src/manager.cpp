/*
 * manager.cpp
 *
 *  Created on: 18 февр. 2024 г.
 *      Author: axtea
 */

#include "../include/manager.h"

size_t Manager::id_count = 2; 		// предустановленный senior_manager должен иметь id 0

Manager::Manager(std::string f_name, std::string l_name, size_t pass, POST in_post):
		Person(f_name, l_name), password(pass), post(in_post)
		{++id_count, id = id_count;};

std::ostream& operator<< (std::ostream& os, const Manager& rhs)
{
	os << rhs.id << std::endl;
	os << rhs.password << std::endl;
	os << rhs.first_name << std::endl;
	os << rhs.last_name;
	os << static_cast<int>(rhs.post) << std::endl;
	return os;
}

std::istream& operator>> (std::istream& is, Manager& rhs)
{
	int i;
	is >> rhs.id;
	is >> rhs.password;
	is >> rhs.first_name;
	is >> rhs.last_name;
	is >> i;
	rhs.post = static_cast<POST>(i);
	return is;
}

void Manager::action(Data& data)
{
	int action;
	char repeat = 'Y';
	while (repeat == 'Y')
	{
		std::cout << "Select the action: " << std::endl;
		std::cout << "1 - Get a car" << std::endl;
		std::cout << "2 - Give a car" << std::endl;
		std::cin >> action;
		switch(action)
		{
		case 1:
			break;
//			get_car();
		case 2:
			break;
//			give_cat();
		default:
			std::cout << "Error input, enter 'Y' to repeat" ;
			std::cin >> repeat;
			break;
	}
	}
}



