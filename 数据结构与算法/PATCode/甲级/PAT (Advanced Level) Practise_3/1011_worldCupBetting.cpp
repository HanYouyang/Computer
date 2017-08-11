//2016年1月30日15时46分26秒
//2016年1月30日16时11分15秒

#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	char map[3] = {'W', 'T', 'L'};
	double profit = 1.0, tmp;
	int maxid;
	double m;	
	for(int i = 0; i < 3; i++){
		tmp = 0.0;
		for(int j = 0; j < 3; j++){
			cin >> m;
			if(m > tmp){
				tmp = m;
				maxid = j;
			}
		}
		profit *= tmp;
		printf("%c ", map[maxid]);
	}
	double sumprofit = (profit*0.65-1.0)*2;
	printf("%.2f", sumprofit);
	return 0;
}
