#pragma once
#include <iostream>
#include "Identity.hpp"

class Manager: public Identity {
	std::string m_name, m_pwd;
public:
	Manager();
	Manager(std::string name, std::string pwd);
	virtual void open_menu();
	void add_person();
	void show_person();
	void show_computer();
	void clean_file();
};