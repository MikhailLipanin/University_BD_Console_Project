#include "Students.h"

Students::Students()
{
	// Инициализация данных
	data = new Student[0];
	count = 0;
}

Students::~Students()
{
	// Очистка динамического массива
	delete[] data;
}

void Students::Copy(int n, Student* org, Student* (&res), int excl)
{
	int q = 0;
	for (int i = 0; i < n; i++) {
		if (i != excl) {
			res[q++] = org[i];
		}
	}
}

void Students::Add()
{
	Student buf;

	// Ввод данных
	cout << "Full name of student: ";
	cin >> buf.fullname.surname >> buf.fullname.name >> buf.fullname.patr;
	cout << "Date of bitrh: ";
	cin >> buf.birth.day >> buf.birth.month >> buf.birth.year;
	cout << "Gender: ";
	cin >> buf.gemder;
	cout << "Address: ";
	cin >> buf.address;
	cout << "Full name of student's father: ";
	cin >> buf.father.surname >> buf.father.name >> buf.father.patr;
	cout << "Full name of student's mother: ";
	cin >> buf.mother.surname >> buf.mother.name >> buf.mother.patr;
	cout << "Group code: ";
	cin >> buf.idg;
	cout << "Additional information: ";
	cin >> buf.dop_info;

	// Проверка количества данных
	if (count == 0) {
		count++;
		data = new Student[count];
	}
	else {
		// Временный массив
		Student* arB = new Student[count];

		// Переносим данные в временный массив
		Copy(count, data, arB, -1);

		// Выделяем новую память
		count++;
		data = new Student[count]; // данные будут потеряны, для этого нужен временный массив

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

void Students::Edit()
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
	cout << "Full name of student: ";
	cin >> data[index].fullname.surname >> data[index].fullname.name >> data[index].fullname.patr;
	cout << "Date of bitrh: ";
	cin >> data[index].birth.day >> data[index].birth.month >> data[index].birth.year;
	cout << "Gender: ";
	cin >> data[index].gemder;
	cout << "Address: ";
	cin >> data[index].address;
	cout << "Full name of student's father: ";
	cin >> data[index].father.surname >> data[index].father.name >> data[index].father.patr;
	cout << "Full name of student's mother: ";
	cin >> data[index].mother.surname >> data[index].mother.name >> data[index].mother.patr;
	cout << "Group code: ";
	cin >> data[index].idg;
	cout << "Additional information: ";
	cin >> data[index].dop_info;

	system("cls");
	cout << "Data changed!" << endl;
}

void Students::Del()
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
	Student* arB = new Student[count];

	// Переносим данные в временный массив
	Copy(count, data, arB, -1);

	// Выделяем новую память
	count--;
	data = new Student[count]; // данные будут потеряны, для этого нужен временный массив

	// Возвращаем данные
	Copy(count + 1, arB, data, index); // кроме элемента с номером index 

	// Удаление временного массива
	delete[] arB;

	system("cls");
	cout << "Data deleted!" << endl;
}

void Students::Save()
{
	// Проверка данных
	if (count == 0) {
		cout << "Data is empty!" << endl;
		return;
	}

	// Поток для записи
	ofstream save("Students.txt", ios::out);

	// Сохранение данных
	save << count << endl;

	for (int i = 0; i < count; i++) {
		save << data[i].fullname.surname << " ";
		save << data[i].fullname.name << " ";
		save << data[i].fullname.patr << " ";
		save << data[i].birth.day << " ";
		save << data[i].birth.month << " ";
		save << data[i].birth.year << " ";
		save << data[i].gemder << " ";
		save << data[i].address << " ";
		save << data[i].father.surname << " ";
		save << data[i].father.name << " ";
		save << data[i].father.patr << " ";
		save << data[i].mother.surname << " ";
		save << data[i].mother.name << " ";
		save << data[i].mother.patr << " ";
		save << data[i].idg << " ";
		save << data[i].dop_info;

		if (i < count - 1)
			save << endl;
	}

	save.close();
	cout << "Data saved in file: Students.txt " << endl;
}

void Students::Load()
{
	// Поток для чтения
	ifstream load("Students.txt");

	// Проверка файла 
	if (!load) {
		cout << "File open error: Students.txt";
		return;
	}

	// Очищаем данные, если массив не пуст
	if (count != 0)
		Clear();

	// Чтение данных
	load >> count;
	data = new Student[count];

	for (int i = 0; i < count; i++) {
		load >> data[i].fullname.surname;
		load >> data[i].fullname.name;
		load >> data[i].fullname.patr;
		load >> data[i].birth.day;
		load >> data[i].birth.month;
		load >> data[i].birth.year;
		load >> data[i].gemder;		
		load >> data[i].address;
		load >> data[i].father.surname;
		load >> data[i].father.name;
		load >> data[i].father.patr;
		load >> data[i].mother.surname;
		load >> data[i].mother.name;
		load >> data[i].mother.patr;
		load >> data[i].idg;
		load >> data[i].dop_info;
	}

	load.close();
	cout << "Data read from file: Students.txt" << endl;
}

void Students::Print()
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

void Students::Print(Student d)
{
	cout << "Full name of student: " << d.fullname.surname << " " << d.fullname.name << " " << d.fullname.patr << endl;
	cout << "Date of bitrh: " << d.birth.day << "." << d.birth.month << "." << d.birth.year << endl;
	cout << "Gender: " << d.gemder << endl;
	cout << "Address: " << d.address << endl;
	cout << "Full name of student's father: " << d.father.surname << " " << d.father.name << " " << d.father.patr << endl;
	cout << "Full name of student's mother: " << d.mother.surname << " " << d.mother.name << " " << d.mother.patr << endl;
	cout << "Group code: " << d.idg << endl;
	cout << "Additional information: " << d.dop_info << endl;
}

void Students::Menu(int& act)
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

Student Students::GetItem(int i)
{
	// Проверка индекса
	if (i < 0 || i > count - 1) {
		cout << "Wrong number!" << endl;
		return Student();
	}

	return data[i];
}

void Students::Clear()
{
	delete[] data;

	data = new Student[0];
	count = 0;
}