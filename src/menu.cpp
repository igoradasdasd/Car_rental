/*
 * main.cpp
 *
 *  Created on: 25 февр. 2024 г.
 *      Author: axtea
 */

#include "../include/menu.h"

size_t Menu::enter_id()
{
	std::cout << "Enter your id: ";
	std::cin >> entered_id;
	return entered_id;
}


void Menu::operator()()
{

	std::cout << "Enter your id: ";
	std::cin >> entered_id;

}
