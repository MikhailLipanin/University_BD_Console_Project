#include "Schedules.h"

Lessons::Lessons()
{
	// Инициализация данных
	data = new Lesson[0];
	count = 0;
}

Lessons::~Lessons()
{
	// Очистка динамического массива
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

	// Ввод данных
	cout << "Lesson id: ";
	cin >> buf.id;
	cout << "Lesson name: ";
	cin >> buf.name;
	cout << "Lesson description: ";
	cin >> buf.desc;
	cout << "Teacher employee code: ";
	cin >> buf.prep;

	// Проверка количества данных
	if (count == 0) {
		count++;
		data = new Lesson[count];
	}
	else {
		// Временный массив
		Lesson* arB = new Lesson[count];

		// Переносим данные в временный массив
		Copy(count, data, arB, -1);

		// Выделяем новую память
		count++;
		data = new Lesson[count]; // данные будут потеряны, для этого нужен временный массив

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

void Lessons::Edit()
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
	Lesson* arB = new Lesson[count];

	// Переносим данные в временный массив
	Copy(count, data, arB, -1);

	// Выделяем новую память
	count--;
	data = new Lesson[count]; // данные будут потеряны, для этого нужен временный массив

	// Возвращаем данные
	Copy(count + 1, arB, data, index); // кроме элемента с номером index 

	// Удаление временного массива
	delete[] arB;

	system("cls");
	cout << "Data deleted!" << endl;
}

void Lessons::Save()
{
	// Проверка данных
	if (count == 0) {
		cout << "Data is empty!" << endl;
		return;
	}

	// Поток для записи
	ofstream save("Lessons.txt", ios::out);

	// Сохранение данных
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
	// Поток для чтения
	ifstream load("Lessons.txt");

	// Проверка файла 
	if (!load) {
		cout << "File open error: Lessons.txt";
		return;
	}

	// Очищаем данные, если массив не пуст
	if (count != 0)
		Clear();

	// Чтение данных
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
	// Проверка индекса
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