/*
 * senior_manager.h
 *
 *  Created on: 11 февр. 2024 г.
 *      Author: axtea
 */

#ifndef SENIOR_MANAGER_H_
#define SENIOR_MANAGER_H_

#include <string>

#include "manager.h"


class Senior_manager final: protected Manager
{
public:
	Senior_manager() = default;
	virtual ~Senior_manager() = default;
	Senior_manager(std::string f_name, std::string l_name, size_t pass);
	/*:
		Manager(f_name,  l_name,  pass){}
*/

protected:

};



#endif /* SENIOR_MANAGER_H_ */
