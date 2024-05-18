#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <fstream>
#include <stdlib.h>

#include "Interface+.h"

using namespace std;

class I_want {
public:
	int iv_room;
	double iv_sqr;
	int iv_floor;
};
class Appartment {
public:
	string name_of_owner_1;
	string name_of_owner_2;
	int count_of_rooms;
	double square;
	int floor;
	string district;
};

void Interface::Show_all() {
	cout << "\n";
	cout << "Имя и инициалы   Кол-во комнат   Площадь м^2  Этаж     Район\n";
	for (int iter = 0; iter != rooms.size(); iter++) {
		cout << names[iter] << "\t\t" << rooms[iter] << "\t     " << sqrs[iter] << "\t\t" << floors[iter] << "      " << dists[iter] << "\n";
	}
	cout << "\n";
}
void Interface::Show_suitable() {
	cout << "\n";
	int chek = 0;
	I_want iwih;
	Appartment newby;
	//вводим желаемые параметры
	cout << "Введите параметры желаемой квартиры: \n";
	cout << "Желаемое количество комнат: ";
	cin >> iwih.iv_room;
	cout << "Желаемая площадь: ";
	cin >> iwih.iv_sqr;
	cout << "Желаемый этаж: ";
	cin >> iwih.iv_floor;
	//вводим информацию о имеющейся квартире
	cout << "Введите параметры вашей квартиры: \n";
	cout << "Ваше имя и инициалы: ";
	cin >> newby.name_of_owner_1;
	cin >> newby.name_of_owner_2;
	cout << "Количество комнат в вашей квартире: ";
	cin >> newby.count_of_rooms;
	cout << "Площадь вашей квартиры: ";
	cin >> newby.square;
	cout << "Этаж вашей квартиры: ";
	cin >> newby.floor;
	cout << "Район вашей квартиры: ";
	cin >> newby.district;
	// цикл обарабатывает информацию о уже имеющихся квартирах и подбирает нам подходящую, опираясь на желаемые параметры
	for (int iter = 0; iter != rooms.size(); iter++) {
		if (rooms[iter] == iwih.iv_room and floors[iter] == iwih.iv_floor) {
			if (iwih.iv_sqr - iwih.iv_sqr * 0.1 < sqrs[iter] < iwih.iv_sqr + iwih.iv_sqr * 0.1) {
				chek = 1;
				cout << "По вашему запросу найдена квартира: ";
				cout << names[iter] << " " << rooms[iter] << " " << sqrs[iter] << " " << floors[iter] << " " << dists[iter] << "\n";
				Interface::Delete(iter); // вызываем функцию для удаления из базы данных подходящего варианта
				break;
			}
		}
	}
	if (chek == 0) {
		cout << "По вашему запросу подходящих квартир не найдено. \n";
		Interface::AddAppartment(newby.name_of_owner_1, newby.name_of_owner_2, newby.count_of_rooms, newby.square, newby.floor, newby.district);
		//добавляем в общую базу данных квартиру, которую ввел пользователь
	}
	cout << "\n";
}
void Interface::AddAppartment(string name, string name_2, int room, double sqr, int floor, string dist) {
	// добавляем в вектор новый эллемент
	names.push_back(name + " " + name_2);
	rooms.push_back(room);
	sqrs.push_back(sqr);
	floors.push_back(floor);
	dists.push_back(dist);
}
void Interface::Delete(int iter) {

	// удаление эллемента, ориентируясь на указателль начала вектора и передаваемого итератора
	auto delete_iter_names = names.begin();
	names.erase(delete_iter_names + iter);
	auto delete_iter_rooms = rooms.begin();
	rooms.erase(delete_iter_rooms + iter);
	auto delete_iter_sqrs = sqrs.begin();
	sqrs.erase(delete_iter_sqrs + iter);
	auto delete_iter_floors = floors.begin();
	floors.erase(delete_iter_floors + iter);
	auto delete_iter_dists = dists.begin();
	dists.erase(delete_iter_dists + iter);

}
void Interface::Gen_of_Cards(int count) {

	random_device rd; // эти две переменные отвечают за генерацию рандомных чисел
	mt19937 gen(rd());

	// ниже находятся массивы данных, среди которых и будет производится рандомная выборка
	string name_1_r[14] = { "Akinin","Ivanov", "Petrov", "Sidorov", "Vladimirov", "Procenko", "Kolesnikov", "Pyras", "Madaev", "Sidorova", "Menchikova", "Tatianina", "Sidorova", "Petrova" };
	string name_2_1_r[15] = { "A.", "B.", "C.", "D.", "E.", "F.", "G.", "H.", "I.", "J.", "K.", "L.", "M.", "N.", "O." };
	string name_2_2_r[15] = { "A.", "B.", "C.", "D.", "P.", "R.", "S.", "T.", "U.", "V.", "W.", "X.", "Z.", "Q.", "Y." };
	int rooms_count_r[3] = { 1, 2, 3 };
	int floors_r[4] = { 1, 2, 3, 4 };
	string dists_r[5] = { "Center", "South", "North", "West", "East" };

	// создаем рандомные генераторы со своим диапазоном
	uniform_int_distribution<> rand_nam_1(0, 13);
	uniform_int_distribution<> rand_nam_2_1(0, 14);
	uniform_int_distribution<> rand_nam_2_2(0, 14);
	uniform_int_distribution<> rand_rooms_count(0, 2);
	uniform_int_distribution<> rand_sqrs_1(30, 50);
	uniform_int_distribution<> rand_sqrs_2(40, 70);
	uniform_int_distribution<> rand_sqrs_3(60, 90);
	uniform_int_distribution<> rand_floors(0, 3);
	uniform_int_distribution<> rand_dists(0, 4);
	// цикл от одного до количества карт, которое ввел пользователь
	for (int i = 1; i <= count; i++) {
		// добавляем в вектор новый эллемент
		names.push_back(name_1_r[rand_nam_1(gen)] + " " + name_2_1_r[rand_nam_2_1(gen)] + name_2_2_r[rand_nam_2_2(gen)]); // добавляем в вектор новый эллемент
		int rm = rand_rooms_count(gen);
		rooms.push_back(rooms_count_r[rm]);

		// тройное условие, чтобы площадь квартиры была адекватной и реалистичной
		if (rm == 0) {
			sqrs.push_back(rand_sqrs_1(gen));
		}
		if (rm == 1) {
			sqrs.push_back(rand_sqrs_2(gen));
		}
		if (rm == 2) {
			sqrs.push_back(rand_sqrs_3(gen));
		}

		// добавляем в вектор новый эллемент
		floors.push_back(floors_r[rand_floors(gen)]);
		dists.push_back(dists_r[rand_dists(gen)]);
	}
	cout << "Карточки квартир успешно сгенерированы.\n";
}
void Interface::File_in() {
	ofstream file;
	file.open("Appartments_base.txt");// открываем файл для записи
	if (file.is_open())
	{
		for (int i = 0; i != names.size(); i++) {
			//записываем в файл данные в столбик
			file << names[i] << "\n";
			file << rooms[i] << "\n";
			file << sqrs[i] << "\n";
			file << floors[i] << "\n";
			file << dists[i] << "\n";
		}
	}
	file.close(); // закрываем файл
}
void Interface::File_out() {
	ifstream file;
	string line;
	int cnt = 1; // счетчик чтобы делать определенные действия
	int dooo = 0; // создаем уникальный идентификатор для того, чтобы не делать действия подряд
	file.open("Appartments_base.txt");// открываем файл для считывания
	if (file.is_open())
	{
		while (getline(file, line))
		{
			if (cnt == 1 and dooo == 0) { // записываем имя
				names.push_back(line);
				cnt += 1;
				dooo = 1;
			}
			if (cnt == 2 and dooo == 0) { // записываем количество комнат
				if (line == "1") {
					rooms.push_back(1);
				}
				if (line == "2") {
					rooms.push_back(2);
				}
				if (line == "3") {
					rooms.push_back(3);
				}
				cnt += 1;
				dooo = 1;
			}
			if (cnt == 3 and dooo == 0) { // записываем площадь
				for (int i = 10; i < 110; i++) {
					if (line == to_string(i)) {
						sqrs.push_back(i);
					}
				}
				cnt += 1;
				dooo = 1;
			}
			if (cnt == 4 and dooo == 0) { // записываем этаж
				for (int i = 1; i < 20; i++) {
					if (line == to_string(i)) {
						floors.push_back(i);
					}
				}
				cnt += 1;
				dooo = 1;
			}
			if (cnt == 5 and dooo == 0) { // записываем район
				dists.push_back(line);
				cnt = 1;
				dooo = 1;
			}
			dooo = 0;
		}
	}
	file.close(); // закрываем файл
}