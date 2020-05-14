#include "Medicament.h"
#include <iostream>
#include <sstream>

using namespace std;

Medicament::Medicament()
{
	this->id = 0;
	this->nume = "";
	this->necesita_reteta = false;
	this->nr_stoc = 0;
	this->producator = "";
}

Medicament::Medicament(int id, string nume, bool necesita_reteta, int nr_stoc, string producator)
{
	this->id = id;
	this->nume = nume;
	this->necesita_reteta = necesita_reteta;
	this->nr_stoc = nr_stoc;
	this->producator = producator;
}

/* creeaza un vector cu obiecte de tip string(atributele unui obiect)
in urma citirii din fisier*/
vector<string> Medicament::splitLine(string linie, char delim)
{
	stringstream ss(linie);
	string item;
	vector<string> elem;
	while (getline(ss, item, delim)) 
	{
		elem.push_back(item);
	}
	return elem;
	
}

/*creeaza un obiect de tip medicament prin delimitarea parametrilor
obicetului, atunci cand este citit dintr-o linie dintr-un fisier
input: linie: string, linia pe care se afla atributele obiectului
	   delim: char, delimitatorul specific fiecarui tip de fisier*/
Medicament::Medicament(string linie,const char delimitator)

{
	vector<string> tokens = splitLine(linie, delimitator);
	id = stoi(tokens[0]);

	nume = tokens[1];

	necesita_reteta = (tokens[2] == "1");
	nr_stoc = stoi(tokens[3]);

	producator = tokens[4];
}

Medicament::Medicament(const Medicament& m)
{
	this->id = m.id;
	this->nume = m.nume;
	this->necesita_reteta = m.necesita_reteta;
	this->nr_stoc = m.nr_stoc;
	this->producator = m.producator;
}

int Medicament::getId() { return this->id; }

string Medicament::getNume() { return this->nume; }

bool Medicament::getNecesitaReteta() { return this->necesita_reteta; }

int Medicament::getNrStoc() { return this->nr_stoc; }

string Medicament::getProducator() { return this->producator; }

void Medicament::setId(int id) { this->id = id; }

void Medicament::setNume(string nume) { this->nume = nume; }

void Medicament::setNecesitaReteta(bool necesita_reteta) { this->necesita_reteta = necesita_reteta; }

void Medicament::setNrStoc(int nr_stoc) { this->nr_stoc = nr_stoc; }

void Medicament::setProducator(string producator) { this->producator = producator; }

bool Medicament::operator==(const Medicament& m)
{
	return (this->id == m.id && this->nume == m.nume && this->necesita_reteta == m.necesita_reteta && this->nr_stoc == m.nr_stoc && this->producator == m.producator);
}

bool Medicament::operator!=(const Medicament& m)
{
	return (id != m.id || nume != m.nume || necesita_reteta != m.necesita_reteta || nr_stoc != m.nr_stoc || producator != m.producator);
}

string Medicament::toString()
{
	return to_string(id) + " " + nume + " " + to_string(necesita_reteta) + " " + to_string(nr_stoc) + " " + producator;
}

string Medicament::toStringDelimiter(char d)
{
	return to_string(id) + d + nume + d + to_string(necesita_reteta) + d + to_string(nr_stoc) + d + producator;
}
