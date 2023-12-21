#pragma once
#include "THeadList.h"
#include "TMonom.h"
#include <string>
#include <sstream>

const int nonDisplayedZeros = 4; 
// Количество неотображаемых нулей при выводе коэффициента полинома
// Кол-во символов после запятой = 6 - nonDisplayedZeros


class TPolinom : public THeadList<TMonom>
{
public:
	TPolinom();
	TPolinom(TPolinom& other);
	TPolinom(string str);
	TPolinom& operator=(const TPolinom& other); // присваивание
    TPolinom operator+(TPolinom& q); // сложение полиномов

    void AddMonom(TMonom newMonom); // добавление монома
    TPolinom AddPolinom(TPolinom& other); // добавление полинома
    string ToString(); // перевод в строку
};

TPolinom::TPolinom() : THeadList<TMonom>::THeadList()//инициализирует список пустым
{
    ;
}

TPolinom::TPolinom(TPolinom& other) : THeadList<TMonom>::THeadList()//создает копию полинома other
{

    other.Reset();
    for (int i = 0; i < other.length; i++) {
        AddMonom(other.pCurrent->value);
        other.GoNext();
    }
}

TPolinom::TPolinom(string str)
{	
    stringstream ss(str);
    string monom;
    while (getline(ss, monom, '+')) {//Разбивает строку str на мономы, каждый из которых представляет 
        //собой число типа double, за которым следует набор переменных (X, Y, Z) со своими степенями
        
        stringstream ss1(monom);
        string tmp;
        double coef;
        int degX = 0, degY = 0, degZ = 0;
        getline(ss1, tmp, '*');
        coef = stod(tmp);
        while(getline(ss1, tmp, '*')) {
            switch (tmp[0])
            {
            case 'X':
                if (tmp.size() >= 3)
                    degX = tmp[2] - '0';
                else
                    degX = 1;
                break;
            case 'Y':
                if (tmp.size() >= 3)
                    degY = tmp[2] - '0';
                else
                    degY = 1;
                break;
            case 'Z':
                if (tmp.size() >= 3)
                    degZ = tmp[2] - '0';
                else
                    degZ = 1;
                break;
            default:
                break;
            }
        }
        AddMonom(TMonom(coef, degX, degY, degZ));
    }
}

TPolinom& TPolinom::operator=(const TPolinom& other)//обеспечивает присваивание одного полинома другому
{
	if (this == &other)
		return *this;

    if (pFirst != nullptr) {
        while (length > 0) {
            DeleteFirst();
        }
    }

    TNode<TMonom>* tmp = other.pFirst;
    for (int i = 0; i < other.length; i++) {
        AddMonom(tmp->value);
        tmp = tmp->pNext;
    }

	return *this;
}

void TPolinom::AddMonom(TMonom m)//добавляет новый моном newMonom в полином
{
    if (m.GetCoef() == 0)
        return;

    if (pFirst == nullptr)
        InsertFirst(m);
    else {
        int i = 0;
        Reset();
        while (i <= length && pCurrent->value.GetIndex() != m.GetIndex()  && pCurrent->value > m)
        {
            i++;
            if (i == length) {
                InsertLast(m);
                return;
            }

            GoNext();
        }

        if (pCurrent->value.GetIndex() == m.GetIndex()) {
            double coef = pCurrent->value.GetCoef() + m.GetCoef();
            pCurrent->value.SetCoef(coef);
            if (coef == 0)
                DeleteCurrent();
        }
        else {
            if (pCurrent == pFirst) {
                InsertFirst(m);
            }
            else if (pPrevious != nullptr) {
                pCurrent = pPrevious;
                pPrevious = nullptr;
                InsertCurrent(m);
            }
        }
        Reset();
    }
}

TPolinom TPolinom::operator+(TPolinom& other)//выполняет сложение двух полиномов
{
    TPolinom res(*this);
    other.Reset();
    for (int i = 0; i < other.length; i++) {
        res.AddMonom(other.pCurrent->value);
        other.GoNext();
    }
	return res;
}

TPolinom TPolinom::AddPolinom(TPolinom& other)//добавляет полином other к текущему полиному
{
	return *this + other;
}


string TPolinom::ToString()//преобразует полином в строку
{
	string result;

    TNode<TMonom>* tmp = pFirst;
    if (length == 0) {
        return "0";
    }
    if (tmp != nullptr)
    {
        result += tmp->value.ToString();

        tmp = tmp->pNext;
    }
    while (tmp != nullptr && tmp != pStop)
    {
        if (tmp->value.GetCoef() > 0) {
            result += " + " + tmp->value.ToString();
        }
        else if (tmp->value.GetCoef() < 0) {
            tmp->value.SetCoef(-1 * tmp->value.GetCoef());
            result += " - " + tmp->value.ToString();
            tmp->value.SetCoef(-1 * tmp->value.GetCoef());
        }
        tmp = tmp->pNext;

    }
    return result;
}
