//2016年2月15日22时39分41秒
//2016年2月15日
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

//maxn为100时测试点3出现断错
const int maxn = 1000;

struct Student{
	string name;
	string id;
	int grade;
}stu[maxn];

bool cmp(Student a, Student b){
	return a.grade >= b.grade;
}

int main()
{
	int n, grade1, grade2;
	bool isPrint = false;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> stu[i].name >> stu[i].id >> stu[i].grade;
	}
	cin >> grade1 >> grade2;

	sort(stu, stu + n, cmp);
	
	for(int i = 0; i < n; i++){
		if(stu[i].grade >= grade1 && stu[i].grade <= grade2){
			cout << stu[i].name << ' ' << stu[i].id << endl;
			isPrint = true;
		}
	}
	if(!isPrint) cout << "NONE" << endl;
	return 0;
}
