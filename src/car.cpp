/*
 * car.cpp
 *
 *  Created on: 10 мар. 2024 г.
 *      Author: axtea
 */
#include "../include/car.h"

Car::Car(string mod, string num, int mil, double cost_of_km, double cost_of_d, CAR_STATUS c_s ):
	model(mod), number(num), cost_of_kilometer(cost_of_km), cost_of_day(cost_of_d),  mileage(mil),
	status(c_s) {}

std::ostream & operator << (std::ostream & os, Car rhs)
{
	os << rhs.model << std::endl;
	os << rhs.number << std::endl;
	os << rhs.client_key << std::endl;
	os << rhs.cost_of_kilometer << std::endl;
	os << rhs.cost_of_day << std::endl;
	os << rhs.mileage << std::endl;
	os << static_cast<int>(rhs.status) << std::endl;
	os << rhs.time << std::endl;
	return os;
}


std::istream & operator >> (std::istream & is, Car rhs)
{
	int in;
	is >> rhs.model;
	is >> rhs.number;
	is >> rhs.client_key;
	is >> rhs.cost_of_kilometer;
	is >> rhs.cost_of_day;
	is >> rhs.mileage;
	is >> in;
	rhs.status = static_cast<CAR_STATUS>(in);
	is >> rhs.time;
	return is;
}
