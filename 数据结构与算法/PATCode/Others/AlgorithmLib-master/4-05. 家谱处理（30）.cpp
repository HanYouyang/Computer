//4-05. 家谱处理（30）
//树的遍历
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <iostream>
#include <queue>
using namespace std;

struct Node{
	int parent;//记录当前节点的父亲结点
	vector<int>child;
}tree[101];

int table[101];//记录祖先表

map<string, int>name2order;
map<int, string>order2name;
int Number = 0;

int calTab(string &s)
{
	int i = 0;
	while(s[i] == ' ' && i < s.length())
		i++;
	s.erase(s.begin(), s.begin() + i);
	i /= 2;
	table[i] = name2order[s];
	return i;
}

int change(string s)
{
	name2order[s] = Number;
	order2name[Number] = s;
	return Number++;
}

bool Find(int x, int y)//x是y的祖先节点
{
	queue<int> q;
	q.push(x);
	while(q.empty() == false)
	{
		int top = q.front();
		q.pop();
		for(int i = 0; i < tree[top].child.size(); i++)
		{
			int next  = tree[top].child[i];
			q.push(next);
			if(next == y)
				return true;
		}
	}
	return false;
}

int main()
{
	int n, m, idx, tab;
	string name;
	scanf("%d%d", &n, &m);
	getchar();
	getline(cin, name);//先读取root
	idx = change(name);
	table[0] = idx;
	tree[idx].parent = -1;
	n--;
	while(n--)
	{
		getline(cin, name);
		tab = calTab(name);
		idx = change(name);
		tree[table[tab - 1]].child.push_back(idx);//添加孩子节点
		tree[idx].parent = table[tab - 1];//添加父节点
		table[tab] = idx;//更新table表 
	}
	//读入陈述句
	char x[11], y[11], relation[11];
	char str1[3], str2[3], str3[3];
	while(m--)
	{
		scanf("%s %s %s %s %s %s", x, str1, str2, relation, str3, y);
		int a = name2order[x];
		int b = name2order[y];

		//1.sibering
		if(relation[0] == 's')
		{
			if(tree[a].parent == tree[b].parent)//说明是兄弟节点
				printf("True\n");
			else
				printf("False\n");
		}
		//2.x is a child of y
		if(relation[0] == 'c')
		{
			if(tree[a].parent == b)
				printf("True\n");
			else
				printf("False\n");
		}
		//3.x is the parent of y
		if(relation[0] == 'p')
		{
			if(tree[b].parent == a)
				printf("True\n");
			else
				printf("False\n");
		}
		//x is a descendant of y
		if(relation[0] == 'd')
		{
			bool res = Find(b, a);
			if(res == true)
				printf("True\n");
			else
				printf("False\n");
		}
		if(relation[0] == 'a')
		{
			bool res = Find(a, b);
			if(res == true)
				printf("True\n");
			else
				printf("False\n");
		}
	}
	return 0;
}