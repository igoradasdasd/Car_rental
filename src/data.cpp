/*
 * data.cpp
 *
 *  Created on: 25 февр. 2024 г.
 *      Author: axtea
 */

//#include "../include/personal.h"
#include "../include/data.h"

void Data::read_data(std::string file, std::string car_f)
{
	read_clients(file, list_of_clients);
	read_cars(file, list_of_cars);
}

void Data::read_clients(std::string clients_f, std::map<std::string, Client> list)
{
	std::fstream read_file(clients_f);
	if (read_file.peek() == EOF)		// если файл пустой, завершаем работу
		return;

	check.check_open_file(read_file, clients_f, "Data::read_clients");
	Client client;
	while (!read_file.eof())
	{
		read_file>>client;
		check.check_ifstream(read_file, "client are not read");
		list.insert(std::make_pair(client.get_key(), client));
	}
	read_file.close();
}

void Data::read_cars(std::string cars_f, std::map<std::string, Car> list)
{
	std::fstream read_file(cars_f);
	if (read_file.peek() == EOF)		// если файл пустой, завершаем работу
		return;

	check.check_open_file(read_file, cars_f, "Data::read_cars");
	Car car;
	while (!read_file.eof())
	{
		read_file>>car;
		check.check_ifstream(read_file, "client are not read");
		list.insert(std::make_pair(car.get_key(), car));
	}
	read_file.close();
}
/*
void Data::read_clients_from_file(std::string clients_f)
{

}
*/


