//2016年3月8日19时06分00秒
//2016年3月8日19时20分28秒
//codeup题目编号27730
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
const int maxn = 310;
struct Student
{
	char id[15];
	int score;
	int cross;
}stu[maxn];
int a, b, c, d, l, n;
int crossNum = 0;

bool cmp(Student a, Student b)
{
	if(a.cross != b.cross){
		return a.cross > b.cross;
	} else if(a.score != b.score){
		return a.score > b.score;
	} else {
		return strcmp(a.id, b.id) < 0;
	}
}

int main()
{
	scanf("%d%d%d%d%d", &a, &b, &c, &d, &l);
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		int temp1, temp2, temp3, temp4;
		scanf("%s %d%d%d%d", stu[i].id, &temp1, &temp2, &temp3, &temp4);
		stu[i].score = temp1 + temp2 + temp3 + temp4;
		if(temp1 >= a && temp2 >= b && temp3 >= c && temp4 >= d && stu[i].score >= l){
			stu[i].cross = 1;
			crossNum++;
		} else {
			stu[i].cross = 0;
		}
	}
	sort(stu, stu + n, cmp);
	printf("%d\n", crossNum);
	for(int i = 0; i < crossNum; i++){
		printf("%s %d\n", stu[i].id, stu[i].score);
	}
	return 0;
}
