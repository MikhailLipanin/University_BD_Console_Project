#include "Data.h"

Data::Data()
{
}

Data::~Data()
{
	delete[] request_1;
	delete[] request_2;
	delete[] request_3;
	delete[] request_4;
}

void Data::MainMenu(int& act)
{
	cout << "Select mode: " << endl
		<< "0 - Exit" << endl
		<< "1 - Employees" << endl
		<< "2 - Positions " << endl
		<< "3 - Groups " << endl
		<< "4 - Lessons" << endl
		<< "5 - Students" << endl
		<< "6 - Schedule" << endl
		<< "7 - Filters" << endl
		<< "Write a number: ";
	cin >> act;

	system("cls");
}

void Data::LoadAll()
{
	LoadEmployees();
	LoadPossitions();
	LoadLessons();
	LoadGroups();
	LoadStudents();
	LoadSchedules();
}

void Data::Query_1()
{
	// Загрузка всех данных
	LoadAll();

	count_R1 = 0;

	// Считаем количество соответствий
	for (int i = 0; i < e.Count(); i++) {
		for (int j = 0; j < p.Count(); j++) {
			if (e.GetItem(i).idPosition == p.GetItem(j).id) {
				count_R1++;
				break;
			}
		}
	}

	// Выделяем память
	request_1 = new HRDepartment[count_R1];

	// Заполняем данные
	int q = 0;
	for (int i = 0; i < e.Count(); i++) {
		for (int j = 0; j < p.Count(); j++) {
			if (e.GetItem(i).idPosition == p.GetItem(j).id) {
				request_1[q].e = e.GetItem(i);
				request_1[q++].p = p.GetItem(j);
				break;
			}
		}
	}

	cout << "Request \"HRDepartment\" completed!" << endl;
}

void Data::Query_2()
{
	// Загрузка все данных
	LoadAll();

	count_R2 = 0;

	// Считаем количество соответствий
	for (int i = 0; i < s.Count(); i++) {
		for (int j = 0; j < g.Count(); j++) {
			if (s.GetItem(i).idg == g.GetItem(j).id) {
				count_R2++;
				break;
			}
		}
	}

	// Выделяем память
	request_2 = new ListOfStudents[count_R2];

	// Заполняем данные
	int q = 0;
	for (int i = 0; i < s.Count(); i++) {
		for (int j = 0; j < g.Count(); j++) {
			if (s.GetItem(i).idg == g.GetItem(j).id) {
				request_2[q].s = s.GetItem(i);
				request_2[q++].g = g.GetItem(j);
				break;
			}
		}
	}

	cout << "Request \"List Of Students\" completed!" << endl;
}

void Data::Query_3()
{
	// Загрузка все данных
	LoadAll();

	count_R3 = 0;

	// Считаем количество соответствий
	for (int i = 0; i < l.Count(); i++) {
		for (int j = 0; j <	e.Count(); j++) {
			if (l.GetItem(i).prep == e.GetItem(j).id) {
				count_R3++;
				break;
			}
		}
	}

	// Выделяем память
	request_3 = new ListOfLessons[count_R3];

	// Заполняем данные
	int q = 0;
	for (int i = 0; i < l.Count(); i++) {
		for (int j = 0; j < e.Count(); j++) {
			if (l.GetItem(i).prep == e.GetItem(j).id) {
				request_3[q].l = l.GetItem(i);
				request_3[q++].e = e.GetItem(j);
				break;
			}
		}
	}

	cout << "Request \"List Of Lessons\" completed!" << endl;
}

