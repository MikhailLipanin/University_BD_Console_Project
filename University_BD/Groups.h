#pragma once
#include "Students.h"

// ��������� ������ ������
struct Group
{
	int id; // ��� ������
	int kur; // ��� ��������
	int dir; // ����������� ����������
	int val; // ���-�� ���������
	int year; // ������� ��� ��������
	int beg; // ������ ��������
};

class Groups
{
	// ���� ������
private: // �������� �����
	Group* data;
	int count;

	// ������ ������
public: // �������� �����
	Groups(); // ����������� �� ��������� - ������� ������ ������ ������
	~Groups(); // ���������� - ������� ������ ������

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

