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

#include "./include/menu.h"
#include "./include/data.h"
#include "./include/personal.h"
#include "./include/function.h"

// протестировать деструкторы Person, добавив и удалив virtual
int main()
{
	Menu menu;
	Personal personal;
	Manager* current_manager;

	current_manager = find_personal(personal, menu);

	current_manager->ShowMenu();





}


