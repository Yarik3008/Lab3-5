#pragma once
#include <string>
using namespace std;
struct TMonom
{
    double coef; // коэффициент монома
    int index; // индекс (свертка степеней переменных X, Y и Z)


	TMonom() {
		coef = 0;
		index = 0;
	}

	TMonom(double coef1, int degX, int degY, int degZ) {
		coef = coef1;
		index = degX * 100 + degY * 10 + degZ;
	}

	void SetCoef(int cval) { coef = cval; }
	int GetCoef(void) { return coef; }

	void SetIndex(int ival) { index = ival; }
	int GetIndex(void) { return index; }


	bool operator==(const TMonom& other) {
		return index == other.index && coef == other.coef;
	}
	
	bool operator>(const TMonom& other) {
		return index >= other.index || coef > other.coef;
	}

	bool operator<(const TMonom& other) {
		return index <= other.index || coef < other.coef;
	}

	string ToString() {
		string result;
		int degX = index / 100;
		int degY = index / 10 % 10;
		int degZ = index % 10;
		if (coef != 1) 
			result += to_string(round(coef * 100000) / 100000);
		if (degX != 0) {
			result += "X";
			if (degX != 1)
				result += "^" + to_string(degX);
		}
		if (degY != 0) {
			result += "*Y";
			if (degY != 1)
				result += "^" + to_string(degY);
		}
		if (degZ != 0) {
			result += "*Z";
			if (degZ != 1)
				result += "^" + to_string(degZ);
		}

		return result;
	}// Он сначала разбивает индекс на степени переменных X, Y и Z, а затем формирует строку, 
	//представляющую коэффициент и степени переменных. Если коэффициент не равен 1, он добавляется 
	// к строке. Затем добавляются степени переменных X, Y и Z соответственно, с учетом их значения 
	// (если они не равны 0) и добавляется знак "^" перед степенью, если она не равна 1.
};