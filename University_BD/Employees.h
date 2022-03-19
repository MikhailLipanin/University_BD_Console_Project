#pragma once

#include <iostream>
#include <fstream>
#include <Windows.h>
#include <string>
using namespace std;

struct Fullname {
	string surname;
	string name;
	string patr;
};

struct Passport {
	string series;
	string number;
};

struct Date {
	int day,
		month,
		year;
};

struct Time {
	int be,
		en;
};

// Структура данных сотрудника
struct Employee
{
	int id;
	Fullname fullname;
	int age;
	char gemder;
	string address;
	string phoneNum;
	Passport passport;
	int idPosition;
};

// Класс Сотрудники
class Employees
{
	// Поля класса
private: // закрытая часть
	Employee* data;
	int count;

	// Методы класса
public: // открытая часть
	Employees(); // конструктор по умолчанию - создает пустой объект класса
	~Employees(); // деструктор - удаляет объект класса

	void Copy(int n, Employee* org, Employee* (&res), int excl);
	void Add();
	void Edit();
	void Del();
	void Save();
	void Load();
	void Print();
	void Print(Employee d);
	void Menu(int& act);
	int Count() { return count; }
	Employee GetItem(int i);
	void Clear();
};

