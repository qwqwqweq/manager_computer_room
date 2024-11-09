#include <iostream>
#include "global_file.hpp"
#include "identity.hpp"
#include "student.hpp"
#include "teacher.hpp"
#include "manager.hpp"
#include <fstream>
#include <cstring>

void manager_menu(Identity * &manager) {
	while (true) {
		manager->open_menu();
		Manager *man = (Manager *)manager;
		int x = 0;
		std::cin >> x;
		if (x == 1) {
			std::cout << "添加账号" << std::endl;
			man->add_person();
		} else if (x == 2) {
			std::cout << "查看账号" << std::endl;
			man->show_person();
		} else if (x == 3) {
			std::cout << "查看机房" << std::endl;
			man->show_computer();
		} else if (x == 4) {
			std::cout << "清空预约" << std::endl;
			man->clean_file();
		} else {
			delete manager;
			std::cout << "注销成功" << std::endl;
			system("cls");
			return;
		}
	}
}

void login_in(std::string file_name, int type) {
	Identity *person = nullptr;

	std::ifstream ifs;
	ifs.open(file_name, std::ios::in);
	if (!ifs.is_open()) {
		std::cout << "文件不存在" << std::endl;
		ifs.close();
		return;
	}

	int id = 0;
	std::string name, pwd;
	if (type == 1) {
		std::cout << "请输入你的学号" << std::endl;
		std::cin >> id;
	} else if (type == 2) {
		std::cout << "请输入你的职工号" << std::endl;
		std::cin >> id;
	} 
	std::cout << "请输入用户名" << std::endl;
	std::cin >> name;
	std::cout << "请输入密码" << std::endl;
	std::cin >> pwd;

	if (type == 1) {
		int fID;
		std::string fName, fPwd;
		while (ifs >> fID && ifs >> fName && ifs >> fPwd)
			if (fID == id && fName == name && fPwd == pwd) {
				std::cout << "学生验证登录成功" << std::endl;
				system("cls");
				person = new Student(id, name, pwd);
				return;
			}
	} else if (type == 2) {
		int fID;
		std::string fName, fPwd;
		while (ifs >> fID && ifs >> fName && ifs >> fPwd)
			if (fID == id && fName == name && fPwd == pwd) {
				std::cout << "教师验证登录成功" << std::endl;
				system("cls");
				person = new Teacher(id, name, pwd);
				return;
			}
	} else if (type == 3) {
		std::string f_name, f_pwd;
		while (ifs >> f_name && ifs >> f_pwd)
			if (f_pwd == pwd && f_name == name) {
				std::cout << "管理员验证登录成功" << std::endl;
				system("cls");
				person = new Manager(name, pwd);
				manager_menu(person);
				return;
			}
	}
	std::cout << "验证失败" << std::endl;
	system("cls");
}

void menu() {
	std::cout << "======================  欢迎来到机房预约系统  =====================" << std::endl;
	std::cout << std::endl << "请输入您的身份" << std::endl;
	std::cout << "\t\t -------------------------------\n";
	std::cout << "\t\t|                               |\n";
	std::cout << "\t\t|          1.学生代表           |\n";
	std::cout << "\t\t|                               |\n";
	std::cout << "\t\t|          2.老    师           |\n";
	std::cout << "\t\t|                               |\n";
	std::cout << "\t\t|          3.管 理 员           |\n";
	std::cout << "\t\t|                               |\n";
	std::cout << "\t\t|          0.退    出           |\n";
	std::cout << "\t\t|                               |\n";
	std::cout << "\t\t -------------------------------\n";
	std::cout << "输入您的选择: ";
}

int main() {

	while (true) {
		menu();

		int select;
		std::cin >> select;
		switch(select) {
		case 1: 
			login_in(STUDENT_FILE, 1);
			break;
		case 2: 
			login_in(TEACHER_FILE, 2);
			break;
		case 3: 
			login_in(ADMIN_FILE, 3);
			break;
		case 0:
			std::cout << "欢迎下次使用" << std::endl;
			exit(0);
		default:
			std::cout << "输入错误，重新选择" << std::endl;
			system("cls");
		 	break;
		}
	}

	return 0;
}