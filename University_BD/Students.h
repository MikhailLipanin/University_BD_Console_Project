#pragma once
#include "Possitions.h"

// ��������� ������ ��������
struct Student
{
	Fullname fullname;
	Date birth;
	char gemder;
	string address;
	Fullname father;
	Fullname mother;
	int idg; // ��� ������
	string dop_info;
};

class Students
{
	// ���� ������
private: // �������� �����
	Student* data;
	int count;

	// ������ ������
public: // �������� �����
	Students(); // ����������� �� ��������� - ������� ������ ������ ������
	~Students(); // ���������� - ������� ������ ������

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

