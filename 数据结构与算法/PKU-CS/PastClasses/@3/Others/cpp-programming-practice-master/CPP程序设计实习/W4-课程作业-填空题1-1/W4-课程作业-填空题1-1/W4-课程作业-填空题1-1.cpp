// W4-�γ���ҵ-�����1-1.cpp : Defines the entry point for the console application.
/*
�벹��Complex��ĳ�Ա���������ܼӳ�Ա������

����
��
���
3+4i
5+6i
*/

#include "stdafx.h"

#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;
class Complex {
private:
	double r, i;
public:
	void Print() {
		cout << r << "+" << i << "i" << endl;
	}
	// �ڴ˴�������Ĵ���
	Complex& operator=(const char *s)
	{
		char num[100];
		int len = 0;
		while (*s != '+') num[len++] = *s++;
		num[len] = '\0';
		double nr = atof(num);

		len = 0;
		s++;
		while (*s != '\0') num[len++] = *s++;
		num[len] = '\0';
		double ni = atof(num);

		r = nr;
		i = ni;
		return *this;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	Complex a;
	a = "3+4i"; a.Print();
	a = "5+6i"; a.Print();

	return 0;
}

