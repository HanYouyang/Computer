// W3-�γ���ҵ2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
class A {
	int val;
public:
	A(int n) { val = n; }
	int GetVal() { return val; }
};
class B : public A {
private:
	int val;
public:
	B(int n) :
		// �ڴ˴�������Ĵ���
		val(2 * n), A(3*n)
	{ }
	int GetVal() { return val; }
};

//�����������Ľ���ǣ�4, 6
int _tmain(int argc, _TCHAR* argv[])
{
	B b1(2);
	cout << b1.GetVal() << "," << b1.A::GetVal() << endl;
	system("pause");
	return 0;
}

