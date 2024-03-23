/*
 * check_file_stream.h
 *
 *  Created on: 17 мар. 2024 г.
 *      Author: axtea
 */

#ifndef INCLUDE_CHECK_FILE_STREAM_H_
#define INCLUDE_CHECK_FILE_STREAM_H_

#include <fstream>
#include <string>

// проверка потока и открытия файла(успешно/неуспешно)
struct Check_file_stream
{
	void check_open_file(std::fstream&, std::string, const std::string&) const; 	// проверка открытия файла
	void check_ifstream(std::fstream&, const std::string&) const;					// проверка успешности чтения из файла
};

inline void Check_file_stream::check_open_file(std::fstream& in, std::string name, const std::string& function_name) const
{
	if (!in)
	{
		std::cout << "the file "  << name << " is'nt open in function " <<
				function_name << std::endl; // файл не открыт, завершаем работу программы
//		exit(EXIT_FAILURE);
	}
}

inline void Check_file_stream::check_ifstream(std::fstream& in_stream, const std::string& function_name) const
{
	if (!in_stream )
	{
		std::cout << function_name <<" - error ifstream" << std::endl; // ошибка потока
//		exit(EXIT_FAILURE);
	}
}

#endif /* INCLUDE_CHECK_FILE_STREAM_H_ */
