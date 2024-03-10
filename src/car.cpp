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



