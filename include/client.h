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
	friend std::ostream& operator << (std::ostream&, const Client & rhs);
	friend std::istream& operator >> (std::istream&, Client & rhs);
public:
	~Client() = default;
	Client() = default;
	Client(std::string fN, std::string lN);
	std::string get_key(){return first_name + "_" + last_name;}
	void set_car_key(const std::string & in) {}
	void clear_car_key() { car_key = std::string("0");}
	std::string give_car_key(){return car_key;}
	void set_status(const CLIENT_STATUS& in_status){ status = in_status;}
	bool check_status();
protected:
//	std::string lastName;
//	std::string firstName;
	std::string car_key;		// id(ключ в map) выданной машины
	CLIENT_STATUS status;		// статус клиента
};

std::ostream& operator << (std::ostream&, const Client & rhs);
std::istream& operator >> (std::istream&, Client & rhs);



#endif /* CLIENT_H_ */
