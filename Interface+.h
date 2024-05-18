#pragma once
#include <iostream>
using namespace std;

class Interface {
public:
	void Show_all();
	void Show_suitable();
	void Gen_of_Cards(int);
	void File_in();
	void File_out();
private:
	vector<string> names;
	vector<int> rooms;
	vector<double> sqrs;
	vector<int> floors;
	vector<string> dists;
	void AddAppartment(string, string, int, double, int, string);
	void Delete(int);
};

