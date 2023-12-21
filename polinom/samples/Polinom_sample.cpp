#include "TPolinom.h"
#include <iostream>

using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	try
	{
		cout << "Мономы:" << endl;


		TMonom m1(3, 5, 2, 5);
		TMonom m2(-5, 4, 3, 3);
		TMonom m3(7, 3, 5, 1);
		TMonom m4(4, 3, 2, 6);
		TMonom m5(0, 2, 7, 3);
		TMonom m6(-6, 2, 1, 8);


		cout << "m1: " << m1.ToString() << endl;
		cout << "m2: " << m2.ToString() << endl;
		cout << "m3: " << m3.ToString() << endl;
		cout << "m4: " << m4.ToString() << endl;
		cout << "m5: " << m5.ToString() << endl;
		cout << "m6: " << m6.ToString() << endl;

		TPolinom p1;
		p1.AddMonom(m1);
		p1.AddMonom(m2);
		p1.AddMonom(m3);
		cout << endl << "Первый полином от m1, m2, m3: " << p1.ToString() << endl;

		TPolinom p2;
		p2.AddMonom(m4);
		p2.AddMonom(m5);
		p2.AddMonom(m6);
		cout << endl  << "Воторой полином от m4, m5, m6: " << p2.ToString() << endl;

		TPolinom res(p1.ToString());

		res = p1 + p2;
		cout  << endl << "res = p1 + p2: " << res.ToString() << endl;


		cout << "Длина: " << res.GetLength() << endl << endl;

		res = p2;
		cout << "res = p2: " << res.ToString() << endl << endl;
	}

	catch (exception e)
	{
		cout << e.what();
	}

	return 0;
}
