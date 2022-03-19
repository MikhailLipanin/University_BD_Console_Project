#pragma once
#include "Possitions.h"

// Структура данных студента
struct Student
{
	Fullname fullname;
	Date birth;
	char gemder;
	string address;
	Fullname father;
	Fullname mother;
	int idg; // код группы
	string dop_info;
};

class Students
{
	// Поля класса
private: // закрытая часть
	Student* data;
	int count;

	// Методы класса
public: // открытая часть
	Students(); // конструктор по умолчанию - создает пустой объект класса
	~Students(); // деструктор - удаляет объект класса

	void Copy(int n, Student* org, Student* (&res), int excl);
	void Add();
	void Edit();
	void Del();
	void Save();
	void Load();
	void Print();
	void Print(Student d);
	void Menu(int& act);
	int Count() { return count; }
	Student GetItem(int i);
	void Clear();
};

