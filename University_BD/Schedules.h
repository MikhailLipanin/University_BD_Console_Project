#pragma once
#include "Lessons.h"

// Структура данных болезни
struct Schedule
{
	Date date;
	int day;
	int idg;
	int idl;
	Time tmbe;
	Time tmen;
};

class Schedules
{
	// Поля класса
private: // закрытая часть
	Schedule* data;
	int count;

	// Методы класса
public: // открытая часть
	Schedules(); // конструктор по умолчанию - создает пустой объект класса
	~Schedules(); // деструктор - удаляет объект класса

	void Copy(int n, Schedule* org, Schedule* (&res), int excl);
	void Add();
	void Edit();
	void Del();
	void Save();
	void Load();
	void Print();
	void Print(Schedule d);
	void Menu(int& act);
	int Count() { return count; }
	Schedule GetItem(int i);
	void Clear();
};

