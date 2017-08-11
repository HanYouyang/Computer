//2016年2月24日13时44分24秒
//2016年2月24日14时16分30秒

//使用vector<string>并用cin/cout输入输出，测试点3会超时
//因此使用二位字符串数组存放姓名，vector<int>中存放姓名的下标
//并使用scanf输入，printf输出
#include <iostream>
#include <cstring>
#include <vector>
#include <cstdio>
#include <algorithm>

using namespace std;

const int maxk = 2510;
const int maxn = 40010;
char name[maxn][5];//姓名存储数组
vector<int> cou[maxk];//每个课程里存放姓名的下标

bool cmp(int a, int b)
{//姓名按照字典序排序
	return strcmp(name[a], name[b]) < 0;
}

int main()
{
	int n, k;
	scanf("%d%d", &n, &k);//总人数，总课程数
	for(int i = 0; i < n; i++){
		int courseCnt;//当前学生修读的课程数
		scanf("%s%d", name[i], &courseCnt);//当前学生的姓名，修读课程数
		for(int j = 0; j < courseCnt; j++){
			int course;//当前学生修读的课程
			scanf("%d", &course);
			cou[course].push_back(i);//相应课程加入该学生的信息
		}
	}
	for(int i = 1; i <= k; i++){
		int stuCnt = cou[i].size();
		sort(cou[i].begin(), cou[i].end(), cmp);
		//按照姓名字典序对存储姓名下标的vector排序
		printf("%d %d\n", i, stuCnt);//输出课程编号、修读学生数
		vector<int>::iterator it = cou[i].begin();
		while(it != cou[i].end()){
			printf("%s\n", name[*it]);//输出修读该课程的每个学生的姓名
			it++;
		}
	}
	return 0;
}
