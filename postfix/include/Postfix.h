#pragma once 
#include "../../stack/include/MyStack.h"
#include <string>
using namespace std;

class TArithmeticExpression
{
private:
	string infix;
	string postfix;

	void ToPostfix();
	int GetPriority(char op); // возвращает приоритет оператора
public:
	TArithmeticExpression(string infix); // принимает арифметическое выражение в инфиксной форме и сохраняет его в поле infix
	string GetInfix() { return infix; }
	string GetPostfix() { return postfix; }
	double Calculate();
	
};
