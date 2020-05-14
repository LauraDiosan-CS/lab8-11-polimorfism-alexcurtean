#pragma once
#include <string>
#include <vector>
using namespace std;
class Angajat
{
private:
	int id;
	string nume;
	string email;
	int grad_acces;
public:
	Angajat();
	Angajat(int id, string nume, string email, int grad_acces);
	vector<string> splitLine(string linie, char delim);
	Angajat(string linie , char delimitator);
	Angajat(const Angajat& a);
	Angajat& operator=(const Angajat& a);

	int getId();
	string getNume();
	string getEmail();
	int getGradAcces();

	void setId(int id);
	void setNume(string nume);
	void setEmail(string email);
	void setGradAcces(int grad_acces);

	void afisare();
	string toString();
	string toStringDelimiter(char d);
};

