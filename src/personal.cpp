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
//#include <filesystem>

void Personal::check_position(manager_ptr m, POST p) const
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
		manager_ptr manager_ptr;
		switch(post)
		{
		case MANAGER:
		{
			read_file>>manager;
			check.check_ifstream(read_file, "managers are not read");
			manager_ptr = std::make_shared<Manager>(manager);
		}
			break;
		case SENIOR_MANAGER:
		{
			read_file>>s_manager;
			check.check_ifstream(read_file, "senior managers are not read");
			manager_ptr  = std::make_shared<Manager>(s_manager);
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
			check.check_ifstream(write_managers_file, "Personal::write_data");
		}
		else
		{
			write_s_managers_file << ( *(i->second) );
			check.check_ifstream(write_s_managers_file, "Personal::write_data");
		}
	}
}

void Personal::identification() const
{
	size_t in_id;
	char c = 'y';
	while (c == 'y')
	{
		std::cout << "Input your id: " ;
		std::cin >> in_id;
		auto m =  list_of_Personal.find(in_id);
		if (m == list_of_Personal.end())
		{
			std::cout << "This account is not found. Enter 'y' to repeat:  ";
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
	char c = 'y';
	while (c == 'y')
	{
		std::cout << "Input your password: " ;
		std::cin >> password;
		if (!current_manager->check_password(password))
		{
			std::cout << "This password is not correct. Enter 'y' to repeat:  ";
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
		std::cout << "Enter post: 0 - add manager, 1 - add senjor_manager, 3 - delete manager or senjor_manager ";
		std::cin >> p;
		switch(p)
		{
		case 0:
			add_manager();
			break;
		case 1:
			add_senjor_manager();
			break;
		case 3:
			delete_manager();
			break;
		default:
			std::cout << "Error input, enter 'Y' to repeat" ;
			std::cin >> repeat;
		};
		std::cout << "Enter 'Y' to continue" ;
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
	size_t del_count = list_of_Personal.erase(in_id);
	if ( 0 == del_count )
		std::cout << "A worker not found" << std::endl;
	else
		std::cout << "the removal of the employee was successful" << std::endl;
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
	manager_ptr m_ptr  = std::make_shared<Manager>(m1);
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
	manager_ptr m_ptr  = std::make_shared<Manager>(m1);
	list_of_Personal.insert(std::make_pair(m_ptr->get_id(), m_ptr));
}
