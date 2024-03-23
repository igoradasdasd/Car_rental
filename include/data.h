/*
 * data1.h
 *
 *  Created on: 9 мар. 2024 г.
 *      Author: axtea
 */

#ifndef INCLUDE_DATA_H_
#define INCLUDE_DATA_H_

#include <map>
#include <vector>

#include "car.h"
#include "client.h"
#include "manager.h"
#include "senior_manager.h"
#include "check_file_stream.h"


//класс, содержащий перечень клиентов и машин
class Data final
{
	friend class Manager;
	friend class Senior_manager;
public:
	Check_file_stream check;
	Data() = default;
	void read_data(std::string file, std::string car_f);
	void write_data(std::string ouptut_file, std::string car_f);

private:
	template<typename T>
	void read_from_file(std::string clients_f, std::map<std::string, T> list);

	std::map<std::string, Client> list_of_clients;
	std::map<std::string, Car> list_of_cars;

};

template<typename T>
void Data::read_from_file(std::string clients_f, std::map<std::string, T> list)
{

}

extern
template
void Data::read_from_file(std::string clients_f, std::map<std::string, Client> list);

extern
template
void Data::read_from_file(std::string clients_f, std::map<std::string, Car> list);



#endif /* INCLUDE_DATA_H_ */
