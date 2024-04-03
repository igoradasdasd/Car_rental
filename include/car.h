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
	friend std::ostream & operator << (std::ostream &, const Car rhs);
	friend std::istream & operator >> (std::istream &, Car rhs);
public:
	static constexpr int kilometer_limit = 300; 		// сколько допусается проехать за сутки
	static constexpr int hour_limit = 2;				// если машина более 2 часов в прокате - это считается за сутки

	~Car() = default;
	Car() = default;
	Car(string mod, string num, int mil, double cost_of_km, double cost_of_d);
	std::string get_key(){ return number;}
	bool check_status();
	void set_status(const CAR_STATUS& in){status = in;};
	void set_client_key(const std::string& in){client_key = in;};
	void clear_client_key(){client_key = std::string();};
	void set_time(){ time_car = time(NULL);}
	time_t get_time(){ return time_car;}
	int get_mileage(){return mileage;}
	void set_mileage(int in){ mileage = in;}
	double get_cost_of_kilometer(){return cost_of_kilometer;}
	double get_cost_of_day(){return cost_of_day;}
private:
	string model;				// модель
	string number;				// номер
	string client_key = std::string();			// id (ключ в map) клиента, взявшего машину
	double cost_of_kilometer;	// при пробеге более 300 км за сутки , берется дополнительная стоимость за каждый километер сверху
	double cost_of_day;			// стоимость дня аренды
	int mileage;				// пробег
	CAR_STATUS status = FREE;			// свободна, сломана, выдана
	time_t time_car = 0;		// дата аренды
};

std::ostream & operator << (std::ostream &,  const Car rhs);
std::istream & operator >> (std::istream &, Car rhs);

#endif /* INCLUDE_CAR_H_ */
