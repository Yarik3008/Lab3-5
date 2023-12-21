#include <iostream>
#include "MyStack.h"
using namespace std;

int main(int argc, char** argv) {
	setlocale(LC_ALL, "Russian");

	size_t size, op;
	int el;
	try {
		cout << "Введите размер стека: ";
		cin >> size;
		TStack<int> s(size);
		while (true) {
			cout << "Меню:\n"
				<< "1. Добавить в стек\n"
				<< "2. Удалить элемент\n"
				<< "3. Верхний элемент\n"
				<< "4. Количество элементов\n"
				<< "5. Размер\n"
				<< "Ввести операцию: ";
			cin >> op;
			cout << endl;
			switch (op) {
			case 1:
				cout << "Введите элемент (int): ";
				cin >> el;
				s.Push(el);
				break;
			case 2:
				s.Get();
				break;
			case 3:
				cout << s.TopView() << endl;
				break;
			case 4:
				cout << s.GetTop() << endl;
				break;
			case 5:
				cout << s.GetSize() << endl;
				break;
			default:
				break;
			}

			cout << s << endl;
		}
	}
	catch (exception e) {
		cerr << e.what() << endl;
	}
}
