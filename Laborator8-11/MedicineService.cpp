#include "MedicineService.h"

MedicineService::MedicineService()
{
}

MedicineService::MedicineService(Repository<Medicament>* &repoMedicamente)
{
	repoMedicament = repoMedicamente;
}

void MedicineService::add(const Medicament& m)
{
	this->repoMedicament->add(m);
}

vector<Medicament> MedicineService::getAll()
{
	return this->repoMedicament->getAll();
}

void MedicineService::update(Medicament& oldMed, Medicament& newMed)
{
	this->repoMedicament->update(oldMed, newMed);
}

void MedicineService::remove(int id)
{
	this->repoMedicament->remove(id);
}

vector<Medicament> MedicineService::search(string name)
{
	vector<Medicament> rez;
	vector <Medicament> all = repoMedicament->getAll();
	for (Medicament current : all) {
		if (current.getNume().find(name) != string::npos)
			rez.push_back(current);
	}
	return rez;
}

MedicineService::~MedicineService()
{
}
