#include "order_file.hpp"
#include <fstream>
#include "global_file.hpp"

order_file::order_file() {
	std::ifstream ifs;
	ifs.open(ORDER_FILE, std::ios::in);
	std::string date;
	std::string interval;
	std::string stu_id;
	std::string stu_name;
	std::string room_id;
	std::string status;

	this->m_size = 0;

	while (ifs >> date && ifs >> interval && ifs >> stu_id && ifs >> stu_name && ifs >> room_id && ifs >> status) {
		std::string key;
		std::string value;

		std::map<std::string, std::string> m;

		int pos = date.find(":");
		if (pos != -1) {
			key = date.substr(0, pos);
			value = date.substr(pos + 1, date.size() - pos - 1);
			m.insert(make_pair(key, value));
		}

		pos = interval.find(":");
		if (pos != -1) {
			key = interval.substr(0, pos);
			value = interval.substr(pos + 1, interval.size() - pos - 1);
			m.insert(make_pair(key, value));
		}

		pos = stu_name.find(":");
		if (pos != -1) {
			key = stu_name.substr(0, pos);
			value = stu_name.substr(pos + 1, stu_name.size() - pos - 1);
			m.insert(make_pair(key, value));
		}

		pos = room_id.find(":");
		if (pos != -1) {
			key = room_id.substr(0, pos);
			value = room_id.substr(pos + 1, room_id.size() - pos - 1);
			m.insert(make_pair(key, value));
		}

		pos = status.find(":");
		if (pos != -1) {
			key = status.substr(0, pos);
			value = status.substr(pos + 1, status.size() - pos - 1);
			m.insert(make_pair(key, value));
		}

		this->m_order_data.insert(make_pair(this->m_size, m));
		this->m_size++;
	}
	ifs.close();
}

void order_file::update_order() {
	if (!this->m_size)
		return;

	std::ofstream ofs(ORDER_FILE, std::ios::out | std::ios::trunc);
	for (int i = 0; i < this->m_size; i++) {
		ofs << "date:" << this->m_order_data[i]["date"] << ' ';
		ofs << "interval:" << this->m_order_data[i]["interval"] << ' ';
		ofs << "stu_id:" << this->m_order_data[i]["stu_id"] << ' ';
		ofs << "stu_name:" << this->m_order_data[i]["stu_name"] << ' ';
		ofs << "room_id:" << this->m_order_data[i]["room_id"] << ' ';
		ofs << "status:" << this->m_order_data[i]["status"] << std::endl;
	}
	ofs.close();
}