//2016年2月14日09时55分02秒
//2016年2月14日13时47分46秒
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>

using namespace std;

const int maxn = 1010;

struct Record{
	char name[25];
	int mon, dd, hh, min;
	char tag[10];
}rec[maxn];

int toll[25] = {0};

bool cmp(Record a, Record b){
	//*********************************************//
	//if (string(a.name) != string(b.name)) return strcmp(a.name, b.name) < 0;//right
	//不能使用关系运算符“＝＝”来比较两个字符串，只能用strcmp() 函数来处理
	//if (a.name != b.name) return strcmp(a.name, b.name) < 0;//wrong
	if (strcmp(a.name, b.name)) return strcmp(a.name, b.name) < 0;
	//int s = strcmp(a.name, b.name);
	//if (s != 0) return s < 0;
	else if (a.mon != b.mon) return a.mon < b.mon;
	else if (a.dd != b.dd) return a.dd < b.dd;
	else if (a.hh != b.hh) return a.hh < b.hh;
	else return a.min < b.min;
}

double process(Record a, Record b){
	printf("%02d:%02d:%02d %02d:%02d:%02d", a.dd, a.hh, a.min, b.dd, b.hh, b.min);
	int time = 0, money = 0;
	//计费方法：模拟真实的时间，不断的将起始时间加1，看其是否到达终止时间
	while(a.dd < b.dd || a.hh < b.hh || a.min < b.min){
		time++;
		money += toll[a.hh];
		a.min++;
		if(a.min >= 60) { a.min = 0; a.hh++; }
		if(a.hh >= 24) { a.hh = 0; a.dd++; }
	}
	printf(" %d $%.2f\n", time, money / 100.0);
	return money / 100.0;
}

int main()
{
	for(int i = 0; i < 24; i++) scanf("%d", &toll[i]);
	int n; cin>> n;
	for(int i = 0; i < n; i++){
		scanf("%s %d:%d:%d:%d %s", rec[i].name, &rec[i].mon, &rec[i].dd, &rec[i].hh, &rec[i].min, rec[i].tag);
	}
	sort(rec, rec + n, cmp);
	int left = 0, right = 0;
	while(left < n){
		int needPrint = 0;
		while(right < n && !strcmp(rec[left].name, rec[right].name)){
			//初始为零，当满足所有条件时值变成了2 多种情况可借鉴
			if(!strcmp(rec[right].tag, "on-line") && 0 == needPrint) needPrint = 1;
			if(!strcmp(rec[right].tag, "off-line") && 1 == needPrint) needPrint = 2;
			right++;
		}
		if(2 == needPrint){
			double total = 0.0;
			printf("%s %02d\n", rec[left].name, rec[left].mon);
			for( int i = left; i < right - 1; i++){
				if(!strcmp(rec[i].tag, "on-line") && !strcmp(rec[i+1].tag, "off-line")){
					total += process(rec[i], rec[i+1]);
				}
			}
			printf("Total amount: $%.2f\n", total);
		}
		left = right;
	}
	//for(int i = 0; i < n; i++){
	//	printf("%s %d:%d:%d:%d %s\n", rec[i].name, rec[i].mon, rec[i].dd, rec[i].hh, rec[i].min, rec[i].tag);
	//}
	return 0;
}
