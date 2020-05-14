#pragma once
#include "Repository.h"

template <class T> class RepositoryFile : public Repository<T> {
protected:
	const char* fileName;
public:
	RepositoryFile();
	RepositoryFile(const char* name);
	virtual void saveToFile();
	virtual void loadFromFile();
	~RepositoryFile();
};

template<class T>
inline RepositoryFile<T>::RepositoryFile() : Repository<T>()
{
}

template<class T>
inline RepositoryFile<T>::RepositoryFile(const char* name)
{
	this->fileName = name;
}

template<class T>
inline void RepositoryFile<T>::saveToFile()
{
}

template<class T>
inline void RepositoryFile<T>::loadFromFile()
{
}

template<class T>
inline RepositoryFile<T>::~RepositoryFile()
{
}

