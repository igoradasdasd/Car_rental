/*
 * manager.h
 *
 *  Created on: 11 февр. 2024 г.
 *      Author: axtea
 */

#ifndef MANAGER_H_
#define MANAGER_H_

#include <iostream>

#include "person.h"
#include "general_data.h"

class Manager: public Person
{
public:
	static size_t id_count;
	Manager() = default;
	Manager(std::string f_name, std::string l_name, size_t pass);
	virtual ~Manager() = default;
	std::string get_key()
		{return first_name + last_name;};
	virtual void ShowMenu();
	size_t get_id() { return id;}

protected:
	size_t id;				// id менеджера
	size_t password;		// пароль менеджера

};




#endif /* MANAGER_H_ */
