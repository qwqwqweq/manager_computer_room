#include "teacher.hpp"
#include "order_file.hpp"
#include <vector>

Teacher::Teacher() {

}

Teacher::Teacher(int emp_id, std::string name, std::string pwd) {
    this->enm_id = emp_id;
    this->m_name = name;
    this->m_pwd = pwd;
}

void Teacher::open_menu() {
    std::cout << "欢迎教师：" << this->m_name << "登录！" << std::endl;
	std::cout << "\t\t ----------------------------------\n";
	std::cout << "\t\t|                                  |\n";
	std::cout << "\t\t|          1.查看所有预约          |\n";
	std::cout << "\t\t|                                  |\n";
	std::cout << "\t\t|          2.审核预约              |\n";
	std::cout << "\t\t|                                  |\n";
	std::cout << "\t\t|          0.注销登录              |\n";
	std::cout << "\t\t|                                  |\n";
	std::cout << "\t\t ----------------------------------\n";
	std::cout << "请选择您的操作： " << std::endl;
}

void Teacher::show_all_order() {
    order_file of;
    if (!of.m_size) {
        std::cout << "无预约记录" << std::endl;
        system("cls");
        return;
    }
    for (int i = 0; i < of.m_size; i++) {
        std::cout << i + 1 << "、 ";
		std::cout << "预约日期： 周" << of.m_order_data[i]["date"];
		std::cout << " 时段: " << (of.m_order_data[i]["intreval"] == "1" ? "上午" : "下午");
		std::cout << " 学号： " << of.m_order_data[i]["stu_id"];
		std::cout << " 姓名： " << of.m_order_data[i]["stu_name"];
		std::cout << " 机房: " << of.m_order_data[i]["room_id"];
        std::string status = " 状态: ";
		if (of.m_order_data[i]["status"] == "1")
			status += "审核中";
		else if (of.m_order_data[i]["status"] == "2")
			status += "预约成功";
		else if (of.m_order_data[i]["status"] == "-1")
			status += "审核未通过，预约失败";
		else 
			status += "预约已取消";
		std::cout << status << std::endl;
    }
    system("cls");
}

void Teacher::valid_order() {
	order_file of;
    if (!of.m_size) {
        std::cout << "无预约记录" << std::endl;
        system("cls");
        return;
    }
    std::cout << "待审核预约记录如下: " << std::endl;
    std::vector<int> v;
    int idx = 0;
    for (int i = 0; i < of.m_size; i++)
        if (of.m_order_data[i]["status"] == "1") {
            v.push_back(i);
            std::cout << ++idx << std::endl;
            std::cout << "预约日期： 周" << of.m_order_data[i]["date"];
            std::cout << " 时段: " << (of.m_order_data[i]["intreval"] == "1" ? "上午" : "下午");
            std::cout << " 机房: " << of.m_order_data[i]["room_id"];
		    std::string status = " 状态: ";
		    if (of.m_order_data[i]["status"] == "1")
			    status += "审核中";
            std::cout << status << std::endl;
        }
    std::cout << "请输入审核的预约记录，0代表返回" << std::endl;
    int x = 0, ret = 0;
    while (true) {
        std::cin >> x;
        if (x >= 0 && x <= v.size()) {
            if (!x)
                break;
            else {
                std::cout << "请输入审核结果" << std::endl;
                std::cout << "1、通过" << std::endl << "2、不通过" << std::endl;
                std::cin >> ret;
                if (ret == 1)
                    of.m_order_data[v[x - 1]]["status"] = "2";
                else 
                    of.m_order_data[v[x - 1]]["status"] = "-1";
                of.update_order();
                std::cout << "审核完毕" << std::endl;
                break;
            }
        }
        std::cout << "输入有误，请重新输入" << std::endl;
    }
    system("cls");
}