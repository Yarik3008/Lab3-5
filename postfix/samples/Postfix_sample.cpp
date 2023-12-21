#include <iostream>
#include "Postfix.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	try {
		string input;
		cout << "Введите выражежение: ";
		cin >> input;

		TArithmeticExpression expression(input);// передается значение арифметического выражения
		cout << expression.GetInfix() << endl;
		cout << expression.GetPostfix() << endl;

		
		cout << expression.Calculate() << endl;
	}
	catch (exception e) {
		cout << "Ошибка" << endl;
	}
}
