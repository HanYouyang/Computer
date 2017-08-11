#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;

class Student
{
	string name;
	int age;
	string xueno;
	int avgsc1, avgsc2, avgsc3, avgsc4;
public:	
	Student(string nm, int ag, string xh, int avg1, int avg2, int avg3, int avg4)
	{
		name = nm;
		age = ag;
		xueno = xh;
		avgsc1 = avg1;
		avgsc2 = avg2;
		avgsc3 = avg3;
		avgsc4 = avg4;
	}
	Student(){}
	string getname()
	{
		return name;
	}
	string getxh()
	{
		return xueno;
	}
	int getage()
	{
		return age;
	}
	int getavg()
	{
		return (avgsc1 + avgsc2 + avgsc3 + avgsc4) / 4;
	}
};

int main()
{
	char nm[100];
	int ag;
	char xh[100];
	int sc1, sc2, sc3, sc4;
	scanf("%[^,],%d,%[^,],%d,%d,%d,%d",nm,&ag,xh,&sc1,&sc2,&sc3,&sc4);
	
	Student s(nm,ag,xh,sc1,sc2,sc3,sc4);
	cout << s.getname()<<"," << s.getage()<<"," << s.getxh()<<"," << s.getavg() << endl;
	
	return 0;
}

