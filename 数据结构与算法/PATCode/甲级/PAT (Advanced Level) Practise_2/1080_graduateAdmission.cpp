//2016年3月7日17时38分01秒
//2016年3月7日18时32分01秒
#include <cstdio>
#include <algorithm>

using namespace std;

struct Student
{//存储学生信息的结构体
	int ge, gi, sum;
	int r, stuID;
	int cho[6];
}stu[40010];

struct School
{//存储学校信息的结构体
	int quota;
	int stuNum;
	int id[40010];
	int lastAdmit;
}sch[110];
int n, m, k;

bool cmpStu(Student a, Student b)
{//根据成绩来对学生进行排序
	if(a.sum != b.sum){
		return a.sum > b.sum;
	} else {
		return a.ge > b.ge;//若写成a.ge >= b.ge 则测试点4运行超时************************************************************
	}
}

bool cmpID(int a, int b)
{//根据ID对学生进行排序
	return stu[a].stuID < stu[b].stuID;
}

int main()
{
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 0; i < m; i++){//输入学校信息并初始化
		scanf("%d", &sch[i].quota);
		sch[i].stuNum = 0;
		sch[i].lastAdmit = 0;
	}
	for(int i = 0; i < n; i++){//输入学生信息并初始化
		scanf("%d%d", &stu[i].ge, &stu[i].gi);
		stu[i].sum = stu[i].ge + stu[i].gi;
		stu[i].stuID = i;
		for(int j = 0; j < k; j++){
			scanf("%d", &stu[i].cho[j]);
		}
	}
	sort(stu, stu + n, cmpStu);//对10^5个int型变量排序没有超时*******************************************************************
	for(int i = 0; i < n; i++){//对学生进行排序
		if(i > 0 && stu[i].sum == stu[i - 1].sum && stu[i].ge == stu[i - 1].ge){
			stu[i].r = stu[i - 1].r;
		} else {
			stu[i].r = i;
		}
	}
	for(int i = 0; i < n; i++){//对于每一个学生
		for(int j = 0; j < k; j++){//对这个学生所选择的学校
			int choice = stu[i].cho[j];
			int num = sch[choice].stuNum;//该学校已招收人数
			int last = sch[choice].lastAdmit;//该学校最后一个录取学生序号
			if(num < sch[choice].quota || (last != -1 && stu[i].r == stu[last].r))
			{//如果人数没招满或者最后一个招收的学生排名与当前学生排名相同，招收该学生
				sch[choice].id[num] = i;
				sch[choice].lastAdmit = i;
				sch[choice].stuNum++;
				break;
			}
		}
	}
	for(int i = 0; i < m; i++){//对于每个学校
		if(sch[i].stuNum > 0){//如果招收学生人数大于0
			sort(sch[i].id, sch[i].id + sch[i].stuNum, cmpID);//根据编号对招收的学生排序
			for(int j = 0; j < sch[i].stuNum; j++){//按照格式输出每个学生
				printf("%d", stu[sch[i].id[j]].stuID);//此处易错*****************************************************
				if(j < sch[i].stuNum - 1) printf(" ");
			}
		}
		printf("\n");//必须输出换行符
	}
	return 0;
}


////2016年2月16日08时40分33秒
////2016年2月16日10时20分17秒//测试点4超时
//#include <iostream>
//#include <algorithm>
//#include <cstdio>
//#include <cstring>
//
//using namespace std;
//
//const int maxn = 40000 + 10;
//const int maxm = 100 + 5;
//const int maxk = 5 + 1;
//const int maxquota = 600;
//
//struct Student{
//	int rank;
//	int id;
//	int ge, gi, gsum;
//	int opt[maxk];
//	int admitted;
//}stu[maxn];
//
//bool cmp1(Student a, Student b)
//{
//	if(a.gsum != b.gsum) return a.gsum > b.gsum;
//	else return a.ge > b.ge;
//}
//
//bool cmp2(int a, int b){
//	return a < b;
//}
//
//int main()
//{
//	int n, m, k;
//	int quota[maxm];//招生人数额度
//	int count[maxm] = {0};//当前实际招生人数
//	int result[maxm][maxquota];//招生学生的编号
//	int lastAdmit[maxm];//最后一个招收的学生编号
//	memset(result, -1, sizeof(int) * maxm * maxquota);
//	memset(lastAdmit, -1, sizeof(int) * maxm);
//	memset(stu, -1, sizeof(Student) * maxn);
//	scanf("%d%d%d", &n, &m, &k);
//	for(int i = 0; i < m; i++) scanf("%d", &quota[i]);
//	for(int i = 0; i < n; i++){
//		stu[i].id = i;
//		scanf("%d%d", &stu[i].ge, &stu[i].gi);
//		stu[i].gsum = (stu[i].ge + stu[i].gi);
//		for(int j = 0; j < k; j++){
//			scanf("%d", &stu[i].opt[j]);
//		}
//	}
//
//	sort(stu, stu + n, cmp1);
//
//	for(int i = 0; i < n; i++){
//		if(0 == i) stu[i].rank = 1;
//		else{
//			if(stu[i].gsum == stu[i - 1].gsum && stu[i].ge == stu[i - 1].ge){
//				stu[i].rank = stu[i - 1].rank;
//			}
//			else stu[i].rank = i + 1;
//		}
//	}
//	int left = 0, right = 0;
//	while(left <= right && left < n){
//		while(stu[right].rank == stu[left].rank) right++;
//		for(int i = left; i < right; i++){
//			for(int j = 0; j < k; j++){
//				if(count[stu[i].opt[j]] < quota[stu[i].opt[j]]){
//					result[stu[i].opt[j]][count[stu[i].opt[j]]] = stu[i].id;
//					count[stu[i].opt[j]]++;
//					stu[i].admitted = stu[i].opt[j];
//					break;
//				}
//				else if((right-left)>1){
//					for(int temp = left; temp <= i; temp++){
//						if(stu[temp].admitted == stu[i].opt[j]){
//							result[stu[i].opt[j]][count[stu[i].opt[j]]] = stu[i].id;
//							count[stu[i].opt[j]]++;
//							stu[i].admitted = stu[i].opt[j];
//							break;
//						}
//					}
//				}
//			}
//		}
//		left = right;
//	}
//	for(int i = 0; i < m; i++){
//		if(-1 == result[i][0]){
//			printf("\n");
//			continue;
//		}
//		else{
//			sort(result[i], result[i] + count[i], cmp2);
//			for(int j = 0; j < count[i]; j++){
//				if(j == 0) printf("%d", result[i][j]);
//				else printf(" %d", result[i][j]);
//			}
//			printf("\n");
//		}
//	}
//	return 0;
//}
