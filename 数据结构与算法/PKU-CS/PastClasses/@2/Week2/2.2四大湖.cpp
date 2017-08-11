#include<iostream>
#include<stdlib.h>
using namespace std;
int main(){
	int py, dt, th, hz, sum[4] = { 0 };
	for (py = 1; py <= 4; py++){
		for (dt = 1; dt <= 4; dt++){
			if (py == dt) continue;
			for (th = 1; th <= 4; th++){
				if (th == py || th == dt) continue;
				hz = 10 - py - dt - th;
				sum[0] = (py == 3) + (dt == 1) + (hz == 4);
				sum[1] = (py == 2) + (dt == 4) + (th == 3) + (hz == 1);
				sum[2] = (dt == 3) + (hz == 4);
				sum[3] = (py == 1) + (dt == 3) + (th == 4) + (hz == 2);
				if (sum[0] == 1 && sum[1] == 1 && sum[2] == 1 && sum[3] == 1){
					cout << py << endl;
					cout << dt << endl;
					cout << th << endl;
					cout << hz << endl;
				}
			}
		}
	}
	system("pause");
	return 0;
}
