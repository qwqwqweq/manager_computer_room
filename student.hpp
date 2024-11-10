#pragma once
#include <iostream>
#include "Identity.hpp"
#include <vector>
#include "Computer_room.hpp"

class Student: public Identity {
public:
	Student();
	Student(int id, std::string name, std::string pwd);

	virtual void open_menu();

	void apply_order();

	void show_my_order();

	void show_all_order();

	void cancer_order();

	int id;

	std::vector<Computer_room> v_com;
};