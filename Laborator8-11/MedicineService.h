#pragma once
#include "Repository.h"
#include "Medicament.h"
#include "Service.h"

class MedicineService :public Service
{

public:
	MedicineService();
	MedicineService(Repository<Medicament>* &repoMedicamente);
	void add(const Medicament& );
	vector<Medicament> getAll();
	void update(Medicament& , Medicament& );
	void remove(int id);
	vector <Medicament> search(string name);
	~MedicineService();
};