void Data::Query_4()
{
	// Загрузка все данных
	LoadAll();

	count_R4 = 0;

	// Считаем количество соответствий
	for (int i = 0; i < sc.Count(); i++) {
		int check = count_R4;
		for (int j = 0; j < l.Count(); j++) {
			if (sc.GetItem(i).idl == l.GetItem(j).id) {
				count_R4++;
				break;
			}
		}
		if (check == count_R4) {
			for (int j = 0; j < g.Count(); j++) {
				if (sc.GetItem(i).idg == g.GetItem(j).id) {
					count_R4++;
					break;
				}
			}
		}
	}

	// Выделяем память
	request_4 = new ListOfSchedule[count_R4];

	// Заполняем данные
	int q = 0;
	for (int i = 0; i < sc.Count(); i++) {
		bool fl = 0;
		for (int j = 0; j < l.Count(); j++) {
			if (sc.GetItem(i).idl == l.GetItem(j).id) {
				request_4[q++].sc = sc.GetItem(i);
				fl = 1;
				break;
			}
		}
		if (!fl) {
			for (int j = 0; j < g.Count(); j++) {
				if (sc.GetItem(i).idg == g.GetItem(j).id) {
					request_4[q++].sc = sc.GetItem(i);
					break;
				}
			}
		}
	}

	cout << "Request \"ListOfSchedule\" completed!" << endl;
}

void Data::Print(HRDepartment d)
{
	cout << "Fullname: " << d.e.fullname.surname << " " << d.e.fullname.name << " " << d.e.fullname.patr << endl;
	cout << "Age: " << d.e.age << endl;
	cout << "Gender: " << d.e.gemder << endl;
	cout << "Address: " << d.e.address << endl;
	cout << "Phone number: " << d.e.phoneNum << endl;
	cout << "Passport data (**** ******): " << d.e.passport.series << " " << d.e.passport.number << endl;
}

void Data::Print(ListOfStudents d)
{
	cout << "Full name of student: " << d.s.fullname.surname << " " << d.s.fullname.name << " " << d.s.fullname.patr << endl;
	cout << "Date of bitrh: " << d.s.birth.day << "." << d.s.birth.month << "." << d.s.birth.year << endl;
	cout << "Gender: " << d.s.gemder << endl;
	cout << "Address: " << d.s.address << endl;
	cout << "Full name of student's father: " << d.s.father.surname << " " << d.s.father.name << " " << d.s.father.patr << endl;
	cout << "Full name of student's mother: " << d.s.mother.surname << " " << d.s.mother.name << " " << d.s.mother.patr << endl;
	cout << "Group code: " << d.s.idg << endl;
	cout << "Additional information: " << d.s.dop_info << endl;
}

void Data::Print(ListOfLessons d)
{
	cout << "Lesson id: " << d.l.id << endl;
	cout << "Lesson name: " << d.l.name << endl;
	cout << "Lesson description: " << d.l.desc << endl;
	cout << "Teacher employee code: " << d.l.prep << endl;
}

void Data::Print(ListOfSchedule d)
{
	cout << "Lesson date: " << d.sc.date.day << "." << d.sc.date.month << "." << d.sc.date.year << endl;
	cout << "Day of week (1 - 7): " << d.sc.day << endl;
	cout << "Group number: " << d.sc.idg << endl;
	cout << "Lesson number: " << d.sc.idl << endl;
	cout << "Start time: " << d.sc.tmbe.be << ":" << d.sc.tmbe.en << endl;
	cout << "End time: " << d.sc.tmen.be << ":" << d.sc.tmen.en << endl;;
}

void Data::MenuFiltration(int& act)
{
	cout << "Select a filter: " << endl
		<< "0 - Back" << endl
		<< "1 - Filter for displaying employees of individual positions " << endl
		<< "2 - Filter for displaying groups of different years of study " << endl
		<< "3 - Filter for displaying schedules for individual groups and dates " << endl
		<< "4 - Filters for displaying students of individual groups " << endl
		<< "5 - Filters for displaying lessons of individual teachers" << endl
		<< "Write a number: ";
	cin >> act;

	system("cls");
}

