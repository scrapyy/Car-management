#pragma once
#include "Repo.h"
#include "Domain.h"
#include<assert.h>
#include<functional>
#include<algorithm>

class Service {
private:
	Repo repo;
public:
	Service()=default;
	void Add(int Register, string producer, string model, string type);
	void Delete(int Register, string producer, string model, string type);
	void Update(int Register, string producer, string model, string type, int nRegister, string nproducer, string nmodel, string ntype);
	Car* Search(int Register);
	vector<Car> Get_all();
	vector<Car> Filter(function<bool(Car, string)> crt, string s);
	vector<Car> Sort(function<bool(Car,Car)> crt);
	~Service()=default;
};

class TestService {
private:
	Service service;
public:
	TestService() = default;
	void TestAdd();
	void TestDelete();
	void TestUpdate();
	void TestSearch();
	void TestGetAll();
	void TestFilter();
	void TestSort();
	
	void Run();
	~TestService()=default;
};

bool sort3(Car el1, Car el2);
bool sort2(Car el1, Car el2);
bool sort1(Car el1, Car el2) noexcept;
bool crit2(Car p, string s);
bool crit(Car p, string s);