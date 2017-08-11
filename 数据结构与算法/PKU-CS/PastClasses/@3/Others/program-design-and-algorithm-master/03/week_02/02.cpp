#include<iostream>
#include<cstdlib>
#include<cstring>

using namespace std;


class Student {
private:
	char cName[21];
	int cAge;
	char cNum[11];
	int cA1;
	int cA2;
	int cA3;
	int cA4;
public:
	void setProp(char * name, int age, char * num, int a1, int a2, int a3, int a4) {
		strcpy(cName, name);
		cAge = age;
		strcpy(cNum, num);
		cA1 = a1;
		cA2 = a2;
		cA3 = a3;
		cA4 = a4;
	};

	void printAva() {
		cout << cName << ',' << cAge << ',' << cNum << ',' << ((cA1 + cA2 + cA3 + cA4) / 4) << endl;
	};
};

int main() {
	char name[101] = { '\0' }, num[101] = { '\0' }, a;
	int age = 0, a1 = 0, a2 = 0, a3 = 0, a4 = 0;

	cin.getline(name, 101, ',');
	cin >> age;
	cin.get();
	cin.getline(num, 101, ',');
	cin >> a1 >> a >> a2 >> a >> a3 >> a >> a4;

	Student stu;
	stu.setProp(name, age, num, a1, a2, a3, a4);
	stu.printAva();

	return 0;
}