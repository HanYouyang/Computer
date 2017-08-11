// W8-�����ҵ-2SET.cpp : Defines the entry point for the console application.
//
/*����
����һ���������������ظ�Ԫ�أ�����ʼΪ�ա����Ƕ������²�����
add x ��x���뼯��
del x �Ѽ�����������x��ȵ�Ԫ��ɾ��
ask x �Լ�����Ԫ��x�����ѯ��
��ÿ�ֲ���������Ҫ��������������
add ��������󼯺���x�ĸ���
del �������ǰ������x�ĸ���
ask �����0��1��ʾx�Ƿ��������뼯�ϣ�0��ʾ�������룩���������ǰ������x�ĸ������м��ÿո�񿪡�
����
��һ����һ������n����ʾ��������0 <= n <= 100000��
����n�������Description��������
���
��n�У�ÿ�а�Ҫ�������
��������
7
add 1
add 1
ask 1
ask 2
del 2
del 1
ask 1
�������
1
2
1 2
0 0
0
2
1 0
��ʾ
Please use STL's set and multiset to finish the task
*/

#include "stdafx.h"
#include <iostream>
#include <set>
#include <string>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	int n;
	cin >> n;
	multiset<int> jh;
	set<int> nums;
	while (n-- > 0)
	{
		string sml;
		cin >> sml;
		if (sml == "add")
		{
			int x;
			cin >> x;
			jh.insert(x);
			nums.insert(x);
			cout << jh.count(x) << endl;
		}
		else if (sml == "del")
		{
			int x;
			cin >> x;
			cout << jh.erase(x)<<endl;
			/*int cnt = jh.count(x);
			cout << cnt <<endl;
			multiset<int>::iterator it = jh.find(x);
			for (int i = 0; i <cnt; ++i)
			  it=jh.erase(it);*/  //��һ��erase���VS����ȷִ�У�gcc�������
		}
		else if (sml == "ask")
		{
			int x;
			cin >> x;
			cout << nums.count(x) << " " << jh.count(x)<<endl;
		}
	}

	return 0;
}

