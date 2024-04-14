/*
 * car.h
 *
 *  Created on: 14 апр. 2024 г.
 *      Author: Игорь
 */

#ifndef INCLUDE_CAR_H_
#define INCLUDE_CAR_H_

#include <iostream>
#include <string>
#include <time.h>

#include "../include/general_data.h"

class Car
{
	friend std::ostream & operator << (std::ostream & , const Car &);
	friend std::istream & operator >> (std::istream &, Car &);
public:
	static constexpr int kilometer_limit = 300; 		// сколько допусается проехать за сутки
	static constexpr int hour_limit = 2;				// если машина более 2 часов в прокате - это считается за сутки

	Car() = default;
	Car(std::string mod, std::string num, int mil, double cost_of_km, double cost_of_d);
	~Car() = default;
	std::string get_key(){ return number;}
	bool check_status();

	void set_status(const CAR_STATUS& in){status = in;};
	void set_client_key(const std::string& in){client_key = in;};
	void clear_client_key(){client_key = std::string("0");};
	void set_time(){ time_car = time(NULL);}
	time_t get_time(){ return time_car;}
	int get_mileage(){return mileage;}
	void set_mileage(int in){ mileage = in;}
	double get_cost_of_kilometer(){return cost_of_kilometer;}
	double get_cost_of_day(){return cost_of_day;}
private:
	std::string model;								// модель
	std::string number;								// номер
	std::string client_key = std::string("0");		// id (ключ в map) клиента, взявшего машину
	double cost_of_kilometer;						// при пробеге более 300 км за сутки , берется дополнительная стоимость за каждый километер сверху
	double cost_of_day;								// стоимость дня аренды
	int mileage;									// пробег
	CAR_STATUS status = FREE;						// свободна, сломана, выдана
	time_t time_car = 0;		// дата аренды
};

std::ostream & operator << (std::ostream & , const Car &);
std::istream & operator >> (std::istream &, Car &);


#endif /* INCLUDE_CAR_H_ */
