#include "User.h"
#include <sstream>
#include <iostream>
User::User()
{
	this->userName = "";
	this->password = "";
}

User::User(string name, string pass)
{
	this->userName = name;
	this->password = pass;
}

vector<string> User::splitLine(string linie, char delim)
{
	stringstream ss(linie);
	string item;
	vector<string> elems;
	while (getline(ss, item, delim))
	{
		elems.push_back(item);
	}
	return elems;
}

User::User(string linie, char delimitator)
{
	vector<string> tokens = splitLine(linie, delimitator);
	userName = tokens[0];
	password = tokens[1];
}

string User::getUserName() { return this->userName; }

string User::getPassword() { return this->password; }

void User::setUserName(string name) { this->userName = name; }

void User::setPassword(string pass) { this->password = pass; }

bool User::operator==(const User& u) { return (this->userName == u.userName && this->password == u.password); }

string User::toString() { return userName + " " + password; }

string User::toStringDelimiter(char delimiter) { return userName + delimiter + password; }
