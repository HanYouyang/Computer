// W3-�γ���ҵ2-3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

//������������ǣ�10
//�벹��Sample��ĳ�Ա�������������ӳ�Ա������

#include <iostream>
using namespace std;
class Sample{
public:
	int v;
	Sample(int n) :v(n) { }
	// �ڴ˴�������Ĵ���
	Sample(const Sample& a)
	{
		v = a.v*2;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	Sample a(5);
	Sample b = a;
	cout << b.v;
	system("pause");
	return 0;
}

