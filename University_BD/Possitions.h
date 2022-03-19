#pragma once
#include "Employees.h"

// Структура данных должности
struct Possition
{
	int id;
	string name;
	float salary;
	string responsibilities;
	string requirements;
};


class Possitions
{
	// Поля класса
private: // закрытая часть
	Possition* data;
	int count;

	// Методы класса
public: // открытая часть
	Possitions(); // конструктор по умолчанию - создает пустой объект класса
	~Possitions(); // деструктор - удаляет объект класса

	void Copy(int n, Possition* org, Possition* (&res), int excl);
	void Add();
	void Edit();
	void Del();
	void Save();
	void Load();
	void Print();
	void Print(Possition d);
	void Menu(int& act);
	int Count() { return count; }
	Possition GetItem(int i);
	void Clear();
};

