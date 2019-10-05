#include "Repo.h"

void Repo::Add(Car el)
{
	if (Find(el) == true)
		throw exception("Existing element!\n");
	list.push_back(el);
}

void Repo::Delete(Car el)
{
	if (Find(el) == false)
		throw exception("Inexisting element!\n");

	vector<Car> ::iterator it = find(list.begin(), list.end(), el);
	list.erase(it);
}

bool Repo::Find(Car el)
{
	for (unsigned int i = 0; i < list.size(); i++)
	{
		if (list.at(i) == el)
			return true;
	}
	return false;
}

Car* Repo::Search(Car el)
{
	for (unsigned int i = 0; i < list.size(); i++)
	{
		if (list.at(i) == el)
			return &list.at(i);
	}
	throw exception("Inexisting element");
}

void Repo::Update(Car el, Car new_el)
{
	Car* p = Search(el);

	if (p == nullptr)
		throw exception("Error");

	(*p).SetModel(new_el.Getmodel());
	(*p).SetnrRegister(new_el.GetnrRegister());
	(*p).SetProducer(new_el.GetProducer());
	(*p).SetType(new_el.GetType());
}

vector<Car> Repo::Get_all()
{
	return list;
}


void TestRepo::TestAdd()
{
	string s = "1";
	repo.Add(Car(1,s,s,s));
	Car t = Car(1, s, s, s);
	assert((*repo.Search(t)).GetnrRegister() == 1);

	try
	{
		repo.Add(Car(1, s, s, s));
		assert(false);
	}
	catch (exception)
	{
		assert(true);
	}
}

void TestRepo::TestDelete()
{
	string s = "1";
	repo.Delete(Car(1, s, s, s));
	vector<Car> p = repo.Get_all();
	assert(p.size() == 0);
	try
	{
		repo.Delete(Car(1, s, s, s));
		assert(false);
	}
	catch (exception)
	{
		assert(true);
	}
}

void TestRepo::TestSearch()
{
	string s = "1";

	repo.Add(Car(3, s, s, s));
	repo.Add(Car(1, s, s, s));

	Car q = Car(1, s, s, s);

	const Car* p = repo.Search(q);

	if (p == nullptr)
		throw exception("error");

	assert((*p).GetnrRegister() == 1);
	try
	{
		Car b = Car(2, s, s, s);
		repo.Search(b);
		assert(false);
	}
	catch (exception)
	{
		assert(true);
	}
}

void TestRepo::TestUpdate()
{
	string s = "1";
	repo.Update(Car(1, s, s, s), Car(2, s, s, s));
	Car t = Car(2, s, s, s);
	repo.Search(t);

	try
	{
		Car v = Car(1, s, s, s);
		repo.Update(v, t);
		assert(false);
	}
	catch (exception)
	{
		assert(true);
	}
}

void TestRepo::Run()
{
	TestAdd();
	TestDelete();
	TestSearch();
	TestUpdate();
}
