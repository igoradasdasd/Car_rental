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

// перейти от умного указателя к обычому в Personal
//
// реализовать для Personal конструктор копий, конструктор rvalue, оператор присвоение копии, оператор присвоения rvalue

// реализовать сохранение и чтение id в файл

int main()
{

	Data data;
	Personal personal;
	Car c;

	Manager m;
	Senior_manager s_m;
	Manager * p;
//	p = &s_m;
//	p->action(data);
	manager_ptr manager_ptr1;
	manager_ptr1 = std::make_shared<Manager>(s_m);
	manager_ptr1->action(data);
	p = static_cast<Manager *>(manager_ptr1);



	// считывание данных
	std::string manager_file("./files/managers_file.txt");
	std::string senior_manager_file = "./files/senior_managers_file.txt";
	personal.read_data(manager_file, senior_manager_file);

	std::string cars_file("./files/cars.txt");
	std::string clients_file("./files/clients.txt");
	data.read_data(clients_file, cars_file);

	personal.identification();
	personal.authentication();

	personal.begin_work(data);

	data.write_data(clients_file, cars_file);
	personal.write_data(manager_file, senior_manager_file);
}


