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
	{
		std::cout << "Give car was break:: client is in blacklist or not return a car" << std::endl;
		return;	// если клиент не вернул машину или в блеклисте, завершаем работу
	}

	if (!it_car->second.check_status())
	{
		std::cout << "Give car was break:: car is busy or broken" << std::endl;
		return;	// если машина занята или сломана, завершаем работу
	}

	it_client->second.set_car_key( it_car->second.get_key() );		// Записали машину за клиентом
	it_client->second.set_status(CAR_IS_RENTAL);					// изменили статус клиента

	it_car->second.set_client_key( it_client->second.get_key() ); 	// записали Id клиента в профиль машины
	it_car->second.set_status(BUSY);								// изменили статус машины
	it_car->second.set_time();										// фиксирую время выдачи машины
}

void Data::get_car()
{
	std::map<std::string, Client>::iterator it_client;
	std::map<std::string, Car>::iterator it_car;
	// find the client and the car

	find(it_client, it_car );
	if (it_client == list_of_clients.end() ||
					it_car == list_of_cars.end() )
		return;

	it_client->second.clear_car_key( );								// отписали машину от клиентом
	it_client->second.set_status(CAR_IS_NOT_RENTAL);				// изменили статус клиента

	it_car->second.clear_client_key( );							 	// записали Id клиента в профиль машины
	it_car->second.set_status(FREE);								// изменили статус машины
	time_t current_time = time(NULL);								// фиксирую время получения
	current_time = current_time - it_car->second.get_time();		// вычисляем разницу времени в секундах
	int count_of_day = current_time/(24*60*60);						// вычисляем сколько дней машина была в прокате
	int count_of_hour = (current_time%(24*60*60))/(60*60);			// вычисляем сколько часов сверх count_of_day машина была в прокате
	if (count_of_hour > Car::hour_limit)
		++count_of_day;

	int current_mileage, diff;
	std::cout << "Enter current mileage: ";
	std::cin >> current_mileage;									// ввод пробега
	diff = current_mileage - it_car->second.get_mileage();			// расчет пробега километры
	it_car->second.set_mileage(current_mileage);					// сохранение пробега

	int cost;
	cost =  count_of_day * it_car->second.get_cost_of_day();
	// если клиент проехал больше допустимого, необходимо заплатить за каждый километр сверх нормы
	if (diff > (Car::kilometer_limit*count_of_day) )
		cost += ( (diff - Car::kilometer_limit*count_of_day) *  it_car->second.get_cost_of_kilometer());
	std::cout << "To be paid: " << cost << std::endl;
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

