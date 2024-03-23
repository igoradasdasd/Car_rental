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


// реализовать сохранение в файл
// добавить проверку при чтении, что файл пустой eof

int main()
{
	Menu menu;
	Data data;
	Personal personal;
	Manager m;
	Car c;

	// считывание данных
	std::string manager_file("./files/managers_file.txt");
	std::string senior_manager_file = "./files/senior_managers_file.txt";
	personal.read_data(manager_file, senior_manager_file);

	std::string cars_file("./files/cars.txt");
	std::string clients_file("./files/clients.txt");

	data.read_data(cars_file, clients_file);


	personal.identification();
	personal.authentication();


//	personal.write_data(manager_file, senior_manager_file);	// вызывать при изменениях в учетных записях
}


