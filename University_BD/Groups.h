#pragma once
#include "Students.h"

// Структура данных группы
struct Group
{
	int id; // код группы
	int kur; // код куратора
	int dir; // направление подготовки
	int val; // кол-во студентов
	int year; // текущий год обучения
	int beg; // начало обучения
};

class Groups
{
	// Поля класса
private: // закрытая часть
	Group* data;
	int count;

	// Методы класса
public: // открытая часть
	Groups(); // конструктор по умолчанию - создает пустой объект класса
	~Groups(); // деструктор - удаляет объект класса

	void Copy(int n, Group* org, Group* (&res), int excl);
	void Add();
	void Edit();
	void Del();
	void Save();
	void Load();
	void Print();
	void Print(Group d);
	void Menu(int& act);
	int Count() { return count; }
	Group GetItem(int i);
	void Clear();
};

