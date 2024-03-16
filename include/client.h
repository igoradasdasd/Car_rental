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

class Client final: public Person
{
public:
	~Client() = default;
	Client() = default;
	Client(std::string lN, std::string fN, tm d_o_b, std::string c_key);
protected:
	std::string lastName;
	std::string firstName;
	tm date_of_birthday;
	std::string car_key;		// id(ключ в map) выданной машины
	CLIENT_STATUS status;		// статус клиента
};




#endif /* CLIENT_H_ */
