#include "student.hpp"
#include <fstream>
#include "global_file.hpp"

Student::Student() {

}

Student::Student(int id, std::string name, std::string pwd) {
	this->id = id;
	this->m_name = name;
	this->m_pwd = pwd;

	std::ifstream ifs;
	ifs.open(COMPUTER_FILE, std::ios::in);
	Computer_room c;
	while (ifs >> c.m_com_id && ifs >> c.m_max_num) {
		v_com.push_back(c);
	}
	ifs.close();
}

void Student::open_menu() {
	std::cout << "欢迎学生代表：" << this->m_name << "登录！" << std::endl;
	std::cout << "\t\t ----------------------------------\n";
	std::cout << "\t\t|                                 |\n";
	std::cout << "\t\t|          1.申请预约              |\n";
	std::cout << "\t\t|                                 |\n";
	std::cout << "\t\t|          2.查看我的预约          |\n";
	std::cout << "\t\t|                                 |\n";
	std::cout << "\t\t|          3.查看所有预约          |\n";
	std::cout << "\t\t|                                 |\n";
	std::cout << "\t\t|          4.取消预约              |\n";
	std::cout << "\t\t|                                 |\n";
	std::cout << "\t\t|          0.注销登录              |\n";
	std::cout << "\t\t|                                 |\n";
	std::cout << "\t\t ----------------------------------\n";
	std::cout << "请选择您的操作： " << std::endl;
}

void Student::apply_order() {
	
}

void Student::show_my_order() {

}

void Student::show_all_order() {

}

void Student::cancer_order() {
	
}