#include <iostream>

using namespace std;

int main()
{
	int N;
	int id, grade;
	int score[100010] = {0};
	int maxid;
	cin >> N;
	maxid = 0;
	score[maxid] = -1;
	for(int i = 0; i < N; i++){
		cin >> id >> grade;
		score[id] += grade;
		if(score[maxid]< score[id])
			maxid = id;
	}
	cout << maxid << ' ' << score[maxid];
	return 0;
}