// W6-�γ���ҵ2-1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

//���������������ǣ�

//A::Fun

//C::Do

//����գ�

#include <iostream>
using namespace std;
class A {
private:
	int nVal;
public:
	void Fun()
	{
		cout << "A::Fun" << endl;
	}
	void Do()
	{
		cout << "A::Do" << endl;
	}
};
class B :public A {
public:
	virtual void Do()
	{
		cout << "B::Do" << endl;
	}
};
class C :public B {
public:
	void Do()
	{
		cout << "C::Do" << endl;
	}
	void Fun()
	{
		cout << "C::Fun" << endl;
	}
};
void Call(
	 B &p                           // �ڴ˴�������Ĵ���
	)  
{
	p.Fun();  p.Do();
}

int _tmain(int argc, _TCHAR* argv[])
{
	C c;    Call(c);
	system("pause");
	return 0;
}

