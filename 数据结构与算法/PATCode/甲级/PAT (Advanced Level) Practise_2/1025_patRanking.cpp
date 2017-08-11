//2016年2月14日14时19分12秒
//2016年2月14日
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

const int maxn = 30010;

struct Student{
	string name;
	int score;
	int rank[3];
}stu[maxn];

bool cmp(Student a, Student b){
	if(a.score != b.score) return a.score > b.score;
	else return a.name < b.name;
}

void ranking(int left, int right, int index){
	stu[left].rank[index] = 1;
	for(int i = left + 1; i < right; i++){
		if(stu[i].score == stu[i - 1].score){
			stu[i].rank[index] = stu[i - 1].rank[index];
		} else {
			stu[i].rank[index] = i - left + 1;
		}
	}
}

int main()
{
	int n = 0, k = 0, total = 0;
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> k;
		for(int j = 0; j < k; j++){
			cin >> stu[total+j].name >> stu[total+j].score;
			stu[total+j].rank[1] = i;
		}
		sort(stu+total, stu+total+k, cmp);
		ranking(total, total + k, 2);
		total += k;
	}
	sort(stu, stu + total, cmp);
	ranking(0, total, 0);
	cout << total << endl;
	for(int i = 0; i < total; i++)
		cout << stu[i].name << ' ' << stu[i].rank[0] << ' '
			<< stu[i].rank[1] << ' ' << stu[i].rank[2] << endl;
	return 0;
}
