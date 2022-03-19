#include "Employees.h"

Employees::Employees()
{
	// ������������� ������
	data = new Employee[0];
	count = 0;
}

Employees::~Employees()
{
	// ������� ������������� �������
	delete[] data;
}

void Employees::Copy(int n, Employee* org, Employee* (&res), int excl)
{
	int q = 0;
	for (int i = 0; i < n; i++) {
		if (i != excl) {
			res[q++] = org[i];
		}
	}
}

void Employees::Add()
{
	Employee buf;

	// ���� ������
	cout << "Employee code: ";
	cin >> buf.id;
	cout << "Fullname: ";
	cin >> buf.fullname.surname >> buf.fullname.name >> buf.fullname.patr;
	cout << "Age: ";
	cin >> buf.age;
	cout << "Gender (m / f): ";
	cin >> buf.gemder;
	cout << "Address: ";
	cin >> buf.address;
	cout << "Phone number: ";
	cin >> buf.phoneNum;
	cout << "Passport data (**** ******): ";
	cin >> buf.passport.series >> buf.passport.number;
	cout << "Position code: ";
	cin >> buf.idPosition;

	// �������� ���������� ������
	if (count == 0) {
		count++;
		data = new Employee[count];
	}
	else {
		// ��������� ������
		Employee* arB = new Employee[count];

		// ��������� ������ � ��������� ������
		Copy(count, data, arB, -1);

		// �������� ����� ������
		count++;
		data = new Employee[count]; // ������ ����� ��������, ��� ����� ����� ��������� ������

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

void Employees::Edit()
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
	cout << "Employee code: ";
	cin >> data[index].id;
	cout << "Fullname: ";
	cin >> data[index].fullname.surname >> data[index].fullname.name >> data[index].fullname.patr;
	cout << "Age: ";
	cin >> data[index].age;
	cout << "Gender (m / f): ";
	cin >> data[index].gemder;
	cout << "Address: ";
	cin >> data[index].address;
	cout << "Phone number: ";
	cin >> data[index].phoneNum;
	cout << "Passport data (**** ******): ";
	cin >> data[index].passport.series >> data[index].passport.number;
	cout << "Position code: ";
	cin >> data[index].idPosition;

	system("cls");
	cout << "Data changed!" << endl;
}

void Employees::Del()
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
	Employee* arB = new Employee[count];

	// ��������� ������ � ��������� ������
	Copy(count, data, arB, -1);

	// �������� ����� ������
	count--;
	data = new Employee[count]; // ������ ����� ��������, ��� ����� ����� ��������� ������

	// ���������� ������
	Copy(count + 1, arB, data, index); // ����� �������� � ������� index 

	// �������� ���������� �������
	delete[] arB;

	system("cls");
	cout << "Data deleted!" << endl;
}

void Employees::Save()
{
	// �������� ������
	if (count == 0) {
		cout << "Data is empty!" << endl;
		return;
	}

	// ����� ��� ������
	ofstream save("Employees.txt", ios::out);

	// ���������� ������
	save << count << endl;

	for (int i = 0; i < count; i++) {
		save << data[i].id << " ";
		save << data[i].fullname.surname << " ";
		save << data[i].fullname.name << " ";
		save << data[i].fullname.patr << " ";
		save << data[i].age << " ";
		save << data[i].gemder << " ";
		save << data[i].address << " ";
		save << data[i].phoneNum;
		save << data[i].passport.series << " ";
		save << data[i].passport.number << " ";
		save << data[i].idPosition << " ";

		if (i < count - 1)
			save << endl;
	}

	save.close();
	cout << "Data saved in file:: Employees.txt " << endl;
}

void Employees::Load()
{
	// ����� ��� ������
	ifstream load("Employees.txt");

	// �������� ����� 
	if (!load) {
		cout << "File open error: Employees.txt";
		return;
	}

	// ������� ������, ���� ������ �� ����
	if (count != 0)
		Clear();

	// ������ ������
	load >> count;
	data = new Employee[count];

	for (int i = 0; i < count; i++) {
		load >> data[i].id;
		load >> data[i].fullname.surname;
		load >> data[i].fullname.name;
		load >> data[i].fullname.patr;
		load >> data[i].age;
		load >> data[i].gemder;
		load >> data[i].address;
		load >> data[i].phoneNum;
		load >> data[i].passport.series;
		load >> data[i].passport.number;
		load >> data[i].idPosition;
	}

	load.close();
	cout << "Data read from file: Employees.txt" << endl;
}

void Employees::Print()
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

void Employees::Print(Employee d)
{
	cout << "Employee code: " << d.id << endl;
	cout << "Fullname: " << d.fullname.surname << " " << d.fullname.name << " " << d.fullname.patr << endl;
	cout << "Age: " << d.age << endl;
	cout << "Gender (m / f): " << d.gemder << endl;
	cout << "Address: " << d.address << endl;
	cout << "Phone number: " << d.phoneNum << endl;
	cout << "Passport data (**** ******): " << d.passport.series << " " << d.passport.number << endl;
	cout << "Position code: " << d.idPosition << endl;
}

void Employees::Menu(int& act)
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

Employee Employees::GetItem(int i)
{
	// �������� �������
	if (i < 0 || i > count - 1) {
		cout << "Wrong number!" << endl;
		return Employee();
	}

	return data[i];
}

void Employees::Clear()
{
	delete[] data;

	data = new Employee[0];
	count = 0;
}