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
	cout << "��� � ��������   ���-�� ������   ������� �^2  ����     �����\n";
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
	//������ �������� ���������
	cout << "������� ��������� �������� ��������: \n";
	cout << "�������� ���������� ������: ";
	cin >> iwih.iv_room;
	cout << "�������� �������: ";
	cin >> iwih.iv_sqr;
	cout << "�������� ����: ";
	cin >> iwih.iv_floor;
	//������ ���������� � ��������� ��������
	cout << "������� ��������� ����� ��������: \n";
	cout << "���� ��� � ��������: ";
	cin >> newby.name_of_owner_1;
	cin >> newby.name_of_owner_2;
	cout << "���������� ������ � ����� ��������: ";
	cin >> newby.count_of_rooms;
	cout << "������� ����� ��������: ";
	cin >> newby.square;
	cout << "���� ����� ��������: ";
	cin >> newby.floor;
	cout << "����� ����� ��������: ";
	cin >> newby.district;
	// ���� ������������� ���������� � ��� ��������� ��������� � ��������� ��� ����������, �������� �� �������� ���������
	for (int iter = 0; iter != rooms.size(); iter++) {
		if (rooms[iter] == iwih.iv_room and floors[iter] == iwih.iv_floor) {
			if (iwih.iv_sqr - iwih.iv_sqr * 0.1 < sqrs[iter] < iwih.iv_sqr + iwih.iv_sqr * 0.1) {
				chek = 1;
				cout << "�� ������ ������� ������� ��������: ";
				cout << names[iter] << " " << rooms[iter] << " " << sqrs[iter] << " " << floors[iter] << " " << dists[iter] << "\n";
				Interface::Delete(iter); // �������� ������� ��� �������� �� ���� ������ ����������� ��������
				break;
			}
		}
	}
	if (chek == 0) {
		cout << "�� ������ ������� ���������� ������� �� �������. \n";
		Interface::AddAppartment(newby.name_of_owner_1, newby.name_of_owner_2, newby.count_of_rooms, newby.square, newby.floor, newby.district);
		//��������� � ����� ���� ������ ��������, ������� ���� ������������
	}
	cout << "\n";
}
void Interface::AddAppartment(string name, string name_2, int room, double sqr, int floor, string dist) {
	// ��������� � ������ ����� ��������
	names.push_back(name + " " + name_2);
	rooms.push_back(room);
	sqrs.push_back(sqr);
	floors.push_back(floor);
	dists.push_back(dist);
}
void Interface::Delete(int iter) {

	// �������� ���������, ������������ �� ���������� ������ ������� � ������������� ���������
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

	random_device rd; // ��� ��� ���������� �������� �� ��������� ��������� �����
	mt19937 gen(rd());

	// ���� ��������� ������� ������, ����� ������� � ����� ������������ ��������� �������
	string name_1_r[14] = { "Akinin","Ivanov", "Petrov", "Sidorov", "Vladimirov", "Procenko", "Kolesnikov", "Pyras", "Madaev", "Sidorova", "Menchikova", "Tatianina", "Sidorova", "Petrova" };
	string name_2_1_r[15] = { "A.", "B.", "C.", "D.", "E.", "F.", "G.", "H.", "I.", "J.", "K.", "L.", "M.", "N.", "O." };
	string name_2_2_r[15] = { "A.", "B.", "C.", "D.", "P.", "R.", "S.", "T.", "U.", "V.", "W.", "X.", "Z.", "Q.", "Y." };
	int rooms_count_r[3] = { 1, 2, 3 };
	int floors_r[4] = { 1, 2, 3, 4 };
	string dists_r[5] = { "Center", "South", "North", "West", "East" };

	// ������� ��������� ���������� �� ����� ����������
	uniform_int_distribution<> rand_nam_1(0, 13);
	uniform_int_distribution<> rand_nam_2_1(0, 14);
	uniform_int_distribution<> rand_nam_2_2(0, 14);
	uniform_int_distribution<> rand_rooms_count(0, 2);
	uniform_int_distribution<> rand_sqrs_1(30, 50);
	uniform_int_distribution<> rand_sqrs_2(40, 70);
	uniform_int_distribution<> rand_sqrs_3(60, 90);
	uniform_int_distribution<> rand_floors(0, 3);
	uniform_int_distribution<> rand_dists(0, 4);
	// ���� �� ������ �� ���������� ����, ������� ���� ������������
	for (int i = 1; i <= count; i++) {
		// ��������� � ������ ����� ��������
		names.push_back(name_1_r[rand_nam_1(gen)] + " " + name_2_1_r[rand_nam_2_1(gen)] + name_2_2_r[rand_nam_2_2(gen)]); // ��������� � ������ ����� ��������
		int rm = rand_rooms_count(gen);
		rooms.push_back(rooms_count_r[rm]);

		// ������� �������, ����� ������� �������� ���� ���������� � ������������
		if (rm == 0) {
			sqrs.push_back(rand_sqrs_1(gen));
		}
		if (rm == 1) {
			sqrs.push_back(rand_sqrs_2(gen));
		}
		if (rm == 2) {
			sqrs.push_back(rand_sqrs_3(gen));
		}

		// ��������� � ������ ����� ��������
		floors.push_back(floors_r[rand_floors(gen)]);
		dists.push_back(dists_r[rand_dists(gen)]);
	}
	cout << "�������� ������� ������� �������������.\n";
}
void Interface::File_in() {
	ofstream file;
	file.open("Appartments_base.txt");// ��������� ���� ��� ������
	if (file.is_open())
	{
		for (int i = 0; i != names.size(); i++) {
			//���������� � ���� ������ � �������
			file << names[i] << "\n";
			file << rooms[i] << "\n";
			file << sqrs[i] << "\n";
			file << floors[i] << "\n";
			file << dists[i] << "\n";
		}
	}
	file.close(); // ��������� ����
}
void Interface::File_out() {
	ifstream file;
	string line;
	int cnt = 1; // ������� ����� ������ ������������ ��������
	int dooo = 0; // ������� ���������� ������������� ��� ����, ����� �� ������ �������� ������
	file.open("Appartments_base.txt");// ��������� ���� ��� ����������
	if (file.is_open())
	{
		while (getline(file, line))
		{
			if (cnt == 1 and dooo == 0) { // ���������� ���
				names.push_back(line);
				cnt += 1;
				dooo = 1;
			}
			if (cnt == 2 and dooo == 0) { // ���������� ���������� ������
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
			if (cnt == 3 and dooo == 0) { // ���������� �������
				for (int i = 10; i < 110; i++) {
					if (line == to_string(i)) {
						sqrs.push_back(i);
					}
				}
				cnt += 1;
				dooo = 1;
			}
			if (cnt == 4 and dooo == 0) { // ���������� ����
				for (int i = 1; i < 20; i++) {
					if (line == to_string(i)) {
						floors.push_back(i);
					}
				}
				cnt += 1;
				dooo = 1;
			}
			if (cnt == 5 and dooo == 0) { // ���������� �����
				dists.push_back(line);
				cnt = 1;
				dooo = 1;
			}
			dooo = 0;
		}
	}
	file.close(); // ��������� ����
}