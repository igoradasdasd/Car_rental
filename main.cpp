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

#include "./include/menu.h"
#include "./include/data.h"
#include "./include/car.h"
#include "./include/personal.h"
#include "./include/function.h"
#include "./include/manager.h"
#include "./include/typedef.h"

// добавить в Data edit_data(редактирование данных:клиентов и машин - добавление удалени)
// реализовать для Personal конструктор копий, конструктор rvalue, оператор присвоение копии, оператор присвоения rvalue
// personal.current_manager->action(Personal&, Data&) - добавление и удаление всех сущностей, получение и выдача машин
// реализовать сохранение и чтение id в файл

int main()
{

	Data data;
	Personal personal;
	Car c;

	// считывание данных
	std::string manager_file("./files/managers_file.txt");
	std::string senior_manager_file = "./files/senior_managers_file.txt";
	personal.read_data(manager_file, senior_manager_file);

	std::string cars_file("./files/cars.txt");
	std::string clients_file("./files/clients.txt");
	data.read_data(clients_file, cars_file);

	personal.identification();
	personal.authentication();
	personal.edit_personal_list();

	data.write_data(clients_file, cars_file);
	personal.write_data(manager_file, senior_manager_file);
}


