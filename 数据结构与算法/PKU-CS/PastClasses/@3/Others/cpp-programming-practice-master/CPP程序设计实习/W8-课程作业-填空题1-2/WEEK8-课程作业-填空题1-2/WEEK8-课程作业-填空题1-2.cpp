// WEEK8-�γ���ҵ-�����1-2.cpp : Defines the entry point for the console application.
//
//����ĳ�����ö�ٷ�����������⣬����ա�
//ƽ���ϵ�һ�����Σ�������ƽ���������ᣬ���Ǿͳ���Ϊ"��׼����"���������ظ��� n �����㣨�ᡢ�����궼�������ĵ㣩��
//�����n��������ȡ4����Ϊ���������ɵ��ı����У��ж��ٸ��Ǳ�׼���Ρ�
/*����
��һ���ǵ����Ŀ
���ÿһ�ж�����һ���㣬������������ʾ����һ����x���꣬�ڶ�����y����
���
�����׼���ε���Ŀ*/

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Point {
	int x;
	int y;
	Point(int x_, int y_) :x(x_), y(y_) { }
};
bool operator < (const Point & p1, const Point & p2)
{
	if (p1.y < p2.y)
		return true;
	else if (p1.y == p2.y)
		return p1.x < p2.x;
	else
		return false;
}

int _tmain(int argc, _TCHAR* argv[])
{
	int t;
	int x, y;
	cin >> t;
	vector<Point> v;
	while (t--) {
		cin >> x >> y;
		v.push_back(Point(x, y));
	}
	vector<Point>::iterator i, j;
	int nTotalNum = 0;
	// �ڴ˴�������Ĵ���
	/*��ȱ�������������ʽ��
		_____________________;
	for (i = v.begin(); i < v.end() - 1; i++)
		for (_____________; ______________; _____________) {
			if (binary_search(v.begin(), v.end(), Point(j->x, i->y)) &&
				____________________________________________ &&
				____________________________________________ &&
				____________________________________________)
				nTotalNum++;
		}
	cout << _________________;*/

	sort(v.begin(),v.end());
	for (i = v.begin(); i < v.end() - 1; i++)
		for (j=i+1;j<v.end() ;j++ ) {
			if (binary_search(v.begin(), v.end(), Point(j->x, i->y)) &&
				 binary_search(v.begin(),v.end(),Point(i->x,j->y))&&
				 &&
				)
				nTotalNum++;
		}
	cout << nTotalNum;

	return 0;
}

