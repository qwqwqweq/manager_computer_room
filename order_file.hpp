#pragma once
#include <iostream>
#include <map>
#include "global_file.hpp"

class order_file {
public:
	order_file();

	void update_order();

	std::map<int, std::map<std::string, std::string>> m_order_data;

	int m_size;
};