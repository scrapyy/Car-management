#include "Domain.h"

Car::Car(int nrRegisteri, string produceri, string modeli, string typei)
{
	nrRegister = nrRegisteri;
	producer = produceri;
	model = modeli;
	type = typei;
}

int Car::GetnrRegister() const noexcept
{
	return nrRegister;
}

string Car::Getmodel() const
{
	return model;
}

string Car::GetProducer() const
{
	return producer;
}

string Car::GetType() const
{
	return type;
}

void Car::SetnrRegister(int Register) noexcept
{
	nrRegister = Register;
}

void Car::SetModel(string Model)
{
	model = Model;
}

void Car::SetProducer(string Producer)
{
	producer = Producer;
}

void Car::SetType(string Type)
{
	type = Type;
}

