/*
 * manager.h
 *
 *  Created on: 11 февр. 2024 г.
 *      Author: axtea
 */

#ifndef MANAGER_H_
#define MANAGER_H_

#include "person.h"
#include "general_data.h"

class Manager: protected Person
{
public:
	static size_t id_count;
	Manager() = default;
	virtual ~Manager() = default;
	Manager(std::string f_name, std::string l_name, size_t pass):
		Person(f_name, l_name), password(pass)
		{++id_count, id = id_count;};
	std::string get_key()
		{return first_name + last_name;};
	virtual void ShowMenu();
protected:
	size_t id;				// id менеджера
	size_t password;		// пароль менеджера

};




#endif /* MANAGER_H_ */
