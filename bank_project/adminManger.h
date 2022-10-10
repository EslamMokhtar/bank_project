#pragma once
#include "employeeManger.h"
class AdminManger
{
	static void printAdminMenu() {
		system("cls");
		cout << "1-Display my info" << endl;
		cout << "2-Update Password" << endl;
		cout << "3-Add new client" << endl;
		cout << "4-Search for client" << endl;
		cout << "5-List all clients" << endl;
		cout << "6-Edit client info" << endl;
		cout << "7-Add new Employee" << endl;
		cout << "8-Search for Employee" << endl;
		cout << "9-List all Employees" << endl;
		cout << "10-Edit Employee info" << endl;
		cout << "11-Logout\n" << endl;
	}
	static void back(Admin* admin) {
		cout << endl;
		system("pause");
		adminOptions(admin);
	}
public:
	static Admin* login(int id, string password) {
		for (aIt = allAdmins.begin(); aIt != allAdmins.end(); aIt++) {
			if (aIt->getId() == id && aIt->getPassword() == password) return aIt._Ptr;
		}
		return NULL;
	}
	static bool adminOptions(Admin* admin) {
		printAdminMenu();
		string name, password;
		double salary;
		cout << "Your choice is: ";
		Employee e;
		int choice, id;
		cin >> choice;
		switch (choice) {
		case 1:
			system("cls");
			admin->display();
			break;
		case 2:
			ClientManager::updatePassword(admin);
			FileManager::updateAdmins();
			break;
		case 3:
			EmployeeManger::newClient(admin);
			break;
		case 4:
			EmployeeManger::searchForClient(admin);
			break;
		case 5:
			EmployeeManger::listAllClients(admin);
			break;
		case 6:
			EmployeeManger::editClientInfo(admin);
			break;
		case 7:
			cout << "Name : ";
			cin >> name;
			cout << "Password : ";
			cin >> password;
			cout << "Salary : ";
			cin >> salary;
			e.setName(name);
			e.setPassword(password);
			e.setSalary(salary);
			e.setId(FilesHelper::getLast("EmployeeId.txt") + 1);
			admin->addEmployee(e);
			FileManager::updateEmployees();
			cout << "\nEmployee added successfully.\n";
			break;
		case 8:
			system("cls");
			cout << "Enter employee id: ";
			cin >> id;
			if (admin->searchEmployee(id) == NULL) cout << "\nEmployee not found.\n";
			else admin->searchEmployee(id)->display();
			break;
		case 9:
			system("cls");
			cout << "All employees: \n" << endl;
			admin->listEmployee();
			break;
		case 10:
			system("cls");
			cout << "Enter employee id: ";
			cin >> id;
			if (admin->searchEmployee(id) == NULL) cout << "\nEmployee not found.\n";
			else {
				string name;
				string  password;
				double salary;
				cout << "Name : ";
				cin >> name;
				cout << "Password : ";
				cin >> password;
				cout << "Salary : ";
				cin >> salary;
				admin->editEmployee(id, name, password, salary);
				FileManager::updateEmployees();
				cout << "\nEmployee info updated.\n";
			}
			break;
		case 11:
			return false;
			break;
		default:
			system("cls");
			adminOptions(admin);
			return true;
		}
		back(admin);
		return true;
	}


};
