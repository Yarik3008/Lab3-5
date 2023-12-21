#pragma once
#include <iostream>
template <class T>
class TQueue {
protected:
	int size;
	int start; // индекс начала очереди
	int end;
	int count; // количество элементов в очереди
	T* mas;

public:
	TQueue(int n = 0) {
		if (n <= 0)
			throw - 1;
		size = n;
		start = 0;
		end = size;
		count = 0;
		mas = new T[size];
	}
	TQueue(TQueue <T>& q) {
		start = q.start;
		end = q.end;
		count = q.count;
		size = q.size;
		mas = new T[size];
		for (int i = 0; i < size; i++)
			mas[i] = q.mas[i];
	}
	~TQueue() {
		if (mas == nullptr)
			delete[] mas;

		mas = nullptr;
	}

	void Push(T a) {
		if (IsFull())
			throw - 1;

		int index = (start + count++) % size;
		mas[index] = a;
		end = (end + 1) % size;
	}

	T Get() {
		if (IsEmpty())
			throw - 1;

		T tmp = mas[start];// элемент помещается в tmp 
		mas[start] = T();
		start = (start + 1) % size; // изменение значения полей
		count--;
		end = (end + 1) % size;
		return tmp;
	}
	bool IsFull() {
		return count == size;
	}
	bool IsEmpty() {
		return count == 0;
	}

	int GetStart() { return start; }
	int GetSize() { return size; }
	int GetCount() { return count; }
	int GetEnd() { return end; }
	
	TQueue& operator=(const TQueue<T>& q) { // присваивает одну очередь другой
		if (this == &q)
			return *this;

		if (mas != nullptr)
			delete[] mas;

		size = q.size;
		mas = new T[size];

		for (int i = 0; i < size; i++) // происходит копирование обратно
			mas[i] = q.mas[i];
		count = q.count;
		start = q.start;
		end = q.end;

		return *this;
	}

	//операторы вводы и выводы
	friend std::ostream& operator<<(std::ostream& ostr, const TQueue<T>& q) noexcept {
		for (size_t i = 0; i < q.size; i++) {
			ostr << q.mas[i] << std::endl;
		}
		return ostr;
	}
	friend std::istream& operator>>(std::istream& istr, const TQueue<T>& q) noexcept {
		for (size_t i = 0; i < q.size; i++) {
			istr >> q.mas[i];
		}
		return istr;
	}
};