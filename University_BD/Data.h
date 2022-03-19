#pragma once
#include "Schedules.h"

// Структура данных запроса Отдел кадров
struct HRDepartment
{
	Employee e;
	Possition p;
};

// Структура данных запроса Студенты
struct ListOfStudents
{
	Student s;
	Group g;
};

// Структура данных запроса Предметы
struct ListOfLessons
{
	Lesson l;
	Employee e;
};

// Структура данных запроса Расписание занятий
struct ListOfSchedule
{
	Schedule sc;
	Group g;
	Lesson l;
};

class Data
{
	// Поля класса
private: // закрытая часть
	Employees e;
	Possitions p;
	Lessons l;
	Groups g;
	Students s;
	Schedules sc;

	// Данные запроса 1
	HRDepartment* request_1;
	int count_R1;

	// Данные запроса 2
	ListOfStudents* request_2;
	int count_R2;

	// Данные запроса 3
	ListOfLessons* request_3;
	int count_R3;

	// Данные запроса 4
	ListOfSchedule* request_4;
	int count_R4;

	// Методы класса
public: // открытая часть
	Data(); // конструктор по умолчанию - создает пустой объект класса
	~Data(); // деструктор - удаляет объект класса

	void MainMenu(int& act);

	// Действия над отдельными объектами:
	void MenuEmployees(int& act) { e.Menu(act); }
	void AddEmployees() { e.Add(); }
	void PrintEmployees() { e.Print(); }
	void EditEmployees() { e.Edit(); }
	void DelEmployees() { e.Del(); }
	void SaveEmployees() { e.Save(); }
	void LoadEmployees() { e.Load(); }

	void MenuPossitions(int& act) { p.Menu(act); }
	void AddPossitions() { p.Add(); }
	void PrintPossitions() { p.Print(); }
	void EditPossitions() { p.Edit(); }
	void DelPossitions() { p.Del(); }
	void SavePossitions() { p.Save(); }
	void LoadPossitions() { p.Load(); }

	void MenuLessons(int& act) { l.Menu(act); }
	void AddLessons() { l.Add(); }
	void PrintLessons() { l.Print(); }
	void EditLessons() { l.Edit(); }
	void DelLessons() { l.Del(); }
	void SaveLessons() { l.Save(); }
	void LoadLessons() { l.Load(); }

	void MenuGroups(int& act) { g.Menu(act); }
	void AddGroups() { g.Add(); }
	void PrintGroups() { g.Print(); }
	void EditGroups() { g.Edit(); }
	void DelGroups() { g.Del(); }
	void SaveGroups() { g.Save(); }
	void LoadGroups() { g.Load(); }

	void MenuStudents(int& act) { s.Menu(act); }
	void AddStudents() { s.Add(); }
	void PrintStudents() { s.Print(); }
	void EditStudents() { s.Edit(); }
	void DelStudents() { s.Del(); }
	void SaveStudents() { s.Save(); }
	void LoadStudents() { s.Load(); }

	void MenuSchedules(int& act) { sc.Menu(act); }
	void AddSchedules() { sc.Add(); }
	void PrintSchedules() { sc.Print(); }
	void EditSchedules() { sc.Edit(); }
	void DelSchedules() { sc.Del(); }
	void SaveSchedules() { sc.Save(); }
	void LoadSchedules() { sc.Load(); }

	void LoadAll();

	// Запросы:
	void Query_1();
	void Query_2();
	void Query_3();
	void Query_4();

	void Print(HRDepartment d);
	void Print(ListOfStudents d);
	void Print(ListOfLessons d);
	void Print(ListOfSchedule d);

	// Фильтры 
	void MenuFiltration(int& act);
	void Filtrarions();
	void Filtr_1();
	void Filtr_2();
	void Filtr_3();
	void Filtr_4();
	void Filtr_5();
};

