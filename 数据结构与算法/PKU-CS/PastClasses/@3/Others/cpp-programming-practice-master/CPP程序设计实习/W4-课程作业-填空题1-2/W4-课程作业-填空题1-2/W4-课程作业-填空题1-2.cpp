// W4-�γ���ҵ-�����1-2.cpp : Defines the entry point for the console application.
/*
��д�������صĲ��֡�����д�����ݱ�������ȫ���Ž� MyInt���ڲ��ģ�MyInt�ĳ�Ա�����ﲻ����ʹ�þ�̬��������

����
��
���
4,1
*/

#include "stdafx.h"

#include <iostream>
using namespace std;

class MyInt  {
	int nVal;
public:
	MyInt(int n) { nVal = n; }
	int ReturnVal() { return nVal; }
	// �ڴ˴�������Ĵ���
	MyInt& operator-(int x)
	{
		nVal -= x;
		return *this;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	MyInt objInt(10);
	objInt - 2 - 1 - 3;
	cout << objInt.ReturnVal();
	cout << ",";
	objInt - 2 - 1;
	cout << objInt.ReturnVal();

	return 0;
}

