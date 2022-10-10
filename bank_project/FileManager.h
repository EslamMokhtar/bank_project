#pragma once
#include "dataSourceInterface.h"
#include "fileHelper.h"
class FileManager : public DataSourceInterface {
private:
	static void addClient(Client client) {
		FilesHelper::saveClient(client);
	}
	static void addEmployee(Employee employee) {
		FilesHelper::saveEmployee("Employee.txt", "EmployeeId.txt", employee);
	}
	static void addAdmin(Admin admin) {
		FilesHelper::saveEmployee("Admin.txt", "AdminId.txt", admin);
	}
	static void getAllClients() {
		FilesHelper::getClients();
	}
	static void getAllEmployees() {
		FilesHelper::getEmployees();
	}
	static void getAllAdmins() {
		FilesHelper::getAdmins();
	}
	static void removeAllClients() {
		FilesHelper::clearFile("Clients.txt", "ClientId.txt");
	}
	static void removeAllEmployees() {
		FilesHelper::clearFile("Employee.txt", "EmployeeId.txt");
	}
	static void removeAllAdmins() {
		FilesHelper::clearFile("Admin.txt", "AdminId.txt");
	}
public:
	static void getAllData() {
		getAllClients();
		getAllEmployees();
		getAllAdmins();
	}
	static void updateClients() {
		removeAllClients();
		for (clIt = allClients.begin(); clIt != allClients.end(); clIt++) addClient(*clIt);
	}
	static void updateEmployees() {
		removeAllEmployees();
		for (eIt = allEmployees.begin(); eIt != allEmployees.end(); eIt++) addEmployee(*eIt);
	}
	static void updateAdmins() {
		removeAllAdmins();
		for (aIt = allAdmins.begin(); aIt != allAdmins.end(); aIt++) addAdmin(*aIt);
	}
};
