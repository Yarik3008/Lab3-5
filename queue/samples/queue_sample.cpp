#include <iostream>
#include "MyQueue.h"
using namespace std;

int main(int argc, char** argv) {
	setlocale(LC_ALL, "Russian");

	size_t size, op;
	int el;
	try {
		cout << "Введите размер очереди: ";
		cin >> size;
		TQueue<int> q(size);
		while (true) {
			cout << "Меню:\n"
				<< "1. Добавить в очередь\n"
				<< "2. Удалить элемент\n"
				<< "3. Количество элементов\n"
				<< "4. Размер\n"
				<< "5. Начало\n"
				<< "6. Конец\n"
				<< "Ввести операцию: ";
			cin >> op;
			cout << endl;
			switch (op) {
			case 1:
				cout << "Введите элемент (int): ";
				cin >> el;
				q.Push(el);
				break;
			case 2:
				cout << q.Get() << endl;
				break;
			case 3:
				cout << q.GetCount() << endl;
				break;
			case 4:
				cout << q.GetSize() << endl;
				break;
			case 5:
				cout << q.GetStart() << endl;
				break;
			case 6:
				cout << q.GetEnd() << endl;
				break;
			default:
				break;
			}

			cout << q << endl;
		}
	}
	catch (exception e) {
		cerr << e.what() << endl;
	}
}
