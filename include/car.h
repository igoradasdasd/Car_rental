/*
 * car.h
 *
 *  Created on: 10 мар. 2024 г.
 *      Author: axtea
 */

#ifndef INCLUDE_CAR_H_
#define INCLUDE_CAR_H_

#include <time.h>
#include <string>
#include <iostream>

using std::string;

#include "general_data.h"

class Car
{
	friend std::ostream & operator << (std::ostream &, Car rhs);
	friend std::istream & operator >> (std::istream &, Car rhs);
public:
	~Car() = default;
	Car() = default;
	Car(string mod, string num, int mil, double cost_of_km, double cost_of_d,
			CAR_STATUS c_s);

private:
	string model;				// модель
	string number;				// номер
	string client_key;			// id (ключ в map) клиента, взявшего машину
	double cost_of_kilometer;	// при пробеге более 300 км за сутки , берется дополнительная стоимость за каждый километер сверху
	double cost_of_day;			// стоимость дня аренды
	int mileage;				// пробег
	CAR_STATUS status;			// свободна, сломана, выдана
	time_t time = 0;			// дата аренды
};

std::ostream & operator << (std::ostream &, Car rhs);
std::istream & operator >> (std::istream &, Car rhs);

#endif /* INCLUDE_CAR_H_ */
