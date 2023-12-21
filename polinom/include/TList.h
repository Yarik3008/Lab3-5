#pragma once
#include "TNode.h"
#include <iostream>
using namespace std;

template<class T>
class TList
{
protected:
	TNode<T>* pFirst; // первое звено
	TNode<T>* pCurrent; // текущее звено
	TNode<T>* pPrevious; // звено перед текущим
	TNode<T>* pLast; // последнее звено
	TNode<T>* pStop; // значение указателя, означающего конец списка
	int length; // количество звеньев в списке

public:

	TList();
	~TList();
	int GetLength() { return length; }
	bool IsEmpty(); // список пуст ?
	// вставка звеньев
	void InsertFirst(T item); // перед первым
	void InsertCurrent(T item); // перед текущим
	void InsertLast(T item); // вставить последним

	// удаление звеньев
	void DeleteFirst(); // удалить первое звено
	void DeleteCurrent(); // удалить текущее звено

	void GoNext(); // сдвиг вправо текущего звена
	// (=1 после применения GoNext для последнего звена списка)

	void Reset(); // установить на начало списка
	bool IsEnd(); // список завершен ?

	T GetCurrentItem();
	void SetCurrentItem(T item) { pCurrent->value = item; }


};
template <class T>
TList<T>::TList()//инициализируются поля класса
{
	pFirst = nullptr;
	pCurrent = nullptr;
	pPrevious = nullptr;
	pLast = nullptr;
	pStop = new TNode<T>;
	length = 0;
}

template <class T>
TList<T>::~TList() // освобождение памяти
{
	while (length > 0) {
		DeleteFirst();
	}

	if (pStop != nullptr) {
		delete pStop;
		pStop = nullptr;
	}
	
	pFirst = nullptr;
	pPrevious = nullptr;
	pCurrent = nullptr;
	pLast = nullptr;
	
}

template <class T>
bool TList<T>::IsEmpty()
{
	return length == 0;
}

template <class T>
void TList<T>::InsertFirst(T item)
{
	if (length == 0) {
		pFirst = new TNode<T>;//создается новый узел pFirst
		pFirst->value = item;
		pFirst->pNext = pStop;//устанавливается связь с заглушкой pStop
		pLast = pFirst;// указывают на новый узел pFirst
		pCurrent = pFirst;
	}
	else {
		TNode<T>* prev = pFirst;
		pFirst = new TNode<T>;
		pFirst->value = item;
		pFirst->pNext = prev;
	}

	length++;
}

template <class T>
void TList<T>::InsertLast(T item)
{
	if (length == 0)
		InsertFirst(item);
	else {
		TNode<T>* prev = pLast;
		pLast = new TNode<T>;
		pLast->value = item;
		pLast->pNext = pStop;
		prev->pNext = pLast;//Указатель pNext предыдущего узла prev устанавливается на новый узел pLast
		length++;
	}
}

template <class T>
void TList<T>::InsertCurrent(T item)
{
	if (length == 0)
		InsertFirst(item);
	else {
		TNode<T>* pPrevios = pCurrent;
		pCurrent = new TNode<T>;//создается новый узел pCurrent, в котором хранится значение нового элемента
		pCurrent->value = item;
		pCurrent->pNext = pPrevios->pNext;
		pPrevios->pNext = pCurrent;
		length++;
	}
}

template <class T>
void TList<T>::DeleteFirst()
{
	if (pFirst != nullptr) {
		TNode<T>* prev = pFirst;
		pFirst = pFirst->pNext;
		if (pCurrent == prev)
			pCurrent = pFirst;
		if (pLast == prev)
			pLast = pFirst;
		if (pPrevious == prev)
			pPrevious = nullptr;
		if (prev != nullptr) {
			delete prev;
			prev = nullptr;
		}
		length--;
	}
}

template <class T>
void TList<T>::DeleteCurrent()//Если текущий элемент не является заглушкой pStop, то устанавливаются новые 
//значения для указателей, чтобы пропустить текущий элемент. Затем происходит удаление текущего элемента и 
// корректировка указателя pPrevious.
{
	if (pCurrent != nullptr) {
		TNode<T>* prev = pCurrent;
		pCurrent = pPrevious;
		pCurrent->pNext = prev->pNext;
		if (prev != nullptr)
			delete prev;
		pPrevious = nullptr;
		length--;
	}
}

template <class T>
T TList<T>::GetCurrentItem()
{
	if (pCurrent == pStop)
		throw " ";
	return pCurrent->value;//возвращает значение текущего элемента
}

template <class T>
void TList<T>::Reset()//сбрасывает текущий элемент списка на начало
{
	pPrevious = nullptr;
	pCurrent = pFirst;
}

template <class T>
void TList<T>::GoNext()//переходит к следующему элементу списка
{
	if (pCurrent->pNext == nullptr)
		throw - 1;
	pPrevious = pCurrent;
	pCurrent = pCurrent->pNext;
}

template <class T>
bool TList<T>::IsEnd()//проверяет, достигнут ли конец списка
{
	return pCurrent->pNext == pStop;
}