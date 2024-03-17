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
#include "./include/personal.h"
#include "./include/function.h"
#include "./include/manager.h"
#include "./include/typedef.h"


// реализовать сохранение в файл

int main()
{
	Menu menu;
	Data data;
	Personal personal;
	Manager m;
	//std::shared_ptr<Manager> m1 = std::make_shared<Manager>(m);

	// считывание данных
	std::string manager_file("./files/managers_file.txt");
	std::string senior_manager_file = "./files/senior_managers_file.txt";
	personal.read_data(manager_file, senior_manager_file);



	personal.identification();
	personal.authentication();


}


