/*
 * function.cpp
 *
 *  Created on: 25 февр. 2024 г.
 *      Author: axtea
 */

#include "../include/menu.h"
#include "../include/data.h"
#include "../include/personal.h"

Manager* find_personal(Personal& in_personal, Menu& in_menu)
{
	Manager *find_manager;
	char repeat;
	do
	{
		find_manager = in_personal.search_by_id( in_menu.enter_id() );
		if (!find_manager)
		{
			std::cout << "The manager was not found. For repeat enter 'Y' ";
			std::cin >> repeat;
		}
	} while ( !(find_manager) && repeat == 'Y' );

	// завершение работы, так как менеджер не найден
	if (!find_manager)
	{
		std::cout << "The manager was not found. The program has been completed.";
		return EXIT_SUCCESS;
	}
}


