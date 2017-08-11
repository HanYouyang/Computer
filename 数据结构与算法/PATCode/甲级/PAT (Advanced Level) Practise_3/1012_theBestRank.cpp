//2016年2月14日08时36分25秒
//2016年2月14日09时30分48秒
#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = 2010;

struct student{
	int id;
	int grade[4];
}stu[maxn];

char map[5] = {'A', 'C', 'M', 'E'};
//内存限制为65535kB，约为2^24个int型变量（16,000,000个int型变量）
//此处用空间换时间
int course[1000000][4] = {0};
int index;

bool cmp(student a, student b)
{
	return a.grade[index] > b.grade[index];
}

int main()
{
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		cin >> stu[i].id >> stu[i].grade[1] >> stu[i].grade[2] >> stu[i].grade[3];
		stu[i].grade[0] = (stu[i].grade[1] + stu[i].grade[2] + stu[i].grade[3]) / 3;
	}
	for(index = 0; index < 4; index++){
		sort(stu, stu + n, cmp);
		course[stu[0].id][index] = 1;
		for(int i = 1; i < n; i++){
			if(stu[i].grade[index] == stu[i - 1].grade[index]){
				course[stu[i].id][index] = course[stu[i - 1].id][index];
			} else {
				course[stu[i].id][index] = i + 1;
			}
		}
	}
	int checkId;
	for(int i = 0; i < m; i++){
		cin >> checkId;
		if(course[checkId][0] == 0){
			cout << "N/A" << endl;
		} else {
			int k = 0;
			for(int j = 0; j < 4; j++){
				if(course[checkId][j] < course[checkId][k]){
					k = j;
				}
			}
			cout << course[checkId][k] << ' ' << map[k] << endl;
		}
	}
	return 0;
}
