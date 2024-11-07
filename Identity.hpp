#pragma once
#include <iostream>

class Identity {
public:
	virtual void open_menu() = 0;
	std::string name;
	std::string pwd;
};