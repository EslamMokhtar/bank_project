#pragma once
#include <sstream>
#include "Admin.h"

class Parser {
private:
	static vector<string> split(string line) {
		stringstream stream(line);
		string token;
		vector<string> info;
		while (getline(stream, token, ';')) info.push_back(token);
		return info;
	}
public:
	static Client parseToClient(string line) {
		vector<string> info = split(line);
		Client client;
		client.setId(stoi(info[0]));
		client.setName(info[1]);
		client.setPassword(info[2]);
		client.setBalance(stod(info[3]));
		return client;
	}
	static Employee parseToEmployee(string line) {
		vector<string> info = split(line);
		Employee employee;
		employee.setId(stoi(info[0]));
		employee.setName(info[1]);
		employee.setPassword(info[2]);
		employee.setSalary(stod(info[3]));
		return employee;
	}
	static Admin parseToAdmin(string line) {
		vector<string> info = split(line);
		Admin admin;
		admin.setId(stoi(info[0]));
		admin.setName(info[1]);
		admin.setPassword(info[2]);
		admin.setSalary(stod(info[3]));
		return admin;
	}
};