#include <iostream>
#include <string>
#include <vector>
#include <random>
#include "Interface+.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");
	Interface do_somesing;
	do_somesing.File_out();//считываем из файла
	int num_of_move;
	cout << "Нажмите 1, чтобы ввести заявку на обмен и найти подходящую.\nНажмите 2, чтобы вывести весь список доступных квартир.\nНажмите 3, чтобы сгенерировать карточки квартир.\nНажмите 0, чтобы закончить работу программы.\n";
	do { // используем do-while, потому что нам нужно хотя бы один раз выполнить действие внутри. Взаимодействие с меню реализуем через бесконечный цикл
		cout << "Введите номер действия >>> ";
		cin >> num_of_move; // вводим переменную для выбора действия
		switch (num_of_move)
		{
		case 1:
			do_somesing.Show_suitable(); // вызов функции
			break;
		case 2:
			do_somesing.Show_all(); // вызов функции
			break;
		case 3:
			cout << "Введите количество карточек для генерации: ";
			int count_of_cards; // переменная отвечает за количество сгенерированных карт
			cin >> count_of_cards;
			do_somesing.Gen_of_Cards(count_of_cards); // вызов функц
			break;
		case 0:
			cout << "Заканчиваем работу... ";
			break;
		default:
			cout << "Кажется вы ввели неправильное число, попробуйте еще раз. \n"; // проверка на ошибку пользователя
			break;
		}
		
	} while (num_of_move != 0); // проверяем не выбрал ли пользователь вариант с завершением работы кода
	do_somesing.File_in();//записываем в файл
}
