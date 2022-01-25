#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <windows.h>
#include <ShellAPI.h>
#include <thread>
#include "func.h"
#include <msclr/marshal.h>
#include <string>
#include <vector>
#include <direct.h>

#include <iomanip>
#include <ctime>
#include <chrono>
#include <fstream>
#include <iostream>


using  namespace System;
using  namespace System::Windows::Forms;
using  namespace System::Data::OleDb;


std::string ConvertToString(System::String^ s) {
	using namespace Runtime::InteropServices;
	const char* chars =
		(const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
	std::string	os = chars;
	Marshal::FreeHGlobal(IntPtr((void*)chars));

	return os;
}

// std::string to System::string^ 
System::String^ ConvertToString(std::string& os) {
	System::String^ s = gcnew System::String(os.c_str());

	return s;
}

System::String^ plusOne(System::String^ s) {
	std::string str = ConvertToString(s);
	int in = stoi(str);
	in++;
	str = std::to_string(in);
	s = ConvertToString(str);
	return s;
}




std::string GetTime() {
	std::stringstream stream;
	std::time_t const now_c = std::time(nullptr);
	stream << std::put_time(std::localtime(&now_c), "%F %T");
	std::string time = stream.str();
	return time;
}

std::string getdir()
{
	char current_work_dir[FILENAME_MAX];
	_getcwd(current_work_dir, sizeof(current_work_dir));
	std::string res = current_work_dir;
	return res;
}

void saveBD(std::string str) {
	std::ofstream fout;
	fout.open("BDinfo.txt", std::ios::out);
	fout << str;
	fout.close();
	return;
}

std::string getDB() {
	std::string line;

	std::ifstream in("BDinfo.txt"); // окрываем файл для чтения
	if (in.is_open())
	{
		while (getline(in, line))
		{
			std::cout << line << std::endl;
		}
	}
	in.close();
	return line;
}