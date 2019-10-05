#include "Service.h"


void Service::Add(int Register, string producer, string model, string type)
{
	Car el = Car(Register, producer, model, type);
	repo.Add(el);
}

void Service::Delete(int Register, string producer, string model, string type)
{
	Car el = Car(Register, producer, model, type);
	repo.Delete(el);
}

void Service::Update(int Register, string producer, string model, string type, int nRegister, string nproducer, string nmodel, string ntype)
{
	Car el = Car(Register, producer, model, type);
	Car new_el = Car(nRegister, nproducer, nmodel, ntype);
	repo.Update(el, new_el);
}

Car* Service::Search(int Register)
{
	const char s1[10] = { 0 }, s2[10] = { 0 }, s3[10] = { 0 };
	Car el = Car(Register, s1, s2, s3);
	return repo.Search(el);
}

vector<Car> Service::Get_all()
{
	return repo.Get_all();
}

vector<Car> Service::Filter(function<bool(Car, string)> crt, string s)
{
	vector<Car> p = Get_all();
	vector<Car> aux;

	for (Car el : p)
	{
		if (crt(el, s))
			aux.push_back(el);
	}
	return aux;
}

vector<Car> Service::Sort(function<bool(Car,Car)> crt)
{
	vector<Car> p = Get_all();
	sort(p.begin(), p.end(), crt);
	return p;
}


bool sort1(Car el1, Car el2) noexcept
{
	return el1.GetnrRegister() < el2.GetnrRegister();
}

bool sort2(Car el1, Car el2)
{
	return el1.GetType() < el2.GetType();
}
bool sort3(Car el1, Car el2)
{
	if (el1.GetProducer() == el2.GetProducer())
	{
		return el1.Getmodel() < el2.Getmodel();
	}
	return el1.GetProducer() < el2.GetProducer();
}

void TestService::TestAdd()
{
	const char s[20] = "1";
	service.Add(1, s, s, s);
	assert((*service.Search(1)).GetnrRegister() == 1);

	try
	{
		service.Add(1, s, s, s);
		assert(false);
	}
	catch (exception)
	{
		assert(true);
	}
}

void TestService::TestDelete()
{
	const char s[20] = "1";
	service.Delete(1, s, s, s);
	vector<Car> p = service.Get_all();
	assert(p.size() == 0);
	try
	{
		service.Delete(1, s, s, s);
		assert(false);
	}
	catch(exception)
	{
		assert(true);
	}
}

void TestService::TestSearch()
{
	const char s[20] = "1";

	service.Add(3, s, s, s);
	service.Add(1, s, s, s);

	const Car* p = service.Search(1);

	if (p == nullptr)
		throw exception("error");

	assert((*p).GetnrRegister() == 1);
	try
	{
		service.Search(2);
		assert(false);
	}
	catch (exception)
	{
		assert(true);
	}
}

void TestService::TestUpdate()
{
	const char s[20] = "1";
	service.Update(1, s, s, s, 2, s, s, s);
	service.Search(2);

	try
	{
		service.Update(1, s, s, s, 2, s, s, s);
		assert(false);
	}
	catch (exception)
	{
		assert(true);
	}
}

bool crit(Car p, string s) 
{
	if (p.GetProducer() == s)
		return true;
	return false;
}

bool crit2(Car p, string s) 
{
	if (p.GetType() == s)
		return true;
	return false;
}

void TestService::TestGetAll()
{
	vector<Car> p = service.Get_all();
	assert(true);
}

void TestService::TestFilter()
{
	const char s[20] = "1", p[9] = "2";
	service.Add(1, s, s, s);
	service.Add(2, p, p, p);
	vector<Car> q = service.Filter(crit, s);
    q = service.Filter(crit2, s);
	assert(q.size() == 1);
	service.Delete(1, s, s, s);
	service.Delete(2, p, p, p);
}

void TestService::TestSort()
{
	const char s[20] = "1", p[9] = "2", o[9] = "6";
	service.Add(1, s, s, s);
	service.Add(2, p, p, p);
	service.Add(3,p,o,o);
	vector<Car> q = service.Sort(sort1);
	q = service.Sort(sort2);
	q = service.Sort(sort3);
	assert(q.size() == 3);
	service.Delete(1, s, s, s);
	service.Delete(2, p, p, p);
	service.Delete(3, p, o, o);
}

void TestService::Run()
{
	TestFilter();
	TestSort();
	TestAdd();
	TestDelete();
	TestGetAll();
	TestSearch();
	TestUpdate();
}
