// W7-�γ���ҵ-2.1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

//ʵ��һ����ά����ģ��CArray3D��������������Ԫ��Ϊ�������ͱ�������ά���飬ʹ����������������ǣ�

//0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59,

//ע�⣬ֻ��дһ����ģ�棬����д�����

#include <iostream>
using namespace std;
// �ڴ˴�������Ĵ���
Template<class T>
class CArray3D
{
	class CArray2D
	{

	};

	CArray3D(int a, int b, int c)
	{

	}
};


int _tmain(int argc, _TCHAR* argv[])
{
	CArray3D<int> a(3, 4, 5);
	int No = 0;
	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 4; ++j)
			for (int k = 0; k < 5; ++k)
				a[i][j][k] = No++;
	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 4; ++j)
			for (int k = 0; k < 5; ++k)
				cout << a[i][j][k] << ",";

	return 0;
}

