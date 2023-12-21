#pragma once
#include <iostream>

template <class T>
class TStack {
protected:
	int size;
	int top;
	T* mas;
public:
	TStack(int n = 0) {
		if (n <= 0)
			throw - 1;
		 
		size = n;// инициализация
		top = 0;
		mas = new T[size]();
	}
	TStack(TStack<T>& stack) {
		size = stack.size;
		top = stack.top;
		mas = new T[size]();

		for (int i = 0; i < size; i++)
			mas[i] = stack.mas[i];
	}
	~TStack() {
		if (mas != nullptr)
			delete[] mas;

		size = 0;
		top = 0;
	}
	void Push(T a) {
		if (IsFull()) {
			throw - 1;
		}
		mas[top] = a;
		top++;
	}
	T Get() {
		if (IsEmpty()) {
			throw - 1;
		}
		top--;
		T tmp = mas[top];
		mas[top] = T();
		return tmp;
	}
	T TopView() { return mas[top - 1]; }

	int GetSize()// индексы
	{
		return size;
	}
	int GetTop()
	{
		return top;
	}


	bool IsFull() 
	{
		return top == size;
	}

	bool IsEmpty()
	{
		return top == 0;
	}

	TStack& operator=(TStack<T>& stack)
	{
		if (this == &stack)
			return *this;

		if (mas != nullptr)
			delete[] mas;

		size = stack.size;
		mas = new T[size];


		top = stack.top;

		for (int i = 0; i < size; i++)
			mas[i] = stack.mas[i];

		return *this;
	}

	//операторы вводы и выводы
	friend std::ostream& operator<<(std::ostream & ostr, const TStack<T>&stack) noexcept {
		for (size_t i = 0; i < stack.size; i++) {
			ostr << stack.mas[i] << std::endl;
		}
		return ostr;
	}
	friend std::istream& operator>>(std::istream & istr, const TStack<T>&stack) noexcept {
		for (size_t i = 0; i < stack.size; i++) {
			istr >> stack.mas[i];
		}
		return istr;
	}
};




