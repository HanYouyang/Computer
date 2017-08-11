#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

class Student {
private:
	char name[50],stuId[50];
	int age;
	int score_1,score_2,score_3,score_4, ave_score;

public:
	void set_and_print_name(char *);
	void set_and_print_age(int );
	void set_and_print_stuId(char *);
	void set_and_print_average_score(int ,int, int, int);
};

void Student::set_and_print_name(char *in){
	strcpy(name,in);
	std::cout<<name<<",";
}

void Student::set_and_print_age(int  in) {
	age = in;
	std::cout<<age<<",";
}

void Student::set_and_print_stuId(char *in){
	strcpy(stuId,in);
	std::cout<<stuId<<",";
}

void Student::set_and_print_average_score(int in_1,\
	int in_2, int in_3, int in_4){
	score_1 = in_1;
	score_2 = in_2;
	score_3 = in_3;
	score_4 = in_4;
	
	ave_score = 0.25*(in_1+in_2+in_3+in_4);
	std::cout<<ave_score<<endl;
}


int main() {
	char str_in[50];
	char name[50],stuId[50];
	int age;
	int score_1,score_2,score_3,score_4;
	Student stu_1;

	cin.getline(str_in, 50, ',');
	strcpy(name,str_in);
	
	cin.getline(str_in, 50, ',');
	age = strtol(str_in, NULL, 10);

	cin.getline(str_in, 50, ',');
	strcpy(stuId,str_in);

	cin.getline(str_in, 50, ',');
	score_1 = strtol(str_in, NULL, 10);
	cin.getline(str_in, 50, ',');
	score_2 = strtol(str_in, NULL, 10);
	cin.getline(str_in, 50, ',');
	score_3 =strtol(str_in, NULL, 10);
	cin.getline(str_in, 50);
	score_4 =strtol(str_in, NULL, 10);

	stu_1.set_and_print_name(name);
	stu_1.set_and_print_age(age );
	stu_1.set_and_print_stuId(stuId);
	stu_1.set_and_print_average_score(score_1,score_2\
		,score_3,score_4);
	return 0;
}
