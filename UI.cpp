#include "UI.h"

void UI::Add()
{
	int Register;
	string model;
	string type;
	string producer; 
	
	cout << "Insert register: ";
	cin >> Register;
	cout << "Insert model: ";
	cin >> model;
	cout << "Insert type: ";
	cin >> type;
	cout << "Insert producer: ";
	cin >> producer;

	service.Add(Register, producer, model, type);
}

void UI::Delete()
{
	int Register;
	string model;
	string type;
	string producer;

	cout << "Insert register: ";
	cin >> Register;
	cout << "Insert model: ";
	cin >> model;
	cout << "Insert type: ";
	cin >> type;
	cout << "Insert producer: ";
	cin >> producer;

	service.Delete(Register, producer, model, type);
}

void UI::Update()
{
	int Register;
	string model;
	string type;
	string producer;

	cout << "Insert register: ";
	cin >> Register;
	cout << "Insert model: ";
	cin >> model;
	cout << "Insert type: ";
	cin >> type;
	cout << "Insert producer: ";
	cin >> producer;

	int nRegister;
	string nmodel;
	string ntype;
	string nproducer;

	cout << "Insert new register: ";
	cin >> nRegister;
	cout << "Insert new model: ";
	cin >> nmodel;
	cout << "Insert new type: ";
	cin >> ntype;
	cout << "Insert new producer: ";
	cin >> nproducer;

	service.Update(Register, producer, model, type, nRegister, nproducer, nmodel, ntype);
}

void UI::Search()
{
	int Register;
	cout << "Insert register: ";
	cin >> Register;

	const Car *el = service.Search(Register);

	if (el == nullptr)
		throw exception("error");

	cout << (*el).GetnrRegister() << " " << (*el).GetProducer() << " " << (*el).Getmodel() << " " << (*el).GetType() << "\n";
}

void UI::Print()
{
	vector<Car> list = service.Get_all();
	for (Car el : list)
	{
		cout << el.GetnrRegister() << " " << el.Getmodel() << " " << el.GetProducer() << " " << el.GetType() << "\n";
	}
}



void UI::Filter()
{
	cout << "Insert 1 for producer filter\n";
	cout << "Insert 2 for type filter\n";
	int cmd;
	cin >> cmd;
	string s;
	vector<Car> p;
	if (cmd == 1)
	{
		cout << "Insert producer: ";
		cin >> s;
		p = service.Filter(crit, s);
	}
	else if (cmd == 2)
	{
		cout << "Insert type: ";
		cin >> s;
		p = service.Filter(crit2, s);
	}
	for (Car el : p)
	{
		cout << el.GetnrRegister() << " " << el.Getmodel() << " " << el.GetProducer() << " " << el.GetType() << "\n";
	}
}



void UI::Sort()
{

	int cmd;
	cout << "Insert 1 for register sorting\n";
	cout << "Insert 2 for type sorting\n";
	cout << "Insert 3 for producer + model\n";

	cin >> cmd;
	
	vector<Car> p;

	if (cmd == 1)
		p = service.Sort(sort1);
	else if (cmd == 2)
		p = service.Sort(sort2);
	else if (cmd == 3)
		p = service.Sort(sort3);
	
	for (Car el : p)
	{
		cout << el.GetnrRegister() << " " << el.Getmodel() << " " << el.GetProducer() << " " << el.GetType() << "\n";
	}
}

void UI::Console()
{
	int cmd = 0;
	while (true)
	{
		cout << "Insert 1 to add\n";
		cout << "Insert 2 to delete\n";
		cout << "Insert 3 to update\n";
		cout << "Insert 4 to search\n";
		cout << "Insert 5 tp print\n";
		cout << "Insert 6 to filter\n";
		cout << "Insert 7 to sort\n";
		cin >> cmd;
		try
		{
			if (cmd == 1)
				Add();
			else if (cmd == 2)
				Delete();
			else if (cmd == 3)
				Update();
			else if (cmd == 4)
				Search();
			else if (cmd == 5)
				Print();
			else if (cmd == 6)
				Filter();
			else if (cmd == 7)
				Sort();
			else if (cmd == 0)
				break;
		}
		catch (const exception &exception)
		{
			cout << exception.what() << "\n";
		}
	}
}
