#include "infa.h"
#include <fstream>
#include <iostream>
using namespace std;
using namespace TVR;
string tvr::name() {
	return _name;
}
string tvr::color() {
	return _color;
}
int tvr::cost() {
	return _cost;
}
tvr::tvr(string name, string color, int cost) : _name(name), _color(color), _cost(cost) {}
ostream& TVR::operator << (ostream & out, const tvr& f) {
	out << f._name << " " << f._color << " " << f._cost << endl;
	return out;
}
istream& TVR::operator >> (istream & in, tvr& f) {
	in >> f._name >> f._color >> f._cost;
	return in;
}
tvr * TVR::load(int & count) {
	ifstream in("smeta.txt");
	if (!in.is_open())
		return nullptr;
	tvr *arr = new tvr[count];
	for (int i = 0; i < count; i++)
		in >> arr[i];
	in.close();
	return arr;
}
void TVR::create(tvr** arr, int* count) {
	ifstream file("smeta.txt", ios::binary);
	*count = 5;
	*arr = new tvr[*count + 1];
	(*arr)[0] = { "Pen", "Red", 15 };
	(*arr)[1] = { "Book", "Black", 25 };
	(*arr)[2] = { "Lineika", "Wood", 50 };
	(*arr)[3] = { "Karandash", "Gray", 25 };
	(*arr)[4] = { "Reshebnik po mat analizu", "Gold", 1500 };
}
void TVR::save(tvr *arr, int count) {
	ofstream out("smeta.txt");
	out << count << endl;
	for (int i = 0; i < count; i++) {
		out << arr[i] << endl;
	}
	out.close();
}
void TVR::add(tvr** arr, int* count) {
	tvr* temp = new (nothrow) tvr[*count + 1];
	if (temp == nullptr) {
		cout << "Oshibka: ne udalos vydelit pamyat" << endl;
		return;
	}

	for (int i = 0; i < *count; i++) {
		temp[i] = (*arr)[i];
	}
	string name;
	string color;
	int cost;
	cout << "Vvedite nazvanie tovara: " << endl;
	cin >> name;
	cout << "Vvedite color tovara: " << endl;
	cin >> color;
	cout << "Vvedite ego cost: " << endl;
	cin >> cost;
	temp[*count].setName(name);
	temp[*count].setColor(color);
	temp[*count].setCost(cost);
	delete[] * arr;

	*arr = temp;
	(*count)++;
}
void TVR::del(tvr *arr, int *count) {
	int n = 0;
	cout << "Vvedite nomer tovara: " << endl;
	cin >> n;
	if (n < 0, n >= (*count+1)) {
		cout << "Ne nashli " << endl;
		return;
	}

	for (int i = (n-1); i < *count - 1; i++) {
		arr[i] = arr[i + 1];
	}
	(*count)--;
}
void TVR::edit(tvr *arr, int count) {
	int n = 0;
	cout << "Vvedite nomer tovara: " << endl;
	cin >> n;
	if (n < 0, n >= (count + 1)) {
		cout << "Ne nashli" << endl;
		return;
	}
	string temp = "";
	cout << "Vvedite novoe nazvanie: " << endl;
	cin >> temp;
	arr[n-1].setName(temp);
	cout << "Noviy color: " << endl;
	cin >> temp;
	arr[n-1].setColor(temp);
	int cost = 0;
	cout << "Noviy cost: " << endl;
	cin >> cost;
	arr[n-1].setCost(cost);
}
void TVR::search(tvr* arr, int count) {
	string name, color;
	cout << "Vvedite nazvanie tovara: ";
	cin >> name;
	cout << "Vvedite color tovara: ";
	cin >> color;
	for (int i = 0; i < count; i++) {
		if (arr[i].name() == name && arr[i].color() == color) {
			cout << "+++++++++++++++++" << endl;
			cout << "Tovar naiden!" << endl;
			cout << arr[i] << endl;
			cout << "+++++++++++++++++" << endl;
			return;
		}
	}
	cout << "/////////////////" << endl;
	cout << "Ne nashli takogo!" << endl;
	cout << "/////////////////" << endl;
}
void TVR::show(tvr* arr, int count) {
	cout << "---------------------------------------" << endl;
	cout << "Spisok tovarov:" << endl;
	for (int i = 0; i < count; i++) {
		cout << i+1 << ". " << arr[i] << endl;
	}
}
