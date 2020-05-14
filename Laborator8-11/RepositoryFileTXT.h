#pragma once
#include "RepositoryFile.h"
#include <fstream>
using namespace std;

template <class T> class RepositoryFileTXT : public RepositoryFile<T> 
{public:
	RepositoryFileTXT();
	RepositoryFileTXT(const char* fname);
	void loadFromFile();
	void saveToFile();
	~RepositoryFileTXT();

};

template<class T>
inline RepositoryFileTXT<T>::RepositoryFileTXT() 
{
}

template<class T>
inline RepositoryFileTXT<T>::RepositoryFileTXT(const char* fname): RepositoryFile <T>(fname) {}

template<class T>
inline void RepositoryFileTXT<T>::loadFromFile() 
{
	string line;
	ifstream f(RepositoryFile<T>::fileName);
	while (getline(f, line)) {
		T ob(line, ' ');
		Repository<T>::elem.push_back(ob);
	}
}

template<class T>
inline void RepositoryFileTXT<T>::saveToFile() 
{
	ofstream f(RepositoryFile<T>::fileName);
	for (T crt : Repository<T>::elem) {
		f << crt.toStringDelimiter(' ') << endl;
	}
}

template<class T>
inline RepositoryFileTXT<T>::~RepositoryFileTXT() {}
