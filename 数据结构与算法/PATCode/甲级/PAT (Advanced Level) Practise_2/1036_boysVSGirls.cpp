//2016年1月30日18时27分36秒
//2016年1月30日18时49分41秒

//这题可以将highestf.grade赋值为-1，lowestm.grade赋值为101
//因为输入的成绩时在[0, 100]之间，因此可以直接根据highestf.grade与lowestm.grade
//来判断是否有女生和男生，而不用再设置bool类型的absentf、absentm与absent

#include <iostream>
#include <cstdio>

using namespace std;

struct student{
	char name[20];
	char gender;
	char id[20];
	int grade;
}highestf, lowestm, temp;

void init(){
	highestf.grade = 0;
	lowestm.grade = 100;
}

int main()
{
	init();
	int n;
	bool absentf = true;
	bool absentm = true;
	bool absent = true;
	cin >> n;
	while(n--){
		scanf("%s %c %s %d", temp.name, &temp.gender, temp.id, &temp.grade);
		if(temp.gender == 'F'){
			absentf = false;
			if(temp.grade > highestf.grade){
				highestf = temp;
			}
		}
		else{
			absentm = false;
			if(temp.grade < lowestm.grade){
				lowestm = temp;
			}
		}
	}
	if(!absentf)
		cout << highestf.name << ' ' << highestf.id << endl;
	else
		cout << "Absent" << endl;
	if(!absentm)
		cout << lowestm.name << ' ' << lowestm.id << endl;
	else
		cout << "Absent" << endl;
	if(absentf || absentm)
		cout << "NA" << endl;
	else
		cout << highestf.grade - lowestm.grade;
	return 0;
}
