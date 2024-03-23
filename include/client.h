/*
 * client.h
 *
 *  Created on: 11 февр. 2024 г.
 *      Author: axtea
 */

#ifndef CLIENT_H_
#define CLIENT_H_

#include <ctime>
#include <iostream>

#include "person.h"
#include "general_data.h"

class Client final: public Person
{
	friend std::ostream& operator << (std::ostream&, Client & rhs);
	friend std::istream& operator >> (std::istream&, Client & rhs);
public:
	~Client() = default;
	Client() = default;
	Client(std::string lN, std::string fN);
	std::string get_key(){return lastName + " " + firstName;}
protected:
	std::string lastName;
	std::string firstName;
	std::string car_key;		// id(ключ в map) выданной машины
	CLIENT_STATUS status;		// статус клиента
};


std::ostream& operator << (std::ostream&, Client & rhs);
std::istream& operator >> (std::istream&, Client & rhs);



#endif /* CLIENT_H_ */
