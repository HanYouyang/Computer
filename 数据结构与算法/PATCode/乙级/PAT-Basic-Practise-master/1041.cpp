#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

struct Stu{
	string zkz;
	int zwh;
};

int main()
{
	unordered_map<int, Stu> hash;
	string s;
	int sj, zw;
	int N;
	cin >> N;
	for(int i=0; i<N; i++){
		cin >> s >> sj >> zw;
		Stu stu;
		stu.zkz = s;
		stu.zwh = zw;
		hash[sj] = stu;
	}
	int M;
	cin >> M;
	int k;
	for(int i=0; i<M; i++){
		cin >> k;
		Stu s = hash[k];
		cout << s.zkz << " " << s.zwh << endl;
	}
	return 0;
} 
