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

// ��������� ������ ����������
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

// ����� ����������
class Employees
{
	// ���� ������
private: // �������� �����
	Employee* data;
	int count;

	// ������ ������
public: // �������� �����
	Employees(); // ����������� �� ��������� - ������� ������ ������ ������
	~Employees(); // ���������� - ������� ������ ������

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

