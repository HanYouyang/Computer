// W8-�����ҵ-1.cpp : Defines the entry point for the console application.
/*дһ����������������
    new id �����½�һ��ָ�����Ϊid������(id<10000)
	add id num ��������Ϊid�����м�������num
	merge id1 id2 �����ϲ�����id1��id2�е���������id2���
	unique id ����ȥ������id���ظ���Ԫ��
	out id ������С����������Ϊid�������е�Ԫ�أ��Կո����

����
	��һ��һ����n����ʾ�ж��ٸ�����(n����������������)���Ժ�n��ÿ��һ�����*/

/*
  ˼����out��ʱ����Ҫ������ģ��������б��������򣬻����ǰsortһ��
       unique���������ڹ����������������оͲ�����set֮��Ĺ�������
	   merge�������������䣬������б���������ģ���merge֮ǰ��Ҫsortһ��
	   
	   ���������⣬��Ϊunique������������ɾ����������һ����������־λ�û��ǻ������⡣
	   ����ǿ��Եģ���unique��Ȼ��erase
*/

#include "stdafx.h"
#include <vector>
#include <set>
#include <map>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	freopen("C:\\Users\\hello\\Documents\\Visual Studio 2013\\Projects\\cpp-programming-practice\\OJ-AC-code\\8list-in.txt","r",stdin);

	int n;
	cin >> n;
	//cout << n << endl;
	map<int,vector<int> > xulie;
	//map<int, vector<int>::iterator > xlit;//������ЧԪ�ص���һ��λ�ã����ǵ�unique��������ɾ����ԭ��
	while (n-- > 0)
	{
		string sml;
		cin >> sml;
		if (sml == "new")
		{
			int id;
			cin >> id;
			xulie[id];
		}
		else if (sml == "add")
		{
			int id, num;
			cin >> id >> num;
			//xulie[id].insert(num);
			xulie[id].push_back(num);
		}
		else if (sml == "merge")
		{
			int id1, id2;
			cin >> id1 >> id2;
			if (id1 == id2) continue;  //������ע�����
			//xulie[id1].resize(xulie[id1].size() + xulie[id2].size());
			/*sort(xulie[id1].begin(),xulie[id1].end());
			sort(xulie[id2].begin(), xulie[id2].end());
			xulie[id1].resize(xulie[id1].size() + xulie[id2].size());
			merge(xulie[id1].begin(),xulie[id1].end(),xulie[id2].begin(),xulie[id2].end(),xulie[id1].begin());//������������������ */
			
			vector<int> vtmp(xulie[id1].begin(),xulie[id1].end());
			sort(vtmp.begin(),vtmp.end());
			sort(xulie[id2].begin(), xulie[id2].end());
			xulie[id1].clear();
			xulie[id1].resize(xulie[id1].size() + xulie[id2].size());
			merge(vtmp.begin(),vtmp.end(),xulie[id2].begin(),xulie[id2].end(),xulie[id1].begin());//������������������
			xulie[id2].clear();
		}
		else if (sml == "unique")
		{
			int id;
			cin >> id;
			sort(xulie[id].begin(),xulie[id].end());
			vector<int>::iterator newend=unique(xulie[id].begin(),xulie[id].end());//ɾ���㷨��Ӧ�����ڹ�������
			xulie[id].erase(newend,xulie[id].end());
			/*if (xulie[id].empty() == false)
			{
				for (vector<int>::iterator it = xulie[id].end()-1; it != xulie[id].begin(); --it)
				{
					if (*it == *(it - 1)) xulie[id].erase(it);
				}
			}*/
		}
		else if (sml == "out")
		{
			int id;
			cin >> id;
			sort(xulie[id].begin(), xulie[id].end());
			for (vector<int>::iterator it = xulie[id].begin(); it != xulie[id].end(); ++it)
			{
				cout << *it << " ";
			}
			cout << endl;

		}
	}

	return 0;
}

