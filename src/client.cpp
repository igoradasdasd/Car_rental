/*
 * client.cpp
 *
 *  Created on: 10 мар. 2024 г.
 *      Author: axtea
 */

#include "../include/client.h"

Client::Client(std::string lN, std::string fN, tm d_o_b, std::string c_key):
	lastName(lN), firstName(fN), date_of_birthday(d_o_b), car_key(c_key),
	status(CAR_IS_NOT_RENTAL){}


