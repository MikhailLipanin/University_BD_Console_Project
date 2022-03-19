#include "Groups.h"

Groups::Groups()
{
	// Инициализация данных
	data = new Group[0];
	count = 0;
}

Groups::~Groups()
{
	// Очистка динамического массива
	delete[] data;
}

void Groups::Copy(int n, Group* org, Group* (&res), int excl)
{
	int q = 0;
	for (int i = 0; i < n; i++) {
		if (i != excl) {
			res[q++] = org[i];
		}
	}
}

void Groups::Add()
{
	Group buf;

	// Ввод данных
	cout << "Group code: ";
	cin >> buf.id;
	cout << "Curator code: ";
	cin >> buf.kur;
	cout << "Field of study: ";
	cin >> buf.dir;
	cout << "Number of students: ";
	cin >> buf.val;
	cout << "Current year of study: ";
	cin >> buf.year;
	cout << "Start of study: ";
	cin >> buf.beg;

	// Проверка количества данных
	if (count == 0) {
		count++;
		data = new Group[count];
	}
	else {
		// Временный массив
		Group* arB = new Group[count];

		// Переносим данные в временный массив
		Copy(count, data, arB, -1);

		// Выделяем новую память
		count++;
		data = new Group[count]; // данные будут потеряны, для этого нужен временный массив

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

void Groups::Edit()
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
	cout << "Group code: ";
	cin >> data[index].id;
	cout << "Curator code: ";
	cin >> data[index].kur;
	cout << "Field of study: ";
	cin >> data[index].dir;
	cout << "Number of students: ";
	cin >> data[index].val;
	cout << "Current year of study: ";
	cin >> data[index].year;
	cout << "Start of study: ";
	cin >> data[index].beg;

	system("cls");
	cout << "Data changed!" << endl;
}

void Groups::Del()
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
	Group* arB = new Group[count];

	// Переносим данные в временный массив
	Copy(count, data, arB, -1);

	// Выделяем новую память
	count--;
	data = new Group[count]; // данные будут потеряны, для этого нужен временный массив

	// Возвращаем данные
	Copy(count + 1, arB, data, index); // кроме элемента с номером index 

	// Удаление временного массива
	delete[] arB;

	system("cls");
	cout << "Data deleted!" << endl;
}

void Groups::Save()
{
	// Проверка данных
	if (count == 0) {
		cout << "Data is empty!" << endl;
		return;
	}

	// Поток для записи
	ofstream save("Groups.txt", ios::out);

	// Сохранение данных
	save << count << endl;

	for (int i = 0; i < count; i++) {
		save << data[i].id << " ";
		save << data[i].dir << " ";
		save << data[i].kur << " ";
		save << data[i].val << " ";
		save << data[i].year << " ";
		save << data[i].beg;

		if (i < count - 1)
			save << endl;
	}

	save.close();
	cout << "Data saved in file: Groups.txt " << endl;
}

void Groups::Load()
{
	// Поток для чтения
	ifstream load("Groups.txt");

	// Проверка файла 
	if (!load) {
		cout << "File open error: Groups.txt";
		return;
	}

	// Очищаем данные, если массив не пуст
	if (count != 0)
		Clear();

	// Чтение данных
	load >> count;
	data = new Group[count];

	for (int i = 0; i < count; i++) {
		load >> data[i].id;
		load >> data[i].dir;
		load >> data[i].kur;
		load >> data[i].val;
		load >> data[i].year;
		load >> data[i].beg;
	}

	load.close();
	cout << "Data read from file: Groups.txt" << endl;
}

void Groups::Print()
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

void Groups::Print(Group d)
{
	cout << "Group code: " << d.id << endl;
	cout << "Field of study: " << d.dir << endl;
	cout << "Curator code: " << d.kur << endl;
	cout << "Number of students: " << d.val << endl;
	cout << "Current year of study: " << d.year << endl;
	cout << "Start of study: " << d.beg << endl;
}

void Groups::Menu(int& act)
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

Group Groups::GetItem(int i)
{
	// Проверка индекса
	if (i < 0 || i > count - 1) {
		cout << "Wrong number!" << endl;
		return Group();
	}

	return data[i];
}

void Groups::Clear()
{
	delete[] data;

	data = new Group[0];
	count = 0;
}