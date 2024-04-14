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
	read_clients(client_f);
	read_cars(car_f);
}

void Data::read_clients(std::string clients_f)
{
	std::fstream read_file(clients_f);
	if (read_file.peek() == EOF)		// если файл пустой, завершаем работу
		return;

	check.check_open_file(read_file, clients_f, "Data::read_clients");
	Client client;
	while (!read_file.eof())
	{
		read_file>>client;
		if ( check.check_ifstream(read_file) )
			list_of_clients.insert(std::make_pair(client.get_key(), client));
	}
	read_file.close();
}

void Data::read_cars(std::string cars_f)
{
	std::fstream read_file(cars_f);
	if (read_file.peek() == EOF)		// если файл пустой, завершаем работу
		return;

	check.check_open_file(read_file, cars_f, "Data::read_cars");
	Car car;
	while (!read_file.eof())
	{
		read_file>>car;
		if ( check.check_ifstream(read_file) )
			list_of_cars.insert(std::make_pair(car.get_key(), car));
	}
	read_file.close();
}


void Data::write_data(std::string client_f, std::string car_f)
{
	write_object(client_f, list_of_clients);
	write_object(car_f, list_of_cars);
}

template void Data::write_object(std::string , std::map<std::string, Client> &);
template void Data::write_object(std::string , std::map<std::string, Car> &);

void Data::work()
{
	std::cout << "Work" << std::endl;
	char repeat = 'Y';
	int p;
	while ('Y' == repeat)
	{
		std::cout << "Select action: 0 - give a car, 1 - get a car: " ;
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
		std::cout << "Enter 'Y' to repeat select action: " ;
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
		std::cin >> fn;
		std::cout << "Enter client last name: ";
		std::cin >> ln;
		fn = fn + "_" + ln;
		i_cl = list_of_clients.find(fn);
		if (i_cl == list_of_clients.end())
		{
			std::cout << "The сlient was not found. Enter 'Y' to repeat the search: " ;
			std::cin >> repeat;
			if (repeat != 'Y')
				return;
		}
		else
			break;
	}

	// find the car
	while ('Y' == repeat)
	{
		std::cout << "Enter the number of car: " ;
		std::cin >> ln;
		i_car = list_of_cars.find(ln);
		if (i_car == list_of_cars.end())
		{
			std::cout << "The car was not found. Enter 'Y' to repeat the search: " ;
			std::cin >> repeat;
			if (repeat != 'Y')
				return;
		}
		else
			break;
	}
}

void Data::edit_data()
{
	char repeat = 'Y';
	int p;
	std::cout << "Select action: 0 - add a car, 1 - delete a car, 2 - take it out for repair" << std::endl;
	std::cout << " 3 - add a client, 4 - delete a client" << std::endl;
	std::cin >> p;

	while ('Y' == repeat)
	{
		switch(p)
		{
		case 0:
			add_car();
			break;
		case 1:
			delete_car();
			break;
		case 2:
			car_in_repair();
			break;
		case 3:
			add_client();
			break;
		case 4:
			delete_client();
			break;
		default:
			std::cout << "Error input" << std::endl;
			break;
		}
		std::cout << "Enter 'Y' to repeat edit_data" ;
		std::cin >> repeat;
	}
}

void Data::add_car()
{
	char repeat = 'Y';
	std::string mod, num;
	double cost_of_kilom, cost_of_day;
	int mileage;
	while ('Y' == repeat)
	{
		std::cout << "Enter the model a car: ";
		std::cin >> mod;
		std::cout << "Enter the number a car: ";
		std::cin >> num;
		std::cout << "Enter the cost of kilometr a car: ";
		std::cin >> cost_of_kilom;
		std::cout << "Enter the cost of day a car: ";
		std::cin >> cost_of_day;
		std::cout << "Enter the mileage a car: ";
		std::cin >> mileage;
		Car car(mod, num, mileage, cost_of_kilom, cost_of_day);
		auto ret = list_of_cars.insert(make_pair(car.get_key(), car));
		if (!ret.second)
			std::cout << "This car was" << std::endl;

		std::cout << "Enter 'Y' to repeat add car" ;
		std::cin >> repeat;
	}
}

void Data::delete_car()
{
	char repeat = 'Y';
	std::string num;
	while ('Y' == repeat)
	{
		std::cout << "Enter the number a car: ";
		std::cin >> num;
		size_t ret = list_of_cars.erase(num);
		if (ret == 0)
			std::cout << "There is no such car" << std::endl;
		std::cout << "Enter 'Y' to repeat delete car" ;
		std::cin >> repeat;
	}
}

void Data::car_in_repair()
{
	char repeat = 'Y';
	CAR_STATUS st;
	int in_st;
	std::string num;
	while ('Y' == repeat)
	{
		std::cout << "Enter the number a car: ";
		std::cin >> num;
		std::cout << "Select action: 0 - send the machine for repair, 1 - return the car from repair";
		std::cin >> in_st;
		st = (in_st == 0) ? (BROKEN) : (FREE);
		auto ret = list_of_cars.find(num);
		if (ret != list_of_cars.end())
			ret->second.set_status(st);
		else
			std::cout << "There is no such car" << std::endl;
		std::cout << "Enter 'Y' to repeat delete car" ;
		std::cin >> repeat;
	}
}

void Data::add_client()
{
	char repeat = 'Y';
	while ('Y' == repeat)
	{
		std::string f_N, l_N;
		std::cout << "Enter first name of client: " ;
		std::cin >> f_N;
		std::cout << "Enter last name of client: " ;
		std::cin >> l_N;
		Client client(f_N, l_N);
		auto ret = list_of_clients.insert(make_pair(client.get_key(), client));
		if (!ret.second)
			std::cout << "This client was" << std::endl;
		std::cout << "Enter 'Y' to repeat add client" ;
		std::cin >> repeat;
	}
}

void Data::delete_client()
{
	char repeat = 'Y';
	std::string f_N, l_N;
	std::string key;
	while ('Y' == repeat)
	{
		std::cout << "Enter first name of client: " ;
		std::cin >> f_N;
		std::cout << "Enter last name of client: " ;
		std::cin >> f_N;
		key = f_N + " " + l_N;
		auto ret = list_of_clients.erase(key);
		if (ret == 0)
			std::cout << "There is no such client" << std::endl;
		std::cout << "Enter 'Y' to repeat add client" ;
		std::cin >> repeat;
	}
}

