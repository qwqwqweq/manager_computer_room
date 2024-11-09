#include "manager.hpp"

Manager::Manager() {

}

Manager::Manager(std::string name, std::string pwd) {
	this->m_name = name;
	this->m_pwd = pwd;
}

void Manager::open_menu() {
	std::cout << "欢迎管理员："<< this->m_name << "登录！" << std::endl;
	std::cout << "\t\t ---------------------------------\n";
	std::cout << "\t\t|                                |\n";
	std::cout << "\t\t|          1.添加账号            |\n";
	std::cout << "\t\t|                                |\n";
	std::cout << "\t\t|          2.查看账号            |\n";
	std::cout << "\t\t|                                |\n";
	std::cout << "\t\t|          3.查看机房            |\n";
	std::cout << "\t\t|                                |\n";
	std::cout << "\t\t|          4.清空预约            |\n";
	std::cout << "\t\t|                                |\n";
	std::cout << "\t\t|          0.注销登录            |\n";
	std::cout << "\t\t|                                |\n";
	std::cout << "\t\t ---------------------------------\n";
	std::cout << "请选择您的操作： " << std::endl;
}

void Manager::add_person() {
	std::cout << "请输入添加账号的类型" << std::endl;
	std::cout << "1、添加学生" << std::endl;
	std::cout << "2、添加老师" << std::endl;

	std::string file_name, tip;
	std::ofstream ofs;

	int x = 0;
	std::cin >> x;
	if (x == 1) {
		file_name = STUDENT_FILE;
		tip = "请输入学号: ";
	} else {
		file_name = TEACHER_FILE;
		tip = "请输入职工编号";
	}

	ofs.open(file_name, std::ios::out | std::ios::app);
	int id;
	std::string name, pwd;
	std::cout << tip << std::endl;
	std::cin >> id;

	std::cout << "请输入姓名: " << std::endl;
	std::cin >> name;

	std::cout << "请输入密码: " << std::endl;
	std::cin >> pwd;

	ofs << id << " " << name << " " << pwd << " " << std::endl;
	std::cout << "添加成功" << std::endl;

	system("cls");
	ofs.close();
}

void Manager::show_person() {

}

void Manager::show_computer() {

}

void Manager::clean_file() {
	
}