/*
 * client.h
 *
 *  Created on: 11 февр. 2024 г.
 *      Author: axtea
 */

#ifndef CLIENT_H_
#define CLIENT_H_

#include <ctime>

#include "person.h"
#include "general_data.h"

class Client: public Person
{
public:
	~Client() = default;

protected:
	std::string lastName;
	std::string firstName;
	tm date_of_birthday;
	std::string car_key;		// id(ключ в map) выданной машины
	CLIENT_STATUS status;		// статус клиента
};




#endif /* CLIENT_H_ */
