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
//#include "manager.h"
//#include "senior_manager.h"
#include "check_file_stream.h"


//класс, содержащий перечень клиентов и машин
class Data final
{
public:
	Check_file_stream check;
	Data() = default;
	void read_data(std::string file, std::string car_f);
	void write_data(std::string ouptut_file, std::string car_f);

private:
	void read_clients(std::string clients_f, std::map<std::string, Client> list);
	void read_cars(std::string clients_f, std::map<std::string, Car> list);

	std::map<std::string, Client> list_of_clients;
	std::map<std::string, Car> list_of_cars;

};



#endif /* INCLUDE_DATA_H_ */
