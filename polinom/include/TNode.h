#pragma once

template<class T>
struct TNode
{
	T value;// �������� �������� ������
	TNode<T>* pNext;//��������� �� ��������� ���� ������
};