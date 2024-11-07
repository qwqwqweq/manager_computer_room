#pragma once
#include <iostream>
#include "Identity.hpp"

class Teacher: public Identity {
public:
	Teacher();
	Teacher(int emp_id, std::string name, std::string pwd);

	virtual void open_menu();
	void show_all_order();
	void valid_order();
	int enm_id;
};