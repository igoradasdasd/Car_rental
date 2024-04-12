/*
 * main.cpp
 *
 *  Created on: 18 февр. 2024 г.
 *      Author: axtea
 */

#include <map>
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <memory>

#include "./include/data.h"
#include "./include/car.h"
#include "./include/personal.h"
#include "./include/manager.h"
#include "./include/typedef.h"



// реализовать для Personal конструктор копий, конструктор rvalue, оператор присвоение копии, оператор присвоения rvalue
// очистить list_of_Personal при присвоении копии
// удаление map
// разобраться почему нет виртуальности

int main()
{
	Data data;
	Personal personal;

	// считывание данных
	std::string manager_file("./files/managers_file.txt");
	std::string senior_manager_file = "./files/senior_managers_file.txt";
	std::string id_count_file = "./files/id_count_file.txt";
	Manager::read_id_count(id_count_file);

	personal.read_data(manager_file, senior_manager_file);

	std::string cars_file("./files/cars.txt");
	std::string clients_file("./files/clients.txt");
	data.read_data(clients_file, cars_file);

	personal.identification();
	personal.authentication();

	personal.begin_work(data);

	data.write_data(clients_file, cars_file);
	personal.write_data(manager_file, senior_manager_file);
	Manager::write_id_count(id_count_file);

}


