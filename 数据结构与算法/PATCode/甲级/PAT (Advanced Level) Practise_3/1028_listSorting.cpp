//2016年2月15日15时07分33
//2016年2月15日15时39分11秒
#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>
#include <cstdio>
#include <cstring>

using namespace std;

const int maxn = 100010;
int c;

struct Student{
	int id;
	char name[10];
	int score;
}stu[maxn];

bool cmp(Student a, Student b){
	if(1 == c) return a.id < b.id;
	else if (2 == c) return strcmp(a.name, b.name) <= 0;
	else return a.score <= b.score;
}

int main()
{
	int n;
	scanf("%d%d", &n, &c);
	for(int i = 0; i < n; i++){
		scanf("%d%s%d", &stu[i].id, stu[i].name, &stu[i].score);
	}
	sort(stu, stu + n, cmp);
	for(int i = 0; i < n; i++){
		//cout << setw(6) << setfill('0') << stu[i].id << ' ' << stu[i].name << ' '
		//	<< stu[i].score << endl;
		printf("%06d %s %d\n", stu[i].id, stu[i].name, stu[i].score);
	}
	return 0;
}
//cin cout 测试点6运行超时
//cin printf 测试点6用时169ms， 
//scanf printf 测试点6用时58ms；测试点6占用内存4004kB 其他测试点占用内存256kB
//使用scanf printf 用char型数组代替string 既可以减少时间，有可以减少占用内存
