/*
 * client.cpp
 *
 *  Created on: 10 мар. 2024 г.
 *      Author: axtea
 */

#include "../include/client.h"

Client::Client(std::string lN, std::string fN):
	lastName(lN), firstName(fN), car_key(std::string()),
	status(CAR_IS_NOT_RENTAL){}


std::ostream& operator << (std::ostream& os, Client & rhs)
{
	os << rhs.lastName;
	os << rhs.firstName;
	os << rhs.car_key;
	os << rhs.status;
	return os;
}

std::istream& operator >> (std::istream& is, Client& rhs)
{
	int in;
	is >> rhs.lastName;
	is >> rhs.firstName;
	is >> rhs.car_key;
	is >> in;
	rhs.status =  static_cast<CLIENT_STATUS>(in);
	return is;
}
