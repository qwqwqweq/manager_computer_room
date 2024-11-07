#include <iostream>
#include <iomanip>

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
			break;
		case 2: 
			break;
		case 3: 
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