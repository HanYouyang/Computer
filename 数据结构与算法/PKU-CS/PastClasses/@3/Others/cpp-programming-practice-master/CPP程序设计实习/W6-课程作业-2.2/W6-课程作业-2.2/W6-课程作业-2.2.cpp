// W6-�γ���ҵ-2.2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

/*���������������ǣ�

destructor B

destructor A

������д�� class A�� ��������������Ϊ class A ��д���캯����*/

#include <iostream>
using namespace std;
class A {
	// �ڴ˴�������Ĵ���
public:
	virtual ~A() { cout << "destructor A" << endl; }
};
class B :public A {
public:
	~B() { cout << "destructor B" << endl; }
};

int _tmain(int argc, _TCHAR* argv[])
{
	A * pa;
	pa = new B;
	delete pa;
	system("pause");
	return 0;
}

