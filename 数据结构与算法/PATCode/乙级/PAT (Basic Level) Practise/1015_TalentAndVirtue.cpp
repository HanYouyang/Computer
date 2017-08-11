//2016年2月13日10时20分34秒
//2016年2月13日11时18分46秒

//tip1：使用cin与cout输入输出超时，此时的规模是10^5个person结构体变量
//	改成scanf与printf输入输出解决超时问题
//tip2：scanf无法输入string类型（可能我没找到方法）
//tip3：C语言中字符数组比较函数strcmp(str1, str2)[在头文件string.h中]
//		<0 str1字典序小于str2
//		=0 str1字典序等于str2
//		>0 str1字典序大于str2
//	C++语言中字符串比较函数时str1.compare(str2)[在头文件string中]
//		<0 str1字典序小于str2
//		=0 str1字典序等于str2
//		>0 str1字典序大于str2

#include <iostream>
#include <algorithm>
#include <string>
#include <cstdio>
#include <cstring>

using namespace std;

const int maxn = 100010;

struct person{
	//string id;
	char id[10];
	int virGrade;
	int talGrade;
	int totalGrade;
	int flag;
}stu[maxn];

bool cmp(person a, person b){
	if(a.flag != b.flag) return a.flag < b.flag;
	else if(a.totalGrade != b.totalGrade) return a.totalGrade > b.totalGrade;
	else if(a.virGrade != b.virGrade) return a.virGrade > b.virGrade;
	//else return a.id.compare(b.id) < 0;
	else return strcmp(a.id, b.id) < 0;
}

int main()
{
	int n, l, h;
	//cin >> n >> l >> h;
	scanf("%d%d%d", &n, &l, &h);
	int m = n;
	for(int i = 0; i < n; i++){
		//cin >> stu[i].id >> stu[i].virGrade >> stu[i].talGrade;
		scanf("%s%d%d", stu[i].id, &stu[i].virGrade, &stu[i].talGrade);
		
		stu[i].totalGrade = stu[i].virGrade + stu[i].talGrade;
		if(stu[i].virGrade < l || stu[i].talGrade < l){
			stu[i].flag = 5;
			m--;
		}
		else if (stu[i].virGrade >= h && stu[i].talGrade >= h) stu[i].flag = 1;
		else if (stu[i].virGrade >= h && stu[i].talGrade < h) stu[i].flag = 2;
		else if (stu[i].virGrade >= stu[i].talGrade) stu[i].flag = 3;
		else stu[i].flag = 4;
	}
	sort(stu, stu + n, cmp);
	//cout << m << endl;
	printf("%d\n", m);
	for(int i = 0; i < m; i++){
		//cout << stu[i].id << ' ' << stu[i].virGrade << ' ' << stu[i].talGrade << endl;
		printf("%s %d %d\n", stu[i].id, stu[i].virGrade, stu[i].talGrade);
	}
	return 0;
}
