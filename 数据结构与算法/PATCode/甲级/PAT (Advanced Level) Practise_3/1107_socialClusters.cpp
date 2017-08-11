//2016年3月4日11时22分49秒
//2016年3月4日12时19分28秒
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;
const int maxn = 1010;//people的最大数

vector<int> hobby[maxn];//hobby[i]存储有第i个爱好的人的编号
int father[maxn], isRoot[maxn] = {0};
//father[i]存储第i个人的父亲;是否是根结点，并记录在这个根结点下元素个数

int findFather(int x)
{//查找父亲
	if(x == father[x]){
		return x;
	} else {
		int F = findFather(father[x]);
		father[x] = F;
		return F;
	}
}

void Union(int a, int b)
{//合并
	int faA = findFather(a);
	int faB = findFather(b);
	if(faA != faB){
		father[faA] = faB;
	}
}

void init(int n)
{//初始化集合
	for(int i = 1; i <= n; i++){
		father[i] = i;
	}
}

bool cmp(int a, int b){
	return a > b;
}

int main()
{
	int n, k;//人数，每个人的爱好个数
	scanf("%d", &n);
	init(n);//不要忘记初始化集合
	for(int i = 1; i <= n; i++){
		scanf("%d:", &k);//输入爱好的个数
		for(int j = 0; j < k; j++){
			int temp;
			scanf("%d", &temp);//输入每个爱好
			hobby[temp].push_back(i);//将当前人的编号插入到该爱好的vector中
		}
	}
	for(int i = 1; i <= 1000; i++){
		if(hobby[i].size() < 2) continue;//必须有****************************************这儿有个问题
		//如果不判断hobby[i].size() < 2，则下面即使j >= hobby[i].size() - 1 也会进入循环，为什么？？？？
		//hobby[i].size()返回的是什么类型？？？？？？？？？？？？？
		for(int j = 0; j < hobby[i].size() - 1; j++){
			Union(hobby[i][j], hobby[i][j + 1]);//合并有共同爱好的两个人
		}
	}
	for(int i = 1; i <= n; i++){
		isRoot[findFather(i)]++;//i的根结点是findFather[i]，人数加1
	}
	sort(isRoot + 1, isRoot + n + 1, cmp);//从大到小排序
	int num = 0;//记录集合数目
	for(int i = 1; i <= n; i++){
		if(isRoot[i] == 0) break;//因为已经排好序，如果为零，则记录完毕
		num++;//只记录不为零的isRoot[i]
	}
	printf("%d\n", num);//输出集合个数
	for(int i = 1; i <= num; i++){
		printf("%d", isRoot[i]);//从大到小输出每个集合的人数
		if(i < num) printf(" ");
		else printf("\n");
	}
	return 0;
}
