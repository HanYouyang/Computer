//2016年2月25日18时44分48秒
//2016年2月25日20时15分54秒
#include <iostream>
#include <cstdio>
#include <map>
#include <set>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

map<string, set<int> > mpTitle, mpAuthor, mpKey, mpPub, mpYear;
//题目映射，作者映射，关键字映射，出版社映射，出版年份映射
//分出这么多变量可以减少查找时间
void print(map<string, set<int> >  & mp, string str)
//如果不对mp参数进行引用而使用传值调用则会在最后一个测试点发生超时*******************************************
//由此可见，字符串以及map的参数传递速度较慢，如果需要作为函数参数的话，尽可能加上引用************************
{//根据键值输出
	if(mp.find(str) == mp.end()) printf("Not Found\n");
	//没找到，输出Not Found 注意格式
	else {//找到了，通过迭代器输出（set只能通过迭代器输出）
		for(set<int>::iterator it = mp[str].begin(); it != mp[str].end(); it++){
			printf("%07d\n", *it);//保持七位，不够补零
		}
	}
}

int main()
{
	int n;//书的总数，最大值10000
	scanf("%d", &n);
	int id;//书的id
	string title, author, key, publisher, year;
	//书的标题，作者，关键字，出版社，出版年份
	for(int i = 0; i < n; i++){
		scanf("%d", &id);
		char c = getchar();//getline紧跟scanf中间要吸收回车符
		//还可以用cin.get();
		getline(cin, title);//读入书名title
		mpTitle[title].insert(id);//把id加到title对应的集合中
		getline(cin, author);//读入作者author
		mpAuthor[author].insert(id);//把id加到author对应的集合中
		while(cin >> key){
		//每次读入单个关键字key
			mpKey[key].insert(id);
			c = getchar();//接收关键字key之后的字符
			if(c == '\n') break;//如果是换行，说明关键字输入结束
			//\n不可以加双引号，在字符串比较才能加双引号*****************************************
		}	
		getline(cin, publisher);//读入出版社publisher
		mpPub[publisher].insert(id);//把id加到publisher对应的集合中
		getline(cin, year);//读入出版年份year
		mpYear[year].insert(id);//把id加到year对应的集合中
	}
	int m;//查询的次数
	scanf("%d", &m);
	for(int i = 0; i < m; i++){
		int type;//查询类型
		string str;
		scanf("%d: ", &type);//注意格式
		getline(cin, str);
		cout << type << ": " << str << endl;//原始问题输出
		switch(type){//匹配查询
			case 1: print(mpTitle, str); break;//查询书名对应的所有字符串
			case 2: print(mpAuthor, str); break;//作者
			case 3: print(mpKey, str); break;//关键字
			case 4: print(mpPub, str); break;//出版社
			case 5: print(mpYear, str); break;//出版年份
			default: break;
		}
	}
	return 0;
}
