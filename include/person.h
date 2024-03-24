/*
 * person.h
 *
 *  Created on: 11 февр. 2024 г.
 *      Author: axtea
 */

#ifndef PERSON_H_
#define PERSON_H_

#include <utility>
#include <string>

// абстрактный базовый класс
class Person
{
public:
	virtual ~Person() = default;
	Person() = default;
	Person(std::string f_name, std::string l_name):first_name(f_name), last_name(l_name){};
	std::pair<std::string, std::string> get_name() const;
protected:
	std::string first_name;
	std::string last_name;
};

#endif /* PERSON_H_ */
