#include <stdio.h>
#include <string.h>

typedef struct student{
	char name[12];
	char ID[12];
	int score;
}student;

int main(){
	student stu[100];
	int n;
	student maxscore = {" ", " ", 0};
	student minscore = {" ", " ", 100};
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%s", stu[i].name);
		scanf("%s", stu[i].ID);
		scanf("%d", &stu[i].score);
		if(stu[i].score > maxscore.score)
			//Voluation of struct, all the following two methods can work
			maxscore = stu[i];
			//memcpy(&maxscore, &stu[i], sizeof(struct student));
		if(stu[i].score < minscore.score)
			minscore = stu[i];
			//memcpy(&minscore, &stu[i], sizeof(struct student));
	}
	printf("%s %s\n", maxscore.name, maxscore.ID);
	printf("%s %s\n", minscore.name, minscore.ID);
	return 0;
}
