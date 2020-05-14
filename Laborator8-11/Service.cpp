#include "Service.h"

Service::Service()
{
}

Service::Service(Repository<Angajat>* repoAngajati, Repository<Medicament>* repoMedicamente, Repository<User>* repoUseri)
{
	this->repoAngajat = repoAngajati;
	this->repoMedicament = repoMedicamente;
	this->repoUser = repoUseri;
}

bool Service::login(string u, string p)
{
	User u1(u, p);
	return repoUser->find(u1) != -1;
}

/*bool Service::logout(string, string)
{
	return false;
}*/

vector<Angajat> Service::getAngajati()
{
	return this->repoAngajat->getAll();
}

vector<User> Service::getUseri()
{
	return this->repoUser->getAll();
}

Service::~Service()
{
}
