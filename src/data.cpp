/*
 * data.cpp
 *
 *  Created on: 25 февр. 2024 г.
 *      Author: axtea
 */

#include "../include/personal.h"

Manager*
Personal::search_by_id(size_t in_id)
{

	auto it = list_of_Manager.find(in_id);
	if (it != list_of_Manager.end())
		return &(it->second);

	auto it1 = list_of_Senior_Manager.find(in_id);
	if (it1 != list_of_Senior_Manager.end())
		return &(it1->second);

	return nullptr;

}




