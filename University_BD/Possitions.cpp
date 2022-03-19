#include "Possitions.h"

Possitions::Possitions()
{
	// Инициализация данных
	data = new Possition[0];
	count = 0;
}

Possitions::~Possitions()
{
	// Очистка динамического массива
	delete[] data;
}

void Possitions::Copy(int n, Possition* org, Possition* (&res), int excl)
{
	int q = 0;
	for (int i = 0; i < n; i++) {
		if (i != excl) {
			res[q++] = org[i];
		}
	}
}

void Possitions::Add()
{
	Possition buf;

	// Ввод данных
	cout << "Position code: ";
	cin >> buf.id;
	cout << "Position name: ";
	cin >> buf.name;
	cout << "Salary: ";
	cin >> buf.salary;
	cout << "Responsibilities: ";
	cin >> buf.responsibilities;
	cout << "Requirements: ";
	cin >> buf.requirements;

	// Проверка количества данных
	if (count == 0) {
		count++;
		data = new Possition[count];
	}
	else {
		// Временный массив
		Possition* arB = new Possition[count];

		// Переносим данные в временный массив
		Copy(count, data, arB, -1);

		// Выделяем новую память
		count++;
		data = new Possition[count]; // данные будут потеряны, для этого нужен временный массив

		// Возвращаем данные
		Copy(count - 1, arB, data, -1);

		// Удаление временного массива
		delete[] arB;
	}

	// Добавление данных
	data[count - 1] = buf;

	system("cls");
	cout << "Data added!" << endl;
}

void Possitions::Edit()
{
	// Проверка данных
	if (count == 0) {
		cout << "Data is empty!" << endl;
		return;
	}

	int index;
	cout << "Choose number (from 1 to " << count << "): ";
	cin >> index;
	index--; // так как вводим от 1, а счет от 0

	// Проверка индекса
	if (index < 0 || index > count - 1) {
		cout << "Wrong number!" << endl;
		return;
	}

	// Ввод новых данных
	cout << "Position code: ";
	cin >> data[index].id;
	cout << "Position name: ";
	cin >> data[index].name;
	cout << "Salary: ";
	cin >> data[index].salary;
	cout << "Responsibilities: ";
	cin >> data[index].responsibilities;
	cout << "Requirements: ";
	cin >> data[index].requirements;

	system("cls");
	cout << "Data changed!" << endl;
}

void Possitions::Del()
{
	// Проверка данных
	if (count == 0) {
		cout << "Data is empty!" << endl;
		return;
	}

	int index;
	cout << "Choose number (from 1 to " << count << "): ";
	cin >> index;
	index--; // так как вводим от 1, а счет от 0

	// Проверка индекса
	if (index < 0 || index > count - 1) {
		cout << "Wrong index!" << endl;
		return;
	}

	// Временный массив
	Possition* arB = new Possition[count];

	// Переносим данные в временный массив
	Copy(count, data, arB, -1);

	// Выделяем новую память
	count--;
	data = new Possition[count]; // данные будут потеряны, для этого нужен временный массив

	// Возвращаем данные
	Copy(count + 1, arB, data, index); // кроме элемента с номером index 

	// Удаление временного массива
	delete[] arB;

	system("cls");
	cout << "Data deleted!" << endl;
}

void Possitions::Save()
{
	// Проверка данных
	if (count == 0) {
		cout << "Data is empty!" << endl;
		return;
	}

	// Поток для записи
	ofstream save("Possitions.txt", ios::out);

	// Сохранение данных
	save << count << endl;

	for (int i = 0; i < count; i++) {
		save << data[i].id << " ";
		save << data[i].name << " ";
		save << data[i].salary;
		save << data[i].requirements << " ";
		save << data[i].responsibilities << " ";

		if (i < count - 1)
			save << endl;
	}

	save.close();
	cout << "Data saved in file: Possitions.txt " << endl;
}

void Possitions::Load()
{
	// Поток для чтения
	ifstream load("Possitions.txt");

	// Проверка файла 
	if (!load) {
		cout << "File open error: Possitions.txt";
		return;
	}

	// Очищаем данные, если массив не пуст
	if (count != 0)
		Clear();

	// Чтение данных
	load >> count;
	data = new Possition[count];

	for (int i = 0; i < count; i++) {
		load >> data[i].id;
		load >> data[i].name;
		load >> data[i].salary;
		load >> data[i].requirements;
		load >> data[i].responsibilities;
	}

	load.close();
	cout << "Data read from file: Possitions.txt" << endl;
}

void Possitions::Print()
{
	// Проверка данных
	if (count == 0) {
		cout << "Data is empty!" << endl;
		return;
	}

	for (int i = 0; i < count; i++) {
		Print(data[i]);
		cout << "-----------------------------" << endl;
	}
}

void Possitions::Print(Possition d)
{
	cout << "Position code: " << d.id << endl;
	cout << "Position name: " << d.name << endl;
	cout << "Salary: " << d.salary << endl;
	cout << "Responsibilities: " << d.responsibilities << endl;
	cout << "Requirements: " << d.requirements << endl;
}

void Possitions::Menu(int& act)
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

Possition Possitions::GetItem(int i)
{
	// Проверка индекса
	if (i < 0 || i > count - 1) {
		cout << "Wrong number!" << endl;
		return Possition();
	}

	return data[i];
}

void Possitions::Clear()
{
	delete[] data;

	data = new Possition[0];
	count = 0;
}
