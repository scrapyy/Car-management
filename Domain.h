#pragma once
#include<string>

using namespace std;

class Car {
private:
	int nrRegister;
	string producer;
	string model;
	string type;
public:
	Car(int nrRegisteri,string produceri,string modeli,string typei);
	int GetnrRegister() const noexcept;
	string GetProducer() const;
	string Getmodel() const;
	string GetType() const;

	void SetnrRegister(int Register) noexcept;
	void SetProducer(string Producer);
	void SetModel(string Model);
	void SetType(string Type);

	
	bool operator ==(const Car &other) const noexcept{
		return nrRegister == other.GetnrRegister();
	}
	~Car() = default;
};