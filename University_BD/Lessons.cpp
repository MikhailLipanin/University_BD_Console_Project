#include "Schedules.h"

Lessons::Lessons()
{
	// ������������� ������
	data = new Lesson[0];
	count = 0;
}

Lessons::~Lessons()
{
	// ������� ������������� �������
	delete[] data;
}

void Lessons::Copy(int n, Lesson* org, Lesson* (&res), int excl)
{
	int q = 0;
	for (int i = 0; i < n; i++) {
		if (i != excl) {
			res[q++] = org[i];
		}
	}
}

void Lessons::Add()
{
	Lesson buf;

	// ���� ������
	cout << "Lesson id: ";
	cin >> buf.id;
	cout << "Lesson name: ";
	cin >> buf.name;
	cout << "Lesson description: ";
	cin >> buf.desc;
	cout << "Teacher employee code: ";
	cin >> buf.prep;

	// �������� ���������� ������
	if (count == 0) {
		count++;
		data = new Lesson[count];
	}
	else {
		// ��������� ������
		Lesson* arB = new Lesson[count];

		// ��������� ������ � ��������� ������
		Copy(count, data, arB, -1);

		// �������� ����� ������
		count++;
		data = new Lesson[count]; // ������ ����� ��������, ��� ����� ����� ��������� ������

		// ���������� ������
		Copy(count - 1, arB, data, -1);

		// �������� ���������� �������
		delete[] arB;
	}

	// ���������� ������
	data[count - 1] = buf;

	system("cls");
	cout << "Data added!" << endl;
}

void Lessons::Edit()
{
	// �������� ������
	if (count == 0) {
		cout << "Data is empty!" << endl;
		return;
	}

	int index;
	cout << "Choose number (from 1 to " << count << "): ";
	cin >> index;
	index--; // ��� ��� ������ �� 1, � ���� �� 0

	// �������� �������
	if (index < 0 || index > count - 1) {
		cout << "Wrong number!" << endl;
		return;
	}

	// ���� ����� ������
	cout << "Lesson id: ";
	cin >> data[index].id;
	cout << "Lesson name: ";
	cin >> data[index].name;
	cout << "Lesson description: ";
	cin >> data[index].desc;
	cout << "Teacher employee code: ";
	cin >> data[index].prep;

	system("cls");
	cout << "Data changed!" << endl;
}

void Lessons::Del()
{
	// �������� ������
	if (count == 0) {
		cout << "Data is empty!" << endl;
		return;
	}

	int index;
	cout << "Choose number (from 1 to " << count << "): ";
	cin >> index;
	index--; // ��� ��� ������ �� 1, � ���� �� 0

	// �������� �������
	if (index < 0 || index > count - 1) {
		cout << "Wrong number!" << endl;
		return;
	}

	// ��������� ������
	Lesson* arB = new Lesson[count];

	// ��������� ������ � ��������� ������
	Copy(count, data, arB, -1);

	// �������� ����� ������
	count--;
	data = new Lesson[count]; // ������ ����� ��������, ��� ����� ����� ��������� ������

	// ���������� ������
	Copy(count + 1, arB, data, index); // ����� �������� � ������� index 

	// �������� ���������� �������
	delete[] arB;

	system("cls");
	cout << "Data deleted!" << endl;
}

void Lessons::Save()
{
	// �������� ������
	if (count == 0) {
		cout << "Data is empty!" << endl;
		return;
	}

	// ����� ��� ������
	ofstream save("Lessons.txt", ios::out);

	// ���������� ������
	save << count << endl;

	for (int i = 0; i < count; i++) {
		save << data[i].id << " ";
		save << data[i].name << " ";
		save << data[i].desc << " ";
		save << data[i].prep << " ";

		if (i < count - 1)
			save << endl;
	}

	save.close();
	cout << "Data saved in file: Lessons.txt " << endl;
}

void Lessons::Load()
{
	// ����� ��� ������
	ifstream load("Lessons.txt");

	// �������� ����� 
	if (!load) {
		cout << "File open error: Lessons.txt";
		return;
	}

	// ������� ������, ���� ������ �� ����
	if (count != 0)
		Clear();

	// ������ ������
	load >> count;
	data = new Lesson[count];

	for (int i = 0; i < count; i++) {
		load >> data[i].id;
		load >> data[i].name;
		load >> data[i].desc;
		load >> data[i].prep;
	}

	load.close();
	cout << "Data read from file: Lessons.txt" << endl;
}

void Lessons::Print()
{
	// �������� ������
	if (count == 0) {
		cout << "Data is empty!" << endl;
		return;
	}

	for (int i = 0; i < count; i++) {
		Print(data[i]);
		cout << "-----------------------------" << endl;
	}
}

void Lessons::Print(Lesson d)
{
	cout << "Lesson id: " << d.id << endl;
	cout << "Lesson name: " << d.name << endl;
	cout << "Lesson description: " << d.desc << endl;
	cout << "Teacher employee code: " << d.prep << endl;
}

void Lessons::Menu(int& act)
{
	cout << "Select an action:" << endl
		<< "0 - Back" << endl
		<< "1 - Print" << endl
		<< "2 - Add" << endl
		<< "3 - Edit" << endl
		<< "4 - Delete" << endl
		<< "5 - Load" << endl
		<< "6 - Save" << endl
		<< "Write a number: ";
	cin >> act;

	system("cls");
}

Lesson Lessons::GetItem(int i)
{
	// �������� �������
	if (i < 0 || i > count - 1) {
		cout << "Wrong number!" << endl;
		return Lesson();
	}

	return data[i];
}

void Lessons::Clear()
{
	delete[] data;

	data = new Lesson[0];
	count = 0;
}