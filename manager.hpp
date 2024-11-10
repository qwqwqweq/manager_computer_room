#pragma once
#include <iostream>
#include "Identity.hpp"
#include <vector>
#include "student.hpp"
#include "Teacher.hpp"
#include "computer_room.hpp"

class Manager: public Identity {
public:
	Manager();
	Manager(std::string name, std::string pwd);
	virtual void open_menu();
	void add_person();
	void show_person();
	void show_computer();
	void clean_file();
	void init_vector();

	std::vector<Student> v_stu;
	std::vector<Teacher> v_tea;

	bool check_repeat(int id, int type);

	std::vector<Computer_room> v_com;
};