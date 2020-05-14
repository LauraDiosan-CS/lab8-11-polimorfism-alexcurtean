#pragma once
#include <string>
#include <vector>
using namespace std;

class User
{
private:
	string userName;
	string password;
public:
	User();
	User(string name, string pass);
	vector<string> splitLine(string linie, char delim);
	User(string linie, char delimitator);
	string getUserName();
	string getPassword();
	void setUserName(string name);
	void setPassword(string pass);
	bool operator==(const User& u);
	string toString();
	string toStringDelimiter(char delimiter);
	//~User();
};

