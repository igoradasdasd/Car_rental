/*
 * client.cpp
 *
 *  Created on: 10 мар. 2024 г.
 *      Author: axtea
 */

#include "../include/client.h"

Client::Client(std::string fN, std::string lN): Person(fN, lN),
	car_key(std::string()),
	status(CAR_IS_NOT_RENTAL){}


std::ostream& operator << (std::ostream& os, const Client & rhs)
{
	os << rhs.last_name << std::endl;
	os << rhs.first_name << std::endl;
	os << rhs.car_key << std::endl;
	os << rhs.status << std::endl;
	return os;
}

std::istream& operator >> (std::istream& is, Client& rhs)
{
	int in;
	is >> rhs.last_name;
	is >> rhs.first_name;
	is >> rhs.car_key;
	is >> in;
	rhs.status =  static_cast<CLIENT_STATUS>(in);
	return is;
}
