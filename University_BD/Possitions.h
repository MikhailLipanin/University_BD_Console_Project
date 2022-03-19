#pragma once
#include "Employees.h"

// ��������� ������ ���������
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
	// ���� ������
private: // �������� �����
	Possition* data;
	int count;

	// ������ ������
public: // �������� �����
	Possitions(); // ����������� �� ��������� - ������� ������ ������ ������
	~Possitions(); // ���������� - ������� ������ ������

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

