// W3-�γ���ҵ2-4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
//���������������ǣ�
//5, 5
//5, 5
//����գ�

#include <iostream>
using namespace std;
class Base {
public:
	int k;
	Base(int n) :k(n) { }
};
class Big  {
public:
	int v; Base b;
	// �ڴ˴�������Ĵ���
	//Big ________________{}
	//Big ________________{}
	Big(int n) :v(n), b(n) {}
	
	Big(const Big& a) :v(a.v), b(a.b)
	{
		//v = a.v;
		//b = a.b;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	Big a1(5);    
	Big a2 = a1;
	cout << a1.v << "," << a1.b.k << endl;
	cout << a2.v << "," << a2.b.k << endl;
	system("pause");
	return 0;
}

