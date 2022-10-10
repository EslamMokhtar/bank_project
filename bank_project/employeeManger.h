#pragma once
#include "clientManger.h"
class EmployeeManger
{
private:
	static void printEmployeeMenu() {
		system("cls");
		cout << "1-Display my info" << endl;
		cout << "2-Update Password" << endl;
		cout << "3-Add new client" << endl;
		cout << "4-Search for client" << endl;
		cout << "5-List all clients" << endl;
		cout << "6-Edit client info" << endl;
		cout << "7-Logout\n" << endl;
	}
	static void back(Employee* e) {
		cout << endl;
		system("pause");
		employeeOptions(e);
	}

public:
	static void newClient(Employee* employee) {
		string name, password;
		double balance;
		cout << "Name : ";
		cin >> name;
		cout << "Password : ";
		cin >> password;
		cout << "Balance : ";
		cin >> balance;
		Client client;
		client.setId(FilesHelper::getLast("ClientId.txt") + 1);
		client.setName(name);
		client.setPassword(password);
		client.setBalance(balance);
		employee->addClient(client);
		FileManager::updateClients();
		cout << "\nClient added successfully.\n";
	}
	static void searchForClient(Employee* employee) {
		int id;
		system("cls");
		cout << "Enter client id: ";
		cin >> id;
		if (employee->searchClient(id) == NULL) cout << "\nClient not found.\n";
		else employee->searchClient(id)->display();
	}
	static void listAllClients(Employee* employee) {
		system("cls");
		cout << "All clients: \n" << endl;
		employee->listClient();
	}
	static void editClientInfo(Employee* employee) {
		int id;
		system("cls");
		cout << "Enter client id: ";
		cin >> id;
		if (employee->searchClient(id) == NULL) cout << "\nClient not found.\n";
		else {
			string name, password;
			double balance;
			cout << "Name : ";
			cin >> name;
			cout << "Password : ";
			cin >> password;
			cout << "Balance : ";
			cin >> balance;
			employee->editClient(id, name, password, balance);
			FileManager::updateClients();
			cout << "\nClient info updated.\n";
		}
	}
	static Employee* login(int id, string password) {
		for (eIt = allEmployees.begin(); eIt != allEmployees.end(); eIt++) {
			if (eIt->getId() == id && eIt->getPassword() == password) return eIt._Ptr;
		}
		return NULL;
	}
	static bool employeeOptions(Employee* employee) {
		printEmployeeMenu();
		cout << "Your choice is: ";
		int choice;
		cin >> choice;
		switch (choice) {
		case 1:
			system("cls");
			employee->display();
			break;
		case 2:
			ClientManager::updatePassword(employee);
			FileManager::updateEmployees();
			break;
		case 3:
			newClient(employee);
			break;
		case 4:
			searchForClient(employee);
			break;
		case 5:
			listAllClients(employee);
			break;
		case 6:
			editClientInfo(employee);
			break;
		case 7:
			return false;
			break;
		default:
			system("cls");
			employeeOptions(employee);
			return true;
		}
		back(employee);
		return true;
	}


};