/*
 * menu.h
 *
 *  Created on: 25 февр. 2024 г.
 *      Author: axtea
 */

#ifndef INCLUDE_MENU_H_
#define INCLUDE_MENU_H_

#include <iostream>

struct Menu final
{
	void operator()();
	size_t enter_id();
	void enter_password();

	size_t entered_id;
};



#endif /* INCLUDE_MENU_H_ */
