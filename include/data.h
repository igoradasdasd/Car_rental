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
	void read_data(std::string client_f, std::string car_f);
	void write_data(std::string client_f, std::string car_f);

	void work();		// выдача/получение машины
	void edit_data();	// редактирование списка машин и клиентов

private:
	void add_client();
	void delete_client();
	void add_car();
	void delete_car();
	void car_in_repair();

	void read_clients(std::string clients_f, std::map<std::string, Client> list);
	void read_cars(std::string clients_f, std::map<std::string, Car> list);
	void get_car();			// получить машину
	void give_car();		// выдать машину
	void find(std::map<std::string, Client>::iterator &, std::map<std::string, Car>::iterator &);

	template <typename T>
	void write_object(std::string clients_f, std::map<std::string, T>);
	std::map<std::string, Client> list_of_clients;
	std::map<std::string, Car> list_of_cars;
};

template <typename T>
void Data::write_object(std::string clients_f, std::map<std::string, T> list)
{
	std::fstream write_clients_file(clients_f);
	check.check_open_file(write_clients_file, clients_f, "Data::write_clients");
	for (auto i = list.cbegin();
			i != list.cend(); ++i)
	{
		write_clients_file << ( (i->second) );

		check.check_ifstream(write_clients_file, "Data::write_clients");
	}
}

extern template void Data::write_object(std::string , std::map<std::string, Client> );
extern template void Data::write_object(std::string , std::map<std::string, Car> );

#endif /* INCLUDE_DATA_H_ */
