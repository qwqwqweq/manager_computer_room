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
	std::cout << "机房开放时间为周一到周五!" << std::endl;
	std::cout << "请输入申请预约时间： " << std::endl;
	std::cout << "1、周一" << std::endl;
	std::cout << "2、周二" << std::endl;
	std::cout << "3、周三" << std::endl;
	std::cout << "4、周四" << std::endl;
	std::cout << "5、周五" << std::endl;

	int date = 0, interval = 0, room = 0;

	while (true) {
		std::cin >> date;
		if (date >= 1 && date <= 5) {
			break;
		}
		std::cout << "输入有误， 请重新输入" << std::endl;
	}

	std::cout << "请输入预约时间段: " << std::endl;
	std::cout << "1、上午" << std::endl;
	std::cout << "2、下午" << std::endl;

	while (true) {
		std::cin >> interval;
		if (interval >= 1 && interval <= 2) {
			break;
		}
		std::cout << "输入有误， 请重新输入" << std::endl;
	}

	std::cout << "请选择机房" << std::endl;
	std::cout << "1号机房容量: " << v_com[0].m_max_num << std::endl;
	std::cout << "2号机房容量: " << v_com[1].m_max_num << std::endl;
	std::cout << "3号机房容量: " << v_com[2].m_max_num << std::endl;

	while (true) {
		std::cin >> room;
		if (room >= 1 && room <= 3) {
			break;
		}
		std::cout << "输入有误，请重新输入" << std::endl;
	}

	std::cout << "预约成功！审核中" << std::endl;

	std::ofstream ofs(ORDER_FILE, std::ios::app);
	ofs << "date:" << date << ' ';
	ofs << "interval:" << interval << ' ';
	ofs << "stu_id:" << this->id << ' ';
	ofs << "stu_name:" << this->m_name << ' ';
	ofs << "room:" << room << ' ';
	ofs << "status:" << 1 << std::endl;

	ofs.close();

	system("cls");
}

void Student::show_my_order() {

}

void Student::show_all_order() {

}

void Student::cancer_order() {
	
}