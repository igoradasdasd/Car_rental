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
#include "../include/check_file_stream.h"

class Personal
{
public:
	Check_file_stream check;

	void identification () const;
	void authentication () const;

	void read_data(std::string file_managers, std::string file_senior_managers);	// чтение данных
	void write_data(std::string file_managers, std::string file_senior_managers);	// запись данных
		// file_managers - файл, где хранятся менеджеры
		// file_senior_managers - файл, где храняться старшие менеджеры
	void check_position(manager_ptr , POST) const;			// проверка соответсвия должностей

	void edit_personal_list();
	void begin_work(Data& data);

	mutable manager_ptr current_manager;					// можно обойтись без mutable, но надо убрать const у соответсвующей функции
private:
	void read_data_from_file(std::string file_manager, POST);	// чтение данных из файла
	void wirte_data_from_file(std::string file_manager, POST);	// запись данных в файл
	void add_manager();
	void add_senjor_manager();
	void delete_manager();
	std::map<size_t, manager_ptr> list_of_Personal;
};




#endif /* INCLUDE_PERSONAL_H_ */
