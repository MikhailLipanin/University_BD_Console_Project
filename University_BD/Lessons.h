#pragma once
#include "Groups.h"

// Структура данных болезни
struct Lesson
{
	int id;
	string name;
	string desc; // описание предмета
	int prep; // код преподавателя
};

class Lessons
{
	// Поля класса
private: // закрытая часть
	Lesson* data;
	int count;

	// Методы класса
public: // открытая часть
	Lessons(); // конструктор по умолчанию - создает пустой объект класса
	~Lessons(); // деструктор - удаляет объект класса

	void Copy(int n, Lesson* org, Lesson* (&res), int excl);
	void Add();
	void Edit();
	void Del();
	void Save();
	void Load();
	void Print();
	void Print(Lesson d);
	void Menu(int& act);
	int Count() { return count; }
	Lesson GetItem(int i);
	void Clear();
};

