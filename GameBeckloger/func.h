#pragma once

#include <string>

std::string ConvertToString(System::String^ s);
System::String^ ConvertToString(std::string& os);