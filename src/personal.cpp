/*
 * personal.cpp
 *
 *  Created on: 13 мар. 2024 г.
 *      Author: axtea
 */

#include "../include/personal.h"
#include <fstream>
#include <iostream>
#include <utility>

Personal::Personal(const Personal& in_personal)
{
	copy(in_personal);
}

Personal::Personal(Personal&& in_personal) noexcept
{
	for (auto i: in_personal.list_of_Personal)
	{
		list_of_Personal.insert(std::make_pair(i.first, i.second ));
		i.second = nullptr;
	}
}

Personal& Personal::operator = (const Personal& in_personal)
{
	// освобождаем ресурсы текущего объекта
	if (this != (&in_personal))	// защита от копирования в самого себя
	{
		clear_list();
		copy(in_personal);
	}
	return *this;
}

Personal& Personal::operator = (const Personal&& in_personal) noexcept
{
	if (this != (&in_personal))	// защита от копирования в самого себя
	{
		// освобождаем ресурсы текущего объекта
		clear_list();

		for (auto i: in_personal.list_of_Personal)
		{
			list_of_Personal.insert(std::make_pair(i.first, i.second ));
			i.second = nullptr;
		}
	}
	return *this;
}

void Personal::clear_list()
{
	auto i = list_of_Personal.begin();
	while (i != list_of_Personal.end() )
	{
		delete i->second;
		i = list_of_Personal.erase(i);
	}
}

void Personal::copy(const Personal& in_personal)
{
	for (auto i: in_personal.list_of_Personal)
	{
		list_of_Personal.insert(std::make_pair(i.first, new Manager(*i.second) ));
	}
}

Personal::~Personal()
{
	for (auto a: list_of_Personal)
	{
		delete (a.second);
	}
}

void Personal::check_position(Manager * m, POST p) const
{
	if (m->position() != p)
	{
		std::cout << "Personal::read_data() - mismatch of the position" << std::endl; // несоответствие должностей
		exit(EXIT_FAILURE);
	}
}

void Personal::read_data(std::string file_managers, std::string file_senior_managers)
{
	read_data_from_file(file_managers, MANAGER);
	read_data_from_file(file_senior_managers, SENIOR_MANAGER);
}

void Personal::read_data_from_file(std::string file_manager, POST post)
{
	std::fstream read_file(file_manager);

	if (read_file.peek() == EOF)		// если файл пустой, завершаем работу
		return;

	check.check_open_file(read_file, file_manager, "Personal::read_data_from_file (1)");

	Manager manager;
	Senior_manager s_manager;

	while (!read_file.eof())
	{
		Manager * manager_ptr;
		switch(post)
		{
		case MANAGER:
		{
			read_file>>manager;
			if (check.check_ifstream(read_file))
			manager_ptr = new Manager(manager);
		}
			break;
		case SENIOR_MANAGER:
		{
			read_file>>s_manager;
			if (check.check_ifstream(read_file))
			manager_ptr  = new Manager(s_manager);
		}
			break;
		default:
			std::cout << "Personal::read_data() - unknown position" << std::endl; // файл не открыт, завершаем работу программы
			exit(EXIT_FAILURE);
			break;
		}
		check_position(manager_ptr, post);
		list_of_Personal.insert(std::make_pair(manager_ptr->get_id(), manager_ptr));
	}
	read_file.close();	// закрываем файл
}

void Personal::write_data(std::string file_managers, std::string file_senior_managers)
{
	std::fstream write_managers_file(file_managers);
	check.check_open_file(write_managers_file, file_managers, "Personal::wirte_data_from_file");

	std::fstream write_s_managers_file(file_senior_managers);
	check.check_open_file(write_s_managers_file, file_senior_managers, "Personal::wirte_data_from_file");

	std::fstream write_managers_file1(file_managers);

	for (auto i = list_of_Personal.cbegin();
			i != list_of_Personal.cend(); ++i)
	{
		if (i->second->position() == MANAGER)
		{
			write_managers_file << ( *(i->second) );
			check.check_ifstream(write_managers_file);
		}
		else
		{
			write_s_managers_file << ( *(i->second) );
			check.check_ifstream(write_s_managers_file);
		}
	}
}

void Personal::identification() const
{
	size_t in_id;
	char c = 'Y';
	while (c == 'Y')
	{
		std::cout << "Input your id: " ;
		std::cin >> in_id;
		auto m =  list_of_Personal.find(in_id);
		if (m == list_of_Personal.end())
		{
			std::cout << "This account is not found. Enter 'Y' to repeat:  ";
			std::cin >> c;
		}
		else
		{
			current_manager = m->second;
			return;
		}
	}
	exit(EXIT_FAILURE);
}

void Personal::authentication() const
{
	size_t password;
	char c = 'Y';
	while (c == 'Y')
	{
		std::cout << "Input your password: " ;
		std::cin >> password;
		if (!current_manager->check_password(password))
		{
			std::cout << "This password is not correct. Enter 'Y' to repeat:  ";
			std::cin >> c;
		}
		else
		{
			return;
		}
	}
	exit(EXIT_FAILURE);
}

void Personal::edit_personal_list()
{
	std::cout << "Edit personal list" << std::endl;
	int p;
	char repeat = 'Y';
	while (repeat == 'Y')
	{
		std::cout << "Enter post: 0 - add manager, 1 - add senjor_manager, 2 - delete manager or senjor_manager: ";
		std::cin >> p;
		switch(p)
		{
		case 0:
			add_manager();
			break;
		case 1:
			add_senjor_manager();
			break;
		case 2:
			delete_manager();
			break;
		default:
			std::cout << "Error input, enter 'Y' to repeat: " ;
			std::cin >> repeat;
		};
		std::cout << "Enter 'Y' to continue: " ;
		std::cin >> repeat;
	}
}

void Personal::delete_manager()
{
	size_t in_id;
	std::cout << "Enter personal id ";
	std::cin >> in_id;
	if (in_id == current_manager->get_id())
	{
		std::cout << "You can't delete yourself" << std::endl;
		return;
	}

	if (list_of_Personal.end() == list_of_Personal.find(in_id))
		std::cout << "A worker not found" << std::endl;
	else
	{
		delete list_of_Personal.find(in_id)->second;
		list_of_Personal.erase(in_id);
		std::cout << "the removal of the employee was successful" << std::endl;
	}
}

void Personal::add_manager()
{
	std::string first_name, last_name;
	size_t pass;
	std::cout << " Enter first name: " << std::endl;
	std::cin >> first_name;
	std::cout << " Enter last name: " << std::endl;
	std::cin >> last_name;
	std::cout << " Enter password: " << std::endl;
	std::cin >> pass;
	Manager m1(first_name, last_name, pass);
	Manager * m_ptr  = new Manager(m1);
	list_of_Personal.insert(std::make_pair(m_ptr->get_id(), m_ptr));
}

void Personal::add_senjor_manager()
{
	std::string first_name, last_name;
	size_t pass;
	std::cout << " Enter first name: " << std::endl;
	std::cin >> first_name;
	std::cout << " Enter last name: " << std::endl;
	std::cin >> last_name;
	std::cout << " Enter password: " << std::endl;
	std::cin >> pass;
	Senior_manager m1(first_name, last_name, pass);
	Manager * m_ptr  = new Manager(m1);
	list_of_Personal.insert(std::make_pair(m_ptr->get_id(), m_ptr));
}

void Personal::begin_work(Data& data)
{
	if (current_manager->position() == MANAGER)
	{
		std::cout << "Work as a manager" << std::endl;
		current_manager->action(data);
	}
	else
	{
		// виртуальность так и не отработала
		Senior_manager * s_m = dynamic_cast<Senior_manager *>(current_manager);
		int p;
		std::cout << "Select action: 0 - work with the data, 1 - work with personal list: ";
		std::cin >> p;
		switch(p)
		{
		case 0:
			s_m->action(data);
			break;
		case 1:
			edit_personal_list();
			break;
		default:
			std::cout << "Error input" << std::endl;
			break;
		}
	}
}
