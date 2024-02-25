/*
 * person.h
 *
 *  Created on: 25 февр. 2024 г.
 *      Author: axtea
 */

#include "../include/Person.h"


std::pair<std::string, std::string>
Person::get_name() const
{
	return std::make_pair(last_name, first_name);
}
