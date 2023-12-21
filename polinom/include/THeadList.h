#pragma once
#include "TList.h"
using namespace std;


template<class T>
class THeadList : public TList<T> {
protected:
	TNode<T>* pHead; // заголовок, pFirst - звено за pHead
public:
	THeadList();
	~THeadList();
	void InsertFirst(T item); // вставка звеньев после заголовка
	void DeleteFirst(); // удалить первое звено
};

template<class T>
THeadList<T>::THeadList() : TList<T>()//cоздается заголовочный узел pHead и устанавливается связь между pHead и первым узлом списка. 
//Это делается путем установки указателя pNext заголовочного узла на первый узел списка, а также установкой связи между последним 
// узлом списка и заголовочным узлом, чтобы обеспечить циклическую структуру списка.
{
	pHead = new TNode<T>;
	pHead->pNext = this->pFirst;
	this->pStop->pNext = pHead;
}

template<class T>
THeadList<T>::~THeadList()//очистка памяти
{
	if (pHead != nullptr)
		delete pHead;
	pHead = nullptr;
}

template <class T>
void THeadList<T>::InsertFirst(T item)//вставка нового узла
{
	TList<T>::InsertFirst(item);

	pHead->pNext = this->pFirst;

}

template <class T>
void THeadList<T>::DeleteFirst()//удаление первого узла списка
{
	TList<T>::DeleteFirst();

	pHead->pNext = this->pFirst;
}