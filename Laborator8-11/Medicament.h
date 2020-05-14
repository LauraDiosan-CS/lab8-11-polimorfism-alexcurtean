#pragma once
#include <string>
#include <vector>
using namespace std;

class Medicament
{
private:
	int id;
	string nume;
	bool necesita_reteta;
	int nr_stoc;
	string producator;

public:
	Medicament();
	Medicament(int id, string nume, bool necesita_reteta, int nr_stoc, string producator);
	vector <string> splitLine(string linie, char delim);
	Medicament(string linie,const char delimitator);
	Medicament(const Medicament& m);
	
	int getId();
	string getNume();
	bool getNecesitaReteta();
	int getNrStoc();
	string getProducator();

	void setId(int id);
	void setNume(string nume);
	void setNecesitaReteta(bool necesita_reteta);
	void setNrStoc(int nr_stoc);
	void setProducator(string producator);

	bool operator==(const Medicament& m);
	bool operator !=(const Medicament& m);

	string toString();
	string toStringDelimiter(char d);

};

