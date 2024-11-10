#include "manager.hpp"
#include <fstream>
#include "global_file.hpp"
#include <algorithm>

Manager::Manager() {

}

Manager::Manager(std::string name, std::string pwd) {
	this->m_name = name;
	this->m_pwd = pwd;
	this->init_vector();
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
	std::string error_tip;
	if (x == 1) {
		file_name = STUDENT_FILE;
		tip = "请输入学号: ";
		error_tip = "学号重复，请重新输入";
	} else {
		file_name = TEACHER_FILE;
		tip = "请输入职工编号";
		error_tip = "职工号重复，请重新输入";
	}

	ofs.open(file_name, std::ios::out | std::ios::app);
	int id;
	std::string name, pwd;
	std::cout << tip << std::endl;
	
	while (true) {
		std::cin >> id;
		bool ret = this->check_repeat(id, x);
		if (ret)
			std::cout << error_tip << std::endl;
		else
			break;
	}

	std::cout << "请输入姓名: " << std::endl;
	std::cin >> name;

	std::cout << "请输入密码: " << std::endl;
	std::cin >> pwd;

	ofs << id << " " << name << " " << pwd << " " << std::endl;
	std::cout << "添加成功" << std::endl;

	system("cls");
	ofs.close();

	this->init_vector();
}

void print_student(Student &s) {
	std::cout << "学号： " << s.id << " 姓名: " << s.m_name << " 密码: " << s.m_pwd << std::endl;
}

void print_teacher(Teacher &t) {
	std::cout << "职工号： " << t.enm_id << " 姓名: " << t.m_name << " 密码: " << t.m_pwd << std::endl;
}

void Manager::show_person() {
	std::cout << "请选择查看内容： " << std::endl;
	std::cout << "1、查看所有学生" << std::endl;
	std::cout << "2、查看所有老师" << std::endl;
	int x = 0;
	std::cin >> x;
	if (x == 1) {
		std::cout << "所有学生信息如下: " << std::endl;
		std::for_each(v_stu.begin(), v_stu.end(), print_student);
	} else {
		std::cout << "所有 老师信息如下: " << std::endl;
		std::for_each(v_tea.begin(), v_tea.end(), print_teacher);
	}
	system("cls");
}

void Manager::show_computer() {

}

void Manager::clean_file() {
	
}

void Manager::init_vector() {
	std::ifstream ifs;
	ifs.open(STUDENT_FILE, std::ios::in);
	if (!ifs.is_open()) {
		std::cout << "文件读取失败" << std::endl;
		return;
	}

	v_stu.clear();
	v_tea.clear();
	Student s;
	while (ifs >> s.id && ifs >> s.m_name && ifs >> s.m_pwd) {
		v_stu.push_back(s);
	}

	std::cout << "当前学生的数量： " << v_stu.size() << std::endl;
	ifs.close();

	ifs.open(TEACHER_FILE, std::ios::in);

	Teacher t;
	while (ifs >> t.enm_id && ifs >> t.m_name && ifs >> t.m_pwd) {
		v_tea.push_back(t);
	} 

	std::cout << "当前老师的数量: " << v_tea.size() << std::endl;
	ifs.close();
}

bool Manager::check_repeat(int id, int type) {
	if (type == 1) {
		for (auto it = v_stu.begin(); it != v_stu.end(); it++)
			if (id == it->id)
				return true;
	} else {
		for (auto it = v_tea.begin(); it != v_tea.end(); it++)
			if (id == it->enm_id)
				return true;
	} 
	return false;
}