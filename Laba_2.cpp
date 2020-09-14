// Laba_2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <locale.h>

using namespace std;

class Kotik
{
private:

	int ID;
	string name;
	string diagnosis;

public:
	Kotik()
	{
		this->ID = 0;
		this->name = " ";
		this->diagnosis = " ";
	}
	Kotik(int id, string FIO)
	{
		this->ID = id;
		this->name = FIO;
		this->diagnosis = " ";
	}
	~Kotik() {}
	friend void print(Kotik& prin);
	friend class Veterinar;

};

class Veterinar
{
private:

	string diagnos;

public:

	Veterinar()
	{
		this->diagnos = " ";
	}

	Veterinar(string d)
	{
		this->diagnos = d;
	}

	~Veterinar() {}

	void set_diagnosis(Kotik& obr)
	{
		obr.diagnosis = diagnos;
	}

};

void print(Kotik& prin)
{
	cout << endl << "уникальный номер (ID): ";
	cout << prin.ID;
	cout << endl << "ФИО: ";
	cout << prin.name;
	cout << endl << "Диагноз: ";
	cout << prin.diagnosis;
	cout << endl;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	Veterinar doctor;
	int id;
	string FIO;
	string diagnos;
	bool a = true;
	do
	{
		cout << "Введите id: ";
		cin >> id;
		if (cin.fail())
			cout << "Повторите попытку" << endl;
		else
			a = false;
		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail());
	} while (a);
	cout << endl << "Введите ФИО:";
	cin >> FIO;
	Kotik k(id, FIO);

	print(k);
	cout << endl << "Введите диагноз:";
	cin >> diagnos;
	Veterinar s(diagnos);
	s.set_diagnosis(k);

	print(k);
	return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
