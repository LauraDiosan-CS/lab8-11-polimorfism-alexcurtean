#include "Test.h"
#include "Angajat.h"
#include "Medicament.h"
#include <assert.h>
#include <iostream>
#include "Repository.h"
#include "RepositoryFileTXT.h"
#include "RepositoryFileCSV.h"
#include "User.h"
#include "Service.h"
#include "MedicineService.h"

void runTests() 
{
	testClassAngajat();
	testClassMedicament();
	testLiveRepo();
	testRepoCSV();
	testRepoTXT();
	testClassUser();
	testService();
	testLiveService();

}

void testClassAngajat()
{
	Angajat a1;
	assert(a1.getId() == 0);
	assert(a1.getNume() == "");
	a1.setNume("Pop");
	assert(a1.getNume() == "Pop");

	Angajat a2(1, "Mihai", "mihai32@yahoo.com", 1);
	assert(a2.getId() == 1);
	assert(a2.getNume() == "Mihai");
	assert(a2.getEmail() == "mihai32@yahoo.com");
	assert(a2.getGradAcces() == 1);

	a2.setGradAcces(4);
	assert(a2.getGradAcces() == 4);

	Angajat a3 = a2;
	a3.setNume("Vlad");
	assert(a3.getId() == 1);
	assert(a3.getNume() == "Vlad");

	cout << "Angajat class asserts verified..." << endl;

}

void testClassMedicament()
{
	Medicament m1;
	assert(m1.getNume() == "");
	assert(m1.getNrStoc() == 0);
	m1.setNrStoc(75);
	assert(m1.getNrStoc() == 75);

	Medicament m2(1, "Ketonal", true, 120, "p1");
	assert(m2.getNecesitaReteta() == true);
	assert(m2.getId() == 1);
	assert(m2.getNume() == "Ketonal");
	assert(m2.getNrStoc() == 120);
	assert(m2.getProducator() == "p1");

	m2.setNecesitaReteta(false);
	m2.setProducator("p3");

	Medicament m3 = m2;
	assert(m3.getNecesitaReteta() == false);
	assert(m3.getProducator() == "p3");
	assert(m3.getNrStoc() == 120);

	cout << "Medicament class asserts verified..." << endl;

}

void testRepoCSV()
{
	const char* fileName = "Medicamente.csv";

	RepositoryFile<Medicament>* repo = new RepositoryFileCSV<Medicament>(fileName);
	((RepositoryFileCSV<Medicament>*)repo)->loadFromFile();
	assert(repo->getSize() == 4);

	Medicament m(47, "plasture", 1, 39, "abc");
	Medicament m1(47, "plasture", 0, 45, "abc");
	repo->add(m);
	assert(repo->getSize() == 5);

	//repo->update(m, m1);
	//assert(m.getStoc() == 39);

	repo->remove(47);
	assert(repo->getSize() == 4);

	cout << "RepoCSV asserts verified... " << endl;
}

void testRepoTXT()
{
	const char* fileName = "Angajati.txt";
	RepositoryFile<Angajat>* repo = new RepositoryFileTXT<Angajat>(fileName);
	((RepositoryFile<Angajat>*)repo)->loadFromFile();
	assert(repo->getSize() == 4);

	cout << "RepoTXT asserts verified..." << endl;
}

void testLiveRepo()
{
	Repository<Medicament>* repo = new RepositoryFileTXT<Medicament>();
	Medicament m1 = Medicament(100, "parasinus", false, 10, "p1");
	Medicament m2 = Medicament(200, "ketonal", false, 90, "p2");
	Medicament m3 = Medicament(300, "antibiotic", true, 70, "p3");

	repo->add(m1);
	repo->add(m2);
	assert(repo->getAll().size() == 2);

	assert(repo->getAll()[0] == m1);
	assert(repo->getAll()[1] == m2);
	repo->add(m3);
	assert(repo->getAll()[2] == m3);

	Medicament m1_new(100, "paracetamol", false, 50, "p1");
	repo->update(m1, m1_new);
	assert(repo->getAll()[0] != m1);
	assert(repo->getAll()[0] == m1_new);

	repo->remove(200);
	assert(repo->getAll().size() == 2);

	cout << "Repo asserts verified..." << endl;
}

void testClassUser()
{
	User u1;
	assert(u1.getPassword() == "");
	assert(u1.getUserName() == "");
	u1.setPassword("pass1");
	
	assert(u1.getPassword() == "pass1");

	cout << "User class asserts verified..." << endl;
}

void testService()
{
	Repository <User>* repoU = new Repository<User>();
	Repository <Medicament>* repoM = new Repository<Medicament>();
	Repository <Angajat>* repoA = new Repository<Angajat>();
	User u1("Alex", "1234");
	User u2("u2", "pass2");
	repoU->add(u1);
	repoU->add(u2);
	assert(repoU->getSize() == 2);

	Service* s = new Service(repoA, repoM, repoU);
	
	assert(s->login("u2", "pass2") == true);
	assert(s->login("m1", "pass3") == false);

	cout << "Service class asserts verified..." << endl;
}

void testLiveService()
{
	Repository<Medicament>* repository = new Repository<Medicament>();
	//repoM = new RepositoryFileTXT<Medicament>();
	
	MedicineService* service = new MedicineService{ repository };
	Medicament m1 =  Medicament(100, "parasinus", false, 10, "p1");
	Medicament m2 =  Medicament(200, "ketonal", false, 90, "p2");
	Medicament m3 =  Medicament(300, "antibiotic", true, 70, "p3");

	service->add(m1);
	service->add(m2);
	assert(service->getAll().size() == 2);
	assert(service->getAll()[0] == m1);
	assert(service->getAll()[1] == m2);
	service->add(m3);
	assert(service->getAll()[2] == m3);

	assert(service->search("ic").size() == 1);
	assert(service->search("a").size() == 3);

	Medicament m1_new(100, "altceva", false, 50, "p1");
	service->update(m1, m1_new);
	assert(service->search("al").size() == 2);
	assert(service->search("al")[0] == m1_new);
	assert(service->search("al")[1] == m2);
	service->remove(200);
	assert(service->search("al").size() == 1);
	assert(service->search("al")[0] == m1_new);

	cout << "Service Live asserts verified..." << endl;

}
