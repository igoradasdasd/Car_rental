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
	friend std::ostream& operator<< (std::ostream&, const Manager&);
	friend std::istream& operator>> (std::istream&, Manager&);
public:
	static size_t id_count;
	Manager() = default;
	Manager(std::string f_name, std::string l_name, size_t pass);
	virtual ~Manager() = default;
	std::string get_key()
		{return first_name + last_name;};
	virtual void ShowMenu();
	size_t get_id() const { return id;}
	bool check_passwor(size_t in) const { return in == password;};
	POST position() const {return post;};

protected:
	size_t id;				// id менеджера
	size_t password;		// пароль менеджера
	POST post = MANAGER;
};

std::ostream& operator<< (std::ostream&, const Manager&);
std::istream& operator>> (std::istream&, Manager&);

#endif /* MANAGER_H_ */
