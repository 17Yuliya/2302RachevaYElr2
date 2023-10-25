#include "def.h"

int ReadFile(ifstream& in) {
	int size = 0, tmp;

	if (in.is_open() == 0) { cout << "Ошибка открытия файла." << endl; return 0; }


	while (!in.eof()) {
		if (in >> tmp) size++;
		//size++;
	}

	in.clear();
	in.seekg(0);

	return size;
}

int* CreateArr(int size, ifstream& in) {
	int i = 0;

	if (size == 0) return NULL;

	int* arr = new int[size];

	while (i < size) {
		in >> arr[i];
		i++;
	}
	//cout << size;
	return arr;
}

void OutArr(int* arr, int size, ofstream& out) {

	out << "Полученный массив:\n";

	for (int i = 0; i < size; i++) {
		out << arr[i] << '\n';
	}

	out << "\n\n";
}

void Swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void Clear() { //очищение буфера и игнорирование символов в нем
	cin.clear();
	cin.ignore(cin.rdbuf()->in_avail());
}