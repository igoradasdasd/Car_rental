/*
 * personal.cpp
 *
 *  Created on: 13 мар. 2024 г.
 *      Author: axtea
 */

#include "../include/personal.h"
#include <fstream>
#include <utility>

void Personal::check_open_file(std::ifstream& in, std::string name) const
{
	if (!in)
	{
		std::cout << "the file "  << name << " is'nt open" << std::endl; // файл не открыт, завершаем работу программы
		exit(EXIT_FAILURE);
	}
}

void Personal::check_ifstream(std::ifstream& in_stream) const
{
	if (!in_stream)
	{
		std::cout << "Personal::read_data() - error read ifstream" << std::endl; // ошибка чтения из потока
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

void Personal::read_data(std::string input_file_manager, POST post)
{
	std::ifstream read_file(input_file_manager);

	check_open_file(read_file, input_file_manager);

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
		std::cout << std::endl;
		if (!current_manager->check_passwor(password))
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
