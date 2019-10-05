#pragma once

#include "Service.h"
#include<iostream>
#include<string.h>

class UI {
private:
	Service service;       
public:
	UI() = default;
	void Console();
	void Add();
	void Delete();
	void Update();
	void Search();
	void Print();
	void Filter();
	void Sort();
	~UI() = default;
};
