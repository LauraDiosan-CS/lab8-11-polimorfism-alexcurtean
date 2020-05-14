#pragma once
#include <vector>
#include <algorithm>

using namespace std;

template <class T> class Repository {
protected:
	vector<T> elem ;
public:
	void add(const T& el);
	vector <T> getAll();
	int find(T& el);
	void remove(int id);
	void update(T& el1, T& el2);
	int getSize();
};

template<class T>
inline void Repository<T>::add(const T& el)
{
	this->elem.push_back(el);
}

template<class T>
inline vector<T> Repository<T>::getAll()
{
	return this->elem;
}

template<class T>
inline int Repository<T>::find(T& el)
{
	auto it = std::find(elem.begin(), elem.end(), el);
	if (it != elem.end()) return distance(elem.begin(), it);
	return -1;
}

template<class T>
inline void Repository<T>::remove(int id)
{
	for (int i = 0; i < elem.size();i++)
		if (this->elem[i].getId() == id)
			this->elem.erase(this->elem.begin() + i);


}

template<class T>
inline void Repository<T>::update(T& el1, T& el2)
{
	replace(elem.begin(), elem.end(), el1, el2);
}

template<class T>
inline int Repository<T>::getSize()
{
	return this->elem.size();
}
