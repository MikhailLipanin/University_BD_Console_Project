#pragma once
#include "Groups.h"

// ��������� ������ �������
struct Lesson
{
	int id;
	string name;
	string desc; // �������� ��������
	int prep; // ��� �������������
};

class Lessons
{
	// ���� ������
private: // �������� �����
	Lesson* data;
	int count;

	// ������ ������
public: // �������� �����
	Lessons(); // ����������� �� ��������� - ������� ������ ������ ������
	~Lessons(); // ���������� - ������� ������ ������

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

