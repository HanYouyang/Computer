//2016年3月8日20时24分23秒
//2016年3月8日15时25分20秒
//codeup题目编号27732
#include <iostream>
#include <cstdio>
#include <stack>
#include <string>
#include <queue>
#include <map>

using namespace std;

struct Node{
	double num;
	char op;
	bool flag;
};

string str;
stack<Node> s;
queue<Node> q;
map<char, int> mp;

void change()
{
	Node temp;
	for(int i = 0; i < str.length();){
		if(str[i] >= '0' && str[i] <= '9'){
			temp.flag = true;
			temp.num = str[i++] - '0';
			while(i < str.length() && str[i] >= '0' && str[i] <= '9'){
				temp.num = temp.num * 10 + str[i] - '0';
				i++;
			}
			q.push(temp);
		} else if (str[i] == '('){
			temp.flag = false;
			temp.op = str[i];
			s.push(temp);
			i++;
		} else if (str[i] == ')'){
			while(!s.empty() && s.top().op != '('){
				q.push(s.top());
				s.pop();
			}
			s.pop();
			i++;
		} else {
			temp.flag = false;
			temp.op = str[i];
			while(!s.empty() && mp[s.top().op] >= mp[temp.op]){
				q.push(s.top());
				s.pop();
			}
			s.push(temp);
			i++;
		}
	}
	while(!s.empty()){
		q.push(s.top());
		s.pop();
	}
}

double cal()
{
	double temp1, temp2;
	Node cur, temp;
	while(!q.empty()){
		cur = q.front();
		q.pop();
		if(cur.flag == true){
			s.push(cur);
		} else {
			temp2 = s.top().num;
			s.pop();
			temp1 = s.top().num;
			s.pop();
			temp.flag = true;
			if(cur.op == '+') temp.num = temp1 + temp2;         //加法
			else if(cur.op == '-') temp.num = temp1 - temp2;    //减法
			else if(cur.op == '*') temp.num = temp1 * temp2;    //乘法
			else temp.num = temp1 / temp2;  //除法
			s.push(temp);   //把该操作数压入栈
		}
	}
	return s.top().num;
}

int main()
{
	mp['('] = mp[')'] = 0;
	mp['+'] = mp['-'] = 1;
	mp['*'] = mp['/'] = 2;
	getline(cin, str);
	change();
	printf("%.2f\n", cal());
	return 0;
}
