#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct student * stu;
struct student{
	char name[11];
	char number[11];
	int grade;
};
int main()
{
	int i, n;
	stu max, min, temp;
	max = (stu) malloc(sizeof(struct student));
	min = (stu) malloc(sizeof(struct student));
	temp = (stu) malloc(sizeof(struct student));
	
	scanf("%d", &n);
	scanf("%s %s %d", temp->name, temp->number, &temp->grade);
	strcpy(max->name, temp->name);
	strcpy(max->number, temp->number);
	max->grade = temp->grade;
	strcpy(min->name, temp->name);
	strcpy(min->number, temp->number);
	min->grade = temp->grade;
	
	for(i=1; i<n; i++){
		scanf("%s%s%d", temp->name, temp->number, &temp->grade);
		if(temp->grade > max->grade){
			strcpy(max->name, temp->name);
			strcpy(max->number, temp->number);
			max->grade = temp->grade;
			continue;
		}
		if(temp->grade < min->grade){
			strcpy(min->name, temp->name);
			strcpy(min->number, temp->number);
			min->grade = temp->grade;
			continue;
		}
		printf("%s %s\n%s %s\n", max->name, max->number, min->name, min->number);
	}
	
	return 0;
}
