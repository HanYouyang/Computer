// WEEK8-�γ���ҵ-�����1-1.cpp : Defines the entry point for the console application.
//
//����
//��
//���
//1 2 6 7 8 9

#include "stdafx.h"
#include <iostream>
#include <iterator>
#include <set>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	int a[] = { 8, 7, 8, 9, 6, 2, 1 };
	// �ڴ˴�������Ĵ���
	set<int> v(a,a+7);   //������Ҫ����set������set���������ĳ�ʼ���������Ҳ��ظ���

	ostream_iterator<int> o(cout, " ");
	copy(v.begin(), v.end(), o);

	system("pause");
	return 0;
}

