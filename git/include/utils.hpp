#pragma once
	
#include <iostream>
#include <sstream>
#include <string>

template<typename T>
std::string str(const T& n)
{
std::ostringstream stm;
    stm << n;
    return stm.str();
}

template<typename T>
T str_to(const std::string& v)
{
    T t; std::stringstream b(v);
    b >> t;
    return t;
}