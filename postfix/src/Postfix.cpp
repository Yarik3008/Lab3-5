#include "Postfix.h"

TArithmeticExpression::TArithmeticExpression(string _infix)
{
	infix = _infix;
	ToPostfix();
}

void TArithmeticExpression::ToPostfix() {
	/*
		Рассматриваем поочередно каждый символ:
			Если этот символ - число (или переменная), то просто помещаем его в выходную строку.
			Если символ - знак операции (+, -, *, /), то проверяем приоритет данной операции:
				Умножение и деление имеют наивысший приоритет (например, он равен 2)
				Сложение и вычитание имеют меньший приоритет (например, 1)
				Наименьший приоритет у открывающейся скобки (0)
			Получив один из этих символов мы должны проверить стек:
				Если стек все еще пуст или находящиеся в нем символы (а находиться в нем могут только знаки операций и открывающая скобка) имеют меньший приоритет, чем приоритет текущего символа, то символ помещаем в стек
				Если символ, находящийся на вершине стека имеет приоритет больший или равный приоритету текущего символа, то извлекаем символы из стека в выходную строку до тех пор, пока выполняется это условие,   затем переходим к пункту А
				Если текущий символ - открывающая скобка, то помещаем ее в стек
				Если текущий символ - закрывающая скобка, то извлекаем символы из стека в выходную строку, пока не встретим открывающую скобку (т.е. символ с приоритетом, равным 0), которую следует просто уничтожить. Закрывающая скобка также уничтожается

			Если вся входная строка разобрана, а в стеке еще остаются знаки операций, то извлекаем их из стека в выходную строку.

	*/

	TStack<char> stack(200);
	char stackItem;
	string number = "";
	for (char item : infix) {
		if (item == '(') {
			if (number != "") {
				postfix += number + " ";
				number = "";
			}

			stack.Push(item);
		}
		else if (item == ')') {
			if (number != "") {
				postfix += number + " ";
				number = "";
			}

			stackItem = stack.Get();
			while (stackItem != '(') {
				postfix += stackItem;
				postfix += " ";
				stackItem = stack.Get();
			}
		}
		// Встретился оператор
		else if (item == '+' || item == '-' || item == '*' || item == '/') {
			if (number != "") {
				postfix += number + " ";
				number = "";
			}
			
			while (!stack.IsEmpty()) {
				stackItem = stack.Get();
				if (GetPriority(item) <= GetPriority(stackItem)) {
					postfix += stackItem;
					postfix += " ";
				}
				else {
					stack.Push(stackItem);
					break;
				}
			}
			stack.Push(item);
		}
		// Встретилась часть числа (цифра или точка)
		else {
			number += item;
		}
	}

	if (number != "") {
		postfix += number + " ";
		number = "";
	}

	while (!stack.IsEmpty()) {
		stackItem = stack.Get();
		postfix += stackItem;
		postfix += " ";
	}
}

double TArithmeticExpression::Calculate() {
	/*
		Для каждой лексемы в постфиксной форме
		– Если лексема –операнд, поместить ее значение в стек
		– Если лексема –операция
			• Извлечь из стека значения двух операндов
			• Выполнить операцию (верхний элемент из стека является правым операндом, следующий за ним – левым
			• Положить результат операции в стек
		По исчерпании лексем из постфиксной формы на вершине стека будет 
		результат вычисления выражения

	*/
	double leftOperand, rightOperand;
	TStack<double> stack(200);
	string number = "";
	for (char item : postfix)
	{	
		if (item == ' ') {
			if (number != "") {
				stack.Push(stod(number)); // stod - string to double
				number = "";
			}
			continue;
		}
		// Встретился оператор
		if (item == '+' || item == '-' || item == '*' || item == '/') {
			double res = 0;
			rightOperand = stack.Get();
			leftOperand = stack.Get();

			if (item == '+') res = leftOperand + rightOperand;
			if (item == '-') res = leftOperand - rightOperand;
			if (item == '*') res = leftOperand * rightOperand;
			if (item == '/') {
				if (rightOperand == 0)
					throw - 1;
				res = leftOperand / rightOperand;
			}
			stack.Push(res);
		}
		// Встретилась часть числа (цифра или точка)
		else {
			number += item;
		}
	}
	return stack.TopView();
}

int TArithmeticExpression::GetPriority(char op) {
	/*
		Получить приоритет операции
	*/
	switch (op) {
	case '(':
		return 0;
	case ')':
		return 0;
	case '+':
		return 1;
	case '-':
		return 1;
	case '/':
		return 2;
	case '*':
		return 2;
	}
}

