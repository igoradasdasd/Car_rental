/*
 * data.cpp
 *
 *  Created on: 25 февр. 2024 г.
 *      Author: axtea
 */

//#include "../include/personal.h"
#include "../include/data.h"

void Data::read_data(std::string client_f, std::string car_f)
{
	read_clients(client_f, list_of_clients);
	read_cars(car_f, list_of_cars);
}

void Data::read_clients(std::string clients_f, std::map<std::string, Client> map_object)
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
		map_object.insert(std::make_pair(client.get_key(), client));
	}
	read_file.close();
}

void Data::read_cars(std::string cars_f, std::map<std::string, Car> map_object)
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
		map_object.insert(std::make_pair(car.get_key(), car));
	}
	read_file.close();
}


void Data::write_data(std::string client_f, std::string car_f)
{
	write_object(client_f, list_of_clients);
	write_object(car_f, list_of_cars);
}

template void Data::write_object(std::string , std::map<std::string, Client> );
template void Data::write_object(std::string , std::map<std::string, Car> );

void Data::work()
{
	std::cout << "Work" << std::endl;
	char repeat = 'Y';
	int p;
	while ('Y' == repeat)
	{
		std::cout << "Select action: 0 - give a car, 1 - get a car" ;
		std::cin >> p;
		switch(p)
		{
		case 0:
			give_car();
			break;
		case 1:
			get_car();
			break;
		default:
			std::cout << "Error input" << std::endl;
			break;
		}
		std::cout << "Enter 'Y' to continue" ;
		std::cin >> repeat;
	}
}

void Data::give_car()
{
	std::map<std::string, Client>::iterator it_client;
	std::map<std::string, Car>::iterator it_car;
	// find the client and the car
	find(it_client, it_car );
	if (it_client == list_of_clients.end() ||
					it_car == list_of_cars.end() )
		return;

	if (!it_client->second.check_status())
		return;	// если клиент не вернул машину или в блаклисте, завершаем работу

}

void Data::get_car()
{

}

void Data::find(std::map<std::string, Client>::iterator & i_cl,
		std::map<std::string, Car>::iterator & i_car)
{
	std::string ln, fn;
	char repeat = 'Y';
	while ('Y' == repeat)
	{
		std::cout << "Enter client first name: " ;
		std::cin >> ln;
		std::cout << std::endl << "Enter client last name: ";
		fn = fn + " " + ln;
		i_cl = list_of_clients.find(fn);
		if (i_cl == list_of_clients.end())
		{
			std::cout << "The сlient was not found. Enter 'Y' to repeat" ;
			std::cin >> repeat;
			if (repeat != 'Y')
				return;
		}
	}

	// find the car
	while ('Y' == repeat)
	{
		std::cout << "Enter the number of car: " ;
		std::cin >> ln;
		i_car = list_of_cars.find(ln);
		if (i_car == list_of_cars.end())
		{
			std::cout << "The car was not found. Enter 'Y' to repeat" ;
			std::cin >> repeat;
			if (repeat != 'Y')
				return;
		}
	}
}

