/*
 * car.h
 *
 *  Created on: 11 февр. 2024 г.
 *      Author: axtea
 */

#ifndef CAR_H_
#define CAR_H_

#include <ctime>
#include <string>
using std::string;

#include "general_data.h"
#include "../include/Manager.h"
#include "../include/Senior_Manager.h"

class Car
{
	friend Manager;
	friend Senior_manager;
;
public:
	virtual ~Car() = default;
	Car(std::string mod, int mil, double cost_of_kilom, double cost_of_d);
private:
	string model;				// модель
	string number;				// номер
	string client_key;			// id (ключ в map) клиента, взявшего машину
	int mileage;				// пробег
	double cost_of_kilometer;	// при пробеге более 300 км за сутки , берется дополнительная стоимость за каждый километер сверху
	double cost_of_day;			// стоимость дня аренды
	CAR_STATUS status;			// свободна, сломана, выдана
	time_t time;				// дата аренды
};



#endif /* CAR_H_ */
