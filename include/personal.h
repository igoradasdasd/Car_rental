/*
 * personal.h
 *
 *  Created on: 25 февр. 2024 г.
 *      Author: axtea
 */

#ifndef INCLUDE_PERSONAL_H_
#define INCLUDE_PERSONAL_H_

#include <map>
#include <memory>

#include "client.h"
#include "../include/manager.h"
#include "../include/senior_manager.h"
#include "car.h"
#include "../include/typedef.h"

class Personal
{
public:
	void identification () const;
	void authentication () const;

	void read_data(std::string input_file_manager, POST);	// чтение данных из файла
	void write_data(std::string& ouptut_file);				// запись данных  в файл
	void check_open_file(std::ifstream&, std::string ) const; 	// проверка открытия файла
	void check_ifstream(std::ifstream&) const;					// проверка успешности чтения из файла
	void check_position(manager_ptr , POST) const;			// проверка соответсвия должностей

	mutable manager_ptr current_manager;
private:
	std::map<size_t, manager_ptr> list_of_Personal;
};




#endif /* INCLUDE_PERSONAL_H_ */
