#include "Schedules.h"

Schedules::Schedules()
{
	// Инициализация данных
	data = new Schedule[0];
	count = 0;
}

Schedules::~Schedules()
{
	// Очистка динамического массива
	delete[] data;
}

void Schedules::Copy(int n, Schedule* org, Schedule* (&res), int excl)
{
	int q = 0;
	for (int i = 0; i < n; i++) {
		if (i != excl) {
			res[q++] = org[i];
		}
	}
}

void Schedules::Add()
{
	Schedule buf;

	// Ввод данных
	cout << "Lesson date: ";
	cin >> buf.date.day >> buf.date.month >> buf.date.year;
	cout << "Day of week (1 - 7): ";
	cin >> buf.day;
	cout << "Group number: ";
	cin >> buf.idg;
	cout << "Lesson number: ";
	cin >> buf.idl;
	cout << "Start time: ";
	cin >> buf.tmbe.be >> buf.tmbe.en;
	cout << "End time: ";
	cin >> buf.tmen.be >> buf.tmen.en;

	// Проверка количества данных
	if (count == 0) {
		count++;
		data = new Schedule[count];
	}
	else {
		// Временный массив
		Schedule* arB = new Schedule[count];

		// Переносим данные в временный массив
		Copy(count, data, arB, -1);

		// Выделяем новую память
		count++;
		data = new Schedule[count]; // данные будут потеряны, для этого нужен временный массив

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

void Schedules::Edit()
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
	cout << "Lesson date: ";
	cin >> data[index].date.day >> data[index].date.month >> data[index].date.year;
	cout << "Day of week (1 - 7): ";
	cin >> data[index].day;
	cout << "Group number: ";
	cin >> data[index].idg;
	cout << "Lesson number: ";
	cin >> data[index].idl;
	cout << "Start time: ";
	cin >> data[index].tmbe.be >> data[index].tmbe.en;
	cout << "End time: ";
	cin >> data[index].tmen.be >> data[index].tmen.en;

	system("cls");
	cout << "Data changed!" << endl;
}

void Schedules::Del()
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

	// Временный массив
	Schedule* arB = new Schedule[count];

	// Переносим данные в временный массив
	Copy(count, data, arB, -1);

	// Выделяем новую память
	count--;
	data = new Schedule[count]; // данные будут потеряны, для этого нужен временный массив

	// Возвращаем данные
	Copy(count + 1, arB, data, index); // кроме элемента с номером index 

	// Удаление временного массива
	delete[] arB;

	system("cls");
	cout << "Data deleted!" << endl;
}

void Schedules::Save()
{
	// Проверка данных
	if (count == 0) {
		cout << "Data is empty!" << endl;
		return;
	}

	// Поток для записи
	ofstream save("Schedules.txt", ios::out);

	// Сохранение данных
	save << count << endl;

	for (int i = 0; i < count; i++) {
		save << data[i].date.day << " " << data[i].date.month << " " << data[i].date.year << " ";
		save << data[i].day << " ";
		save << data[i].idg << " ";
		save << data[i].idl << " ";
		save << data[i].tmbe.be << " " << data[i].tmbe.en << " ";
		save << data[i].tmen.be << " " << data[i].tmen.en << " ";

		if (i < count - 1)
			save << endl;
	}

	save.close();
	cout << "Data saved in file: Schedules.txt " << endl;
}

void Schedules::Load()
{
	// Поток для чтения
	ifstream load("Schedules.txt");

	// Проверка файла 
	if (!load) {
		cout << "File open error: Schedules.txt";
		return;
	}

	// Очищаем данные, если массив не пуст
	if (count != 0)
		Clear();

	// Чтение данных
	load >> count;
	data = new Schedule[count];

	for (int i = 0; i < count; i++) {
		load >> data[i].date.day >> data[i].date.month >> data[i].date.year;
		load >> data[i].day;
		load >> data[i].idg;
		load >> data[i].idl;
		load >> data[i].tmbe.be >> data[i].tmbe.en;
		load >> data[i].tmen.be >> data[i].tmen.en;
	}

	load.close();
	cout << "Data read from file: Schedules.txt" << endl;
}

void Schedules::Print()
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

void Schedules::Print(Schedule d)
{
	cout << "Lesson date: " << d.date.day << "." << d.date.month << "." << d.date.year << endl;
	cout << "Day of week (1 - 7): " << d.day << endl;
	cout << "Group number: " << d.idg << endl;
	cout << "Lesson number: " << d.idl << endl;
	cout << "Start time: " << d.tmbe.be << ":" << d.tmbe.en << endl;
	cout << "End time: " << d.tmen.be << ":" << d.tmen.en << endl;
}

void Schedules::Menu(int& act)
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

Schedule Schedules::GetItem(int i)
{
	// Проверка индекса
	if (i < 0 || i > count - 1) {
		cout << "Wrong number!" << endl;
		return Schedule();
	}

	return data[i];
}

void Schedules::Clear()
{
	delete[] data;

	data = new Schedule[0];
	count = 0;
}