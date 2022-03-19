#pragma once
#include "Lessons.h"

// ��������� ������ �������
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
	// ���� ������
private: // �������� �����
	Schedule* data;
	int count;

	// ������ ������
public: // �������� �����
	Schedules(); // ����������� �� ��������� - ������� ������ ������ ������
	~Schedules(); // ���������� - ������� ������ ������

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

