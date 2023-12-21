#pragma once

template<class T>
struct TNode
{
	T value;// значение элемента списка
	TNode<T>* pNext;//указатель на следующий узел списка
};