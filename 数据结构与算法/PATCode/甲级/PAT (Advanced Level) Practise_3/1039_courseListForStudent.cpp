//2016年2月24日12时11分45秒
//2016年2月24日13时32分45秒

//用c++中的map来实现姓名与学生编号之间的映射，会在测试点5超时
//使用map与string会超时，本题使用字符串hash进行求解，这种方法虽然占用内存很大，但避免了超时
//测试点5占用内存为10752KB，用时77ms
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

const int maxn = 26 * 26 * 26 * 10 + 1;

//字符串到学生编号之间的映射
int getID(char s[])
{
	int tempid = 0;
	for(int i = 0; i < 3; i++){
	//前三位是字母
		tempid = tempid * 26 + s[i] - 'A';
	}
	tempid = tempid * 10 + s[3] - '0';
	//最后一位是数字
	return tempid;
}

int main()
{
	int n, k;//人数，课程数
	int ik, in;//课程编号，选课人数
	scanf("%d%d", &n, &k);
	vector<int> stu[maxn];
	for(int i = 0; i < k; i++){
	//每个课程的处理
		scanf("%d%d", &ik, &in);
		for(int j = 0; j < in; j++){
		//每个课程的学生记录
			char name[5];
			scanf("%s", name);
			int index = getID(name);
			stu[index].push_back(ik);
		}
	}
	for(int i = 0; i < n; i++){
	//输出n个查询学生的结果
		char name[5];
		scanf("%s", name);
		int id = getID(name);
		sort(stu[id].begin(),stu[id].end());
		//从小到达排序
		printf("%s", name);//输出姓名
		int size = stu[id].size();
		printf(" %d", size);//输出选课数
		for(int j = 0; j < size; j++){
			printf(" %d", stu[id][j]);
			//输出所选的课程的编号
		}
		printf("\n");
	}
	return 0;
}
