#include <iostream>
#include "validation.h"
using namespace std;

class Person {
protected:
	int id;
	string name, password;
public:

	Person() {
		this->id = 0;
		this->name = " ";
		this->password = " ";
	}
	Person(string name, int id, string password) {
		this->name = name;
		this->id = id;
		this->password = password;
	}


	void setName(string name) {
		if (Validation::ValidateName(name)) {
			this->name = name;
		}
	}
	void setPassword(string password) {
		if (Validation::ValidatePassword(password)) {
			Person::password = password;
		}
	}
	void setId(int id) {
		this->id = id;
	}

	string getName()
	{
		return this->name;
	}
	string getPassword()
	{
		return this->password;
	}
	int getId()
	{
		return this->id;
	}


	void display() {
		cout << "ID : " << this->id << endl;
		cout << "Name : " << this->name << endl;
		cout << "Password : " << this->password << endl;
	}
};