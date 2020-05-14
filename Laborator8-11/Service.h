#pragma once
#include "Angajat.h"
#include "Medicament.h"
#include "Repository.h"
#include "User.h"

class Service
{
protected:
	Repository<Angajat>* repoAngajat;
	Repository<Medicament>* repoMedicament;
	Repository<User>* repoUser;
public:
	Service();
	Service(Repository<Angajat>*, Repository<Medicament>*,Repository<User>*);
	bool login(string, string);
	void logout(string, string);
	
	vector<Angajat> getAngajati();
	vector<User> getUseri();
	~Service(); 
};

