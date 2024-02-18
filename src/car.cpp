/*
 * car.cpp
 *
 *  Created on: 18 февр. 2024 г.
 *      Author: axtea
 */

#include "../include/car.h"

Car::Car(std::string mod, int mil, double cost_of_kilom, double cost_of_d):
		model(mod), mileage(mil), cost_of_kilometer(cost_of_kilom),
		cost_of_day(cost_of_d), status(FREE){}


