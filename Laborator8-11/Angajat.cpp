#include "Angajat.h"
#include <iostream>
#include <sstream>
Angajat::Angajat()
{
	this->id = 0;
	this->nume = "";
	this->email = "";
	this->grad_acces = 0;
}

Angajat::Angajat(int id, string nume, string email, int grad_acces)
{
	this->id = id;
	this->nume = nume;
	this->email = email;
	this->grad_acces = grad_acces;
}

vector<string> Angajat::splitLine(string linie, char delim)
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

Angajat::Angajat(string linie, char delimitator)
{
	vector<string> tokens = splitLine(linie, delimitator);
	id = stoi(tokens[0]);

	nume = tokens[1];

	email = tokens[2];

	grad_acces = stoi(tokens[3]);
}

Angajat::Angajat(const Angajat& a)
{
	this->id = a.id;
	this->nume = a.nume;
	this->email = a.email;
	this->grad_acces = a.grad_acces;
}

Angajat& Angajat::operator=(const Angajat& a)
{
	this->setId(a.id);
	this->setNume(a.nume);
	this->setEmail(a.email);
	this->setGradAcces(a.grad_acces);
	return *this;
}

int Angajat::getId() { return this->id; }

string Angajat::getNume() { return this->nume; }

string Angajat::getEmail() { return this->email; }

int Angajat::getGradAcces() { return this->grad_acces; }

void Angajat::setId(int id) { this->id = id; }

void Angajat::setNume(string nume) { this->nume = nume;}

void Angajat::setEmail(string email) { this->email = email; }

void Angajat::setGradAcces(int grad_acces) { this->grad_acces = grad_acces; }

void Angajat::afisare() { cout << "ID: " << this->id << ", Nume: " << this->nume << ", Email: " << this->email << ", Grad acces: " << this->grad_acces; }

string Angajat::toString() { return to_string(id) + " " + nume + " " + email + " " + to_string(grad_acces); }

string Angajat::toStringDelimiter(char d)
{
	return to_string(id) + d + nume + d + email + d + to_string(grad_acces);
}
