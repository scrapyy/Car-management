#pragma once
#include<vector>
#include "Domain.h"
#include<exception>
#include<assert.h>

using namespace std;

class Repo {
private:
	vector<Car> list;
public:
	Repo() = default;
	void Add(Car el);
	void Delete(Car el);
	void Update(Car el, Car new_el);
	vector<Car> Get_all();
	bool Find(Car el);
	Car* Search(Car el);

	~Repo()=default;
};

class TestRepo {
private:
	Repo repo;
public:
	TestRepo()=default;
	void TestAdd();
	void TestDelete();
	void TestUpdate();
	void TestSearch();
	void Run();
	
	~TestRepo()=default;
};