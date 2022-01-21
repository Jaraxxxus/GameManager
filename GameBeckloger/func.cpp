#pragma once

#include <windows.h>
#include <ShellAPI.h>
#include <thread>
#include "func.h"
#include <msclr/marshal.h>
#include <string>
#include <vector>

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

