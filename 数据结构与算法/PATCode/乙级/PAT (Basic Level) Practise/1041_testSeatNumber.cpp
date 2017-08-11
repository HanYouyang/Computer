//2016年1月30日09时22分38秒
//2016年1月30日09时34分43秒

//improvement
#include <iostream>

using namespace std;

const int maxn = 1010;

struct Student{
	long long id;
	int examSeat;
}testSeat[maxn];

int main()
{
	int n, m, seat, examSeat;
	long long id;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> id >> seat >> examSeat;
		testSeat[seat].id = id;
		testSeat[seat].examSeat = examSeat;
	}
	cin >> m;
	while(m--){
		cin >> seat;
		cout << testSeat[seat].id << ' '
			<< testSeat[seat].examSeat << endl;
	}
	return 0;
}

//#include <iostream>
//
//using namespace std;
//
//const int maxn = 1005;
//
//int main()
//{
//	long long info[maxn][3];
//	int N, M, testnum;
//	cin >> N;
//	for(int i = 0; i < N; i++){
//		cin >> info[i][0] >> info[i][1] >> info[i][2];
//	}
//	cin >> M;
//	while(M--){
//		cin >> testnum;
//		for(int i = 0; i < N; i++){
//			if(info[i][1] == testnum){
//				cout << info[i][0] << ' ' << info[i][2] << endl;
//			break;
//			}
//		}
//	}
//	return 0;
//}