void Data::Filtrarions()
{
	int act = 0;

	// Пока не выйти назад 
	do {
		// Выбор фильтра
		MenuFiltration(act);

		switch (act)
		{
		case 0:
			break;

		case 1:
			Filtr_1();
			break;

		case 2:
			Filtr_2();
			break;

		case 3:
			Filtr_3();
			break;
			
		case 4:
			Filtr_4();
			break;

		case 5:
			Filtr_5();
			break;

		default:
			cout << "Wrong number!" << endl;
			break;
		}

		system("pause"); // задержка консоли
		system("cls"); // очистка консоли
	} while (act != 0);
}

void Data::Filtr_1()
{
	// Выполнение запроса
	Query_1();
	system("pause");
	system("cls");

	string str;
	cout << "Write a position: ";
	cin >> str;
	cout << endl;

	bool found = false; // пока что ничего не нашли

	// Поиск
	for (int i = 0; i < count_R1; i++) {
		if (str == request_1[i].p.name) {
			found = true;

			Print(request_1[i]);
			cout << endl;
		}
	}

	if (!found)
		cout << "No matches found!" << endl;
}

void Data::Filtr_2()
{
	// Выполнение запроса
	Query_2();
	system("pause");
	system("cls");

	cout << "In the statements there is no request for a list of groups, which need for this filter!" << endl;
	return;

	//string str;
	//cout << " ";
	//cin >> str;
	//cout << endl;

	//bool found = false; // пока что ничего не нашли

	//// Поиск
	//for (int i = 0; i < count_R2; i++) {
	//	if (str == request_2[i].d.symptoms) {
	//		found = true;

	//		Print(request_2[i]);
	//		cout << endl;
	//	}
	//}

	//if (!found)
	//	cout << "No match found!" << endl;
}

void Data::Filtr_3()
{
	// Выполнение запроса
	Query_4();
	system("pause");
	system("cls");

	cout << "Which filter you want: group or date (g / d)? ";
	char cc;
	cin >> cc;
	cout << endl;
	if (cc == 'g') {
		cout << "Write number of group: ";
		int gg;
		cin >> gg;
		cout << endl;
		bool found = 0;
		for (int i = 0; i < count_R4; i++) {
			if (gg == request_4[i].sc.idg) {
				found = true;
				Print(request_4[i]);
				cout << endl;
			}
		}
		if (!found)
			cout << "No matches found!" << endl;
	}
	else if (cc == 'd') {
		cout << "Write date in schedule (dd mm yy): ";
		int x, y, z;
		cin >> x >> y >> z;
		cout << endl;
		bool found = 0;
		for (int i = 0; i < count_R4; i++) {
			if (x == request_4[i].sc.date.day && y == request_4[i].sc.date.month && z == request_4[i].sc.date.year) {
				found = true;
				Print(request_4[i]);
				cout << endl;
			}
		}
		if (!found)
			cout << "No matches found!" << endl;
	}
	else {
		cout << "Wrong input!" << endl;
	}
}

void Data::Filtr_4()
{
	// Выполнение запроса
	Query_2();
	system("pause");
	system("cls");

	int x;
	cout << "Write a group number: ";
	cin >> x;
	cout << endl;

	bool found = false; // пока что ничего не нашли

	// Поиск
	for (int i = 0; i < count_R2; i++) {
		if (x == request_2[i].s.idg) {
			found = true;

			Print(request_2[i]);
			cout << endl;
		}
	}

	if (!found)
		cout << "No matches found!" << endl;
}

void Data::Filtr_5()
{
	// Выполнение запроса
	Query_3();
	system("pause");
	system("cls");

	int x;
	cout << "Write a teacher's id: ";
	cin >> x;
	cout << endl;

	bool found = false; // пока что ничего не нашли

	// Поиск
	for (int i = 0; i < count_R3; i++) {
		if (x == request_3[i].l.prep) {
			found = true;

			Print(request_3[i]);
			cout << endl;
		}
	}

	if (!found)
		cout << "No matches found!" << endl;
}