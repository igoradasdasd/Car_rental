/*
 * menu.h
 *
 *  Created on: 25 февр. 2024 г.
 *      Author: axtea
 */

#ifndef INCLUDE_MENU_H_
#define INCLUDE_MENU_H_

#include <iostream>

#include "manager.h"

struct Menu final
{
	void operator()();
	size_t enter_id();
	void enter_password();

	size_t entered_id;

	Manager* enter_id() const;		// идентификация
	bool enter_password() const;	// аутентификация
};



#endif /* INCLUDE_MENU_H_ */
