#pragma once
#include "RepositoryFile.h"
#include <fstream>
using namespace std;

template <class T> class RepositoryFileCSV : public RepositoryFile<T> 
{
public:
	RepositoryFileCSV();
	RepositoryFileCSV(const char* fname);
	void loadFromFile();
	void saveToFile();
	~RepositoryFileCSV();
};

template<class T>
inline RepositoryFileCSV<T>::RepositoryFileCSV()
{
}

template<class T>
inline RepositoryFileCSV<T>::RepositoryFileCSV(const char* fname): RepositoryFile<T>(fname) 
{
}

template<class T>
inline void RepositoryFileCSV<T>::loadFromFile()
{
	string linie;
	ifstream f(RepositoryFile<T>::fileName);
	while (getline(f, linie)) {
		T ob(linie, ',');
		Repository<T>::elem.push_back(ob);
	}

}

template<class T>
inline void RepositoryFileCSV<T>::saveToFile()
{
	ofstream f(RepositoryFile<T>::fileName);
	for (T crt : Repository<T>::elem) {
		f << crt.toStringDelimiter(',') << endl;
	}
}

template<class T>
inline RepositoryFileCSV<T>::~RepositoryFileCSV()
{
}
