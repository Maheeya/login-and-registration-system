#include <iostream>
#include <fstream>
#include <list>
#include <string>
using namespace std;

void registerUser(string name, string user, string pass) {
	ofstream myfile;
	myfile.open("Account.txt", ios::app | ios::ate);
	string accountInfo[3]{ name, user, pass };
	myfile << user << '\n';
	myfile << pass << '\n';

}

void checkPass(string password, int lineNum) {
	ifstream file;
	file.open("Account.txt");
	int pos = 0;
	bool check = false;
	int line = lineNum + 1;
	string checkPass;
	while (pos < lineNum) {
		string read;
		getline(file, read, '\n');
		if (read == password) {
			check = true;
		}
		pos = pos + 1;
	}
	if (check == true) {
		cout << "login details correct \n";
	}
	else {
		cout << "password entered is incorrect \n";
	}
}


void checkUser(string user, string password) {
	ifstream indata;
	indata.open("Account.txt");
	int lineNum = 0;
	bool check = false;
	string checkUser;
	while (getline(indata, checkUser, '\n')) {
		lineNum += 1;
		if (checkUser == checkUser) {
			check = true;
		}
		checkUser = "";
	}
	if (check == true) {
		checkPass(password, lineNum);
	}
	else {
		cout << "incorrect username \n";
	}
	indata.close();
}


int main()
{
	bool repeat = true;
	while (repeat == true){
		cout << "1 : register a new user\n";
		cout << "2 : login to an existing account\n";
		cout << "Please select a number to register or login: ";
		int choice;
		std::cin >> choice;
		if (choice == 1)
		{
			cout << "enter your name: ";
			string newName;
			std::cin >> newName;

			cout << "enter your username: ";
			string newUser;
			std::cin >> newUser;

			cout << "enter your password: ";
			string newPass;
			std::cin >> newPass;

			registerUser(newName, newUser, newPass);
		}
		if (choice == 2)
		{
			cout << "enter your username: ";
			string user;
			std::cin >> user;

			cout << "enter your password: ";
			string password;
			std::cin >> password;

			checkUser(user, password);
		}
		if (choice != 1 and choice != 2) {
			cout << "must select a number 1 or 2 \n";
		}

		cout << "please enter / to go back to selection screen or enter any character to exit";
		string goBack;
		std::cin >> goBack;
		if (goBack == "/") {
			repeat = true;
		}
		else {
			repeat = false;
		}
	}
	
}

