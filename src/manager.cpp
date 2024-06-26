/*
 * manager.cpp
 *
 *  Created on: 18 февр. 2024 г.
 *      Author: axtea
 */

#include "../include/manager.h"

size_t Manager::id_count;

void Manager::read_id_count(std::string in)
{
	std::fstream read(in);
	read >> id_count;
}

void Manager::write_id_count(std::string in)
{
	std::fstream write(in);
	write << id_count;
}

		// предустановленный senior_manager должен иметь id 0

Manager::Manager(std::string f_name, std::string l_name, size_t pass, POST in_post):
		Person(f_name, l_name), password(pass), post(in_post)
		{++id_count, id = id_count;};

std::ostream& operator<< (std::ostream& os, const Manager& rhs)
{
	os << rhs.id << std::endl;
	os << rhs.password << std::endl;
	os << rhs.first_name << std::endl;
	os << rhs.last_name  << std::endl;
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
	data.work();
}



