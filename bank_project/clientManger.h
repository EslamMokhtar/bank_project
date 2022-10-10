#pragma once
#include "FileManager.h"
#include "Validation.h"

class ClientManager {
private:
	static void printClientMenu() {
		system("cls");
		cout << "1-Display my info" << endl;
		cout << "2-Check balance" << endl;
		cout << "3-Update Password" << endl;
		cout << "4-Withdraw" << endl;
		cout << "5-Deposit" << endl;
		cout << "6-Transfer amount" << endl;
		cout << "7-Logout\n" << endl;
	}
	static void back(Client* client) {
		cout << endl;
		system("pause");
		clientOptions(client);
	}
public:
	static void updatePassword(Person* person) {
		string password;
		cout << "Enter Password : ";
		cin >> password;
		if (Validation::ValidatePassword(password)) {
			person->setPassword(password);
			cout << "\nPassword updated.\n";
		}
		else
		{
			updatePassword(person);
		}
	}
	static Client* login(int id, string password) {
		for (clIt = allClients.begin(); clIt != allClients.end(); clIt++) {
			if (clIt->getId() == id && clIt->getPassword() == password) return clIt._Ptr;
		}
		return NULL;
	}
	static bool clientOptions(Client* client) {
		printClientMenu();
		cout << "Your choice is: ";
		Employee e;
		double amount;
		int n, id;
		cin >> n;
		switch (n) {
		case 1:
			system("cls");
			client->display();
			break;
		case 2:
			system("cls");
			client->checkBalance();
			break;
		case 3:
			updatePassword(client);
			FileManager::updateClients();
			break;
		case 4:
			system("cls");
			cout << "Enter amount to withdraw: ";
			cin >> amount;
			client->withdraw(amount);
			FileManager::updateClients();
			break;
		case 5:
			system("cls");
			cout << "Enter amount to deposit: ";
			cin >> amount;
			client->deposit(amount);
			FileManager::updateClients();
			break;
		case 6:
			system("cls");
			cout << "Enter ID : ";
			cin >> id;
			while (e.searchClient(id) == NULL) {
				cout << "Invalid id.\n";
				cout << "\nEnter ID : ";
				cin >> id;
			}
			cout << "\nEnter amount to transfer: ";
			cin >> amount;
			client->transferTo(amount, *e.searchClient(id));
			FileManager::updateClients();
			break;
		case 7:
			return false;
			break;
		default:
			system("cls");
			clientOptions(client);
			return true;
		}
		back(client);
		return true;
	}
};