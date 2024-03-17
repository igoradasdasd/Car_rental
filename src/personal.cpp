/*
 * personal.cpp
 *
 *  Created on: 13 мар. 2024 г.
 *      Author: axtea
 */

#include "../include/personal.h"
#include <fstream>
#include <utility>

void Personal::check_open_file(std::fstream& in, std::string name, const std::string& function_name) const
{
	if (!in)
	{
		std::cout << "the file "  << name << " is'nt open in function " <<
				function_name << std::endl; // файл не открыт, завершаем работу программы
		exit(EXIT_FAILURE);
	}
}

void Personal::check_ifstream(std::fstream& in_stream, const std::string& function_name) const
{
	if (!in_stream)
	{
		std::cout << function_name <<" - error ifstream" << std::endl; // ошибка потока
		exit(EXIT_FAILURE);
	}
}

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

	check_open_file(read_file, file_manager, "Personal::read_data_from_file");

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
			check_ifstream(read_file, "Personal::read_data_from_file");
			manager_ptr = std::make_shared<Manager>(manager);
		}
			break;
		case SENIOR_MANAGER:
		{
			read_file>>s_manager;
			check_ifstream(read_file, "Personal::read_data_from_file");
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
	check_open_file(write_managers_file, file_managers, "Personal::wirte_data_from_file");

	std::fstream write_s_managers_file(file_senior_managers);
	check_open_file(write_s_managers_file, file_senior_managers, "Personal::wirte_data_from_file");

	std::fstream write_managers_file1(file_managers);

	write_managers_file1 << "1";

	for (auto i = list_of_Personal.cbegin();
			i != list_of_Personal.cend(); ++i)
	{
		if (i->second->position() == MANAGER)
		{
			write_managers_file << (i->second);
			check_ifstream(write_managers_file, "Personal::write_data");
		}
		else
		{
			write_s_managers_file << (i->second);
			check_ifstream(write_s_managers_file, "Personal::write_data");
		}
	}
}

void Personal::wirte_data_from_file(std::string file_manager, POST post)
{
	std::fstream read_file(file_manager);

	check_open_file(read_file, file_manager, "Personal::wirte_data_from_file");

	Manager manager;
	Senior_manager s_manager;

	for (auto i = list_of_Personal.cbegin();
			i != list_of_Personal.cend(); ++i)
	{
		i->second->position();
	}

/*
	while (!read_file.eof())
	{
		manager_ptr manager_ptr;
		switch(post)
		{
		case MANAGER:
		{
			read_file>>manager;
			check_ifstream(read_file);
			manager_ptr = std::make_shared<Manager>(manager);
		}
			break;
		case SENIOR_MANAGER:
		{
			read_file>>s_manager;
			check_ifstream(read_file);
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
	*/
}

void
Personal::identification() const
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

void
Personal::authentication() const
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
