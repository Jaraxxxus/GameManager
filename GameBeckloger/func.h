#pragma once

#include <string>

std::string ConvertToString(System::String^ s);
System::String^ ConvertToString(std::string& os);
System::String^ plusOne(System::String^ s);
std::string GetTime();
std::string getdir();

void saveBD(std::string str);
std::string getDB();