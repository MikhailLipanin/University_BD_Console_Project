#include "Data.h"

int main() {
	// Локализация консоли
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Russian");

	// Инициализация данных
	Data data;
	int mode = 0;
	int act = 0;

	// Главный цикл программы, пока работать
	do {
		// Выбор действия
		data.MainMenu(mode);

		// Проверка выбора
		switch (mode)
		{
		case 0:
			break;

		case 1:
			// Цикл, пока работать режиму
			do {
				// Выбор действия 
				data.MenuEmployees(act);

				// Проверка выборв
				switch (act)
				{
				case 0:
					break;

				case 1:
					data.PrintEmployees();
					break;

				case 2:
					data.AddEmployees();
					break;

				case 3:
					data.EditEmployees();
					break;

				case 4:
					data.DelEmployees();
					break;

				case 5:
					data.LoadEmployees();
					break;

				case 6:
					data.SaveEmployees();
					break;

				default:
					cout << "Wrong input!" << endl;
					break;
				}

				system("pause"); // задержка консоли
				system("cls"); // очистка консоли
			} while (act != 0);
			break;

		case 2:
			// Цикл, пока работать режиму
			do {
				// Выбор действия 
				data.MenuPossitions(act);

				// Проверка выборв
				switch (act)
				{
				case 0:
					break;

				case 1:
					data.PrintPossitions();
					break;

				case 2:
					data.AddPossitions();
					break;

				case 3:
					data.EditPossitions();
					break;

				case 4:
					data.DelPossitions();
					break;

				case 5:
					data.LoadPossitions();
					break;

				case 6:
					data.SavePossitions();
					break;

				default:
					cout << "Wrong input!" << endl;
					break;
				}

				system("pause"); // задержка консоли
				system("cls"); // очистка консоли
			} while (act != 0);
			break;

		case 3:
			// Цикл, пока работать режиму
			do {
				// Выбор действия 
				data.MenuGroups(act);

				// Проверка выборв
				switch (act)
				{
				case 0:
					break;

				case 1:
					data.PrintGroups();
					break;

				case 2:
					data.AddGroups();
					break;

				case 3:
					data.EditGroups();
					break;

				case 4:
					data.DelGroups();
					break;

				case 5:
					data.LoadGroups();
					break;

				case 6:
					data.SaveGroups();
					break;

				default:
					cout << "Wrong input!" << endl;
					break;
				}

				system("pause"); // задержка консоли
				system("cls"); // очистка консоли
			} while (act != 0);
			break;

		case 4:
			// Цикл, пока работать режиму
			do {
				// Выбор действия 
				data.MenuLessons(act);

				// Проверка выборв
				switch (act)
				{
				case 0:
					break;

				case 1:
					data.PrintLessons();
					break;

				case 2:
					data.AddLessons();
					break;

				case 3:
					data.EditLessons();
					break;

				case 4:
					data.DelLessons();
					break;

				case 5:
					data.LoadLessons();
					break;

				case 6:
					data.SaveLessons();
					break;

				default:
					cout << "Wrong input!" << endl;
					break;
				}

				system("pause"); // задержка консоли
				system("cls"); // очистка консоли
			} while (act != 0);
			break;

		case 5:
			// Цикл, пока работать режиму
			do {
				// Выбор действия 
				data.MenuStudents(act);

				// Проверка выборв
				switch (act)
				{
				case 0:
					break;

				case 1:
					data.PrintStudents();
					break;

				case 2:
					data.AddStudents();
					break;

				case 3:
					data.EditStudents();
					break;

				case 4:
					data.DelStudents();
					break;

				case 5:
					data.LoadStudents();
					break;

				case 6:
					data.SaveStudents();
					break;

				default:
					cout << "Wrong input!" << endl;
					break;
				}

				system("pause"); // задержка консоли
				system("cls"); // очистка консоли
			} while (act != 0);
			break;

		case 6:
			// Цикл, пока работать режиму
			do {
				// Выбор действия 
				data.MenuSchedules(act);

				// Проверка выборв
				switch (act)
				{
				case 0:
					break;

				case 1:
					data.PrintSchedules();
					break;

				case 2:
					data.AddSchedules();
					break;

				case 3:
					data.EditSchedules();
					break;

				case 4:
					data.DelSchedules();
					break;

				case 5:
					data.LoadSchedules();
					break;

				case 6:
					data.SaveSchedules();
					break;

				default:
					cout << "Wrong input!" << endl;
					break;
				}

				system("pause"); // задержка консоли
				system("cls"); // очистка консоли
			} while (act != 0);
			break;

		case 7:
			data.Filtrarions();
			break;

		default:
			cout << "Wrong input!" << endl;
			break;
		}

		system("pause"); // задержка консоли
		system("cls"); // очистка консоли
	} while (mode != 0);
}