//2016年2月15日18时33分25秒
//2016年2月15日22时34分14秒

//提交通过编译且分数为零的情况也要输出，如果没有输出，则测试点2，4不通过
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

const int maxn = 100010;
const int maxk = 5 + 1;
int mark[maxn];

struct Student{
	int id;
	int s[maxk];//s[0]存储总分
	bool isAc[maxk];//isAC[0]存储是否有有效提交
	int acNum;
}stu[maxn];

bool cmp(int a, int b){
	if(stu[a].isAc[0] != stu[b].isAc[0]) return stu[a].isAc[0] > stu[b].isAc[0];
	else if(stu[a].s[0] != stu[b].s[0]) return stu[a].s[0] > stu[b].s[0];
	else if(stu[a].acNum != stu[b].acNum) return stu[a].acNum > stu[b].acNum;
	else return stu[a].id < stu[b].id;
}

int main()
{
	int n, k, m;
	int p[maxk];
	//input
	scanf("%d%d%d", &n, &k, &m);
	for(int i = 1; i <= k; i++){
		scanf("%d", &p[i]);
	}
	//memset的使用
	memset(stu, 0, sizeof(struct Student) * maxn);
	for(int i = 0; i < m; i++){
		int userId, problemId, scoreObtained;
		scanf("%d%d%d", &userId, &problemId, &scoreObtained);
		stu[userId].id = userId;
		//if(scoreObtained != -1) 
		stu[userId].isAc[problemId] = true;
		if(scoreObtained != -1) stu[userId].isAc[0] = 1;
		if(stu[userId].s[problemId] < scoreObtained){
			stu[userId].s[0] += (scoreObtained - stu[userId].s[problemId]);
			stu[userId].s[problemId] = scoreObtained;
			//printf("\n%d %d %d\n", stu[userId].id, problemId, stu[userId].s[problemId]);
			if(scoreObtained == p[problemId]) stu[userId].acNum++;
		}
	}
	//process
	for(int i = 0; i < maxn; i++) mark[i] = i;
	sort(mark + 1, mark + maxn, cmp);
	//for(int i = 1; i < 6; i++) cout << stu[mark[i]].id << ' ' << stu[mark[i]].s[0]  << endl;
	int rank = 1;
	for(int i = 1; i < maxn && stu[mark[i]].isAc[0]; i++){
		if(1 != i && stu[mark[i]].s[0] != stu[mark[i-1]].s[0]) rank = i;
		printf("%d", rank);
		printf(" %05d %d", stu[mark[i]].id, stu[mark[i]].s[0]);
		for(int j = 1; j <= k; j++){
			if(!stu[mark[i]].isAc[0]) continue;
			//下面一行语句 i与j容易写混，谨记******
			if(stu[mark[i]].isAc[j]) printf(" %d", stu[mark[i]].s[j]);
			else printf(" -");
		}
		printf("\n");
	}
	return 0;
}
