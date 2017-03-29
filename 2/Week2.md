# Week2.综合编程练习
## 2.1寻找下标

```c++
#include <iostream>
using namespace std;

int main() {
    int N = 0;
    cin >> N;
    int a[1000];
    for ( int i = 0; i < N; i++){
        cin >> a[i];
    }
    for ( int j = 0; j < N; j++){
        if( a[j] == j){
            cout << a[j] << endl;
            break;
        }
        if((j == N-1) && (a[j] != j)){
            cout << "N";
        }
    }
    return 0;
}
```
## 2.2四大湖

```c++
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
```
## 2.3发票统计

```c++
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	float sum[6];
	for (int i = 0; i < 3; i++) {
		int a;
		cin >> a;
		int n;
		cin >> n;
		for (int j = 0; j < n; j++) {
			char b;
			cin >> b;
			float c;
			cin >> c;
			sum[a - 1] = sum[a - 1] + c;
			if (b == 'A') {				
				sum[3] = sum[3] + c;
			} else if (b == 'B') {
				sum[4] = sum[4] + c;
			} else if (b == 'C') {
				sum[5] = sum[5] + c;
			}
		}
	}
	cout << fixed << setprecision(2);
	cout << "1 " << sum[0] << endl;
	cout << "2 " << sum[1] << endl;
	cout << "3 " << sum[2] << endl;
	cout << "A " << sum[3] << endl;
	cout << "B " << sum[4] << endl;
	cout << "C " << sum[5] << endl;
	return 0;
}
```
## 2.4TNK

```c++
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	float sum[6];
	for (int i = 0; i < 3; i++) {
		int a;
		cin >> a;
		int n;
		cin >> n;
		for (int j = 0; j < n; j++) {
			char b;
			cin >> b;
			float c;
			cin >> c;
			sum[a - 1] = sum[a - 1] + c;
			if (b == 'A') {				
				sum[3] = sum[3] + c;
			} else if (b == 'B') {
				sum[4] = sum[4] + c;
			} else if (b == 'C') {
				sum[5] = sum[5] + c;
			}
		}
	}
	cout << fixed << setprecision(2);
	cout << "1 " << sum[0] << endl;
	cout << "2 " << sum[1] << endl;
	cout << "3 " << sum[2] << endl;
	cout << "A " << sum[3] << endl;
	cout << "B " << sum[4] << endl;
	cout << "C " << sum[5] << endl;
	return 0;
}
```

```c++
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdlib.h>
#include<stdio.h>
using namespace std;
int main(){
	int y, m, d;
	scanf("%d-%d-%d", &y, &m, &d);
	int isleapyear = y % 400 == 0 || (y%4==0&&y%100!=0);
	switch (m){
	case 1:case 3: case 5: case 7:case 8:case 10:
		if (d== 31){
			d = 1;m++;
		}
		else{
			d++;
		}		
		break;
	case 2:
		if (isleapyear){
			if (d == 29){
				d=1; m++;
			}
			else{
				d++;
			}
		}
		else{
			if (d == 28){
				d = 1; m++;
			}
			else{
				d++;
			}
		}
		break;
	case 4:case 6:case 9:case 11:
		if (d == 30){
			d = 1; m++;
		}
		else{
			d++;
		}
		break;
	case 12:
		if (d == 31){
			d = 1; m = 1; y++;
		}
		else{
			d++;
		}
		break;
	}
	printf("%d-%02d-%02d\n", y, m, d);
	system("pause");
	return 0;
}
```
## 2.5细菌分组

```c++
#include <iostream>
using namespace std;
//细菌实验分组
int n;//n为细菌数量

void ReOrder(int id[], double rate[]){
    //对整个细菌排序
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n - i -1; j++){
            if(rate[j+1] > rate[j]){
                int tmpID = id[j];
                id[j] = id[j+1];
                id[j+1] = tmpID;
                double tmpRate = rate[j];
                rate[j] = rate [j+1];
                rate[j+1] = tmpRate;
            }
        }
    }
}

int main(){
    //id记录细菌的编号，rate记录细菌的繁殖率
    int id[100];
    double rate[100];

    cin >> n;

    for(int i = 0; i < n; i++){
        int initial, final;
        cin >> id[i] >> initial >> final;
        rate[i] = (double)final / initial;
    }

    ReOrder(id, rate);

    //记录最大的差
    double maxDiff = 0;
    //和最大的下标
    int maxDiffIndex = 0;
    for(int i =0; i < n-1;i++){
        double diff = rate[i] - rate[i+1];
        if(maxDiff < diff){
            maxDiff = diff;
            maxDiffIndex = i;
        }
    }

    //输出繁殖率较大的那组细菌
    cout << maxDiffIndex + 1 << endl;
    for(int i = maxDiffIndex; i >= 0; i--){
        cout << id[i] << endl;
    }

    //输出繁殖率较小的那组细菌
    cout << n- maxDiffIndex - 1 << endl;
    for(int i = n - 1; i >= maxDiffIndex + 1; i--){
        cout << id[i] << endl;
    }

    return 0;
}
```

```c++
#include<iostream>
#include<stdlib.h>
using namespace std;
struct Bact{
	int no; int befer; int after; double rate;
};
typedef struct Bact bact;
int panduan(bact *b, int n){
	double max = b[1].rate - b[0].rate; int index = 0;
	for (int i = 1; i < n - 2; i++){
		if (b[i+1].rate-b[i].rate>max){
			max = b[i + 1].rate - b[i].rate;
			index = i;
		}
	}
	return index;
}

int main5(){
	int n; cin >> n; int no, befer, after; double rate;
	bact *b = (bact *)malloc(sizeof(bact)* 100);
	for (int i = 0; i < n; i++){
		cin >> no; cin >> befer; cin >> after;
		rate = (double)(after - befer) / befer;
		b[i].no = no; b[i].befer = befer; b[i].after = after; b[i].rate = rate;
	}
	int temp1, temp2, temp3; double temp;
	for (int i = 0; i < n - 1; i++){
		for (int j = 0; j < n - i - 1; j++){
			if (b[j].rate>b[j + 1].rate){
				temp1 = b[j].no; b[j].no = b[j + 1].no; b[j + 1].no = temp1;
				temp2 = b[j].befer; b[j].befer = b[j + 1].befer; b[j + 1].befer = temp2;
				temp3 = b[j].after; b[j].after = b[j + 1].after; b[j + 1].after = temp3;
				temp = b[j].rate; b[j].rate = b[j + 1].rate; b[j + 1].rate = temp;
			}
		}
	}
	int t = panduan(b, n);
	cout << n - t - 1 << endl;
	for (int i = t + 1; i < n; i++){
		cout << b[i].no << endl;
	}
	cout << t + 1 << endl;
	for (int i = 0; i <= t; i++){
		cout << b[i].no << endl;
	}
	free(b);
	return 0;
}
```
## 2.6流感传染

```c++
#include <iostream>
using namespace std;
//流感传染
int main(){
    int n, m;
    cin >> n;
    char matrix[n][n];

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> matrix[i][j];
        }
    }

    cin >> m;

    for(int k = 1; k < m; k++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(matrix[i][j] == '@'){
                    if(i - 1 >= 0 && matrix[i - 1][j] =='.')
                        matrix[i - 1][j] = '*';
                    if(i + 1 < n && matrix[i + 1][j] == '.')
                        matrix[i + 1][j] = '*';
                    if(j - 1 >= 0 && matrix[i][j - 1] =='.')
                        matrix[i][j - 1] = '*';
                    if(j + 1 < n && matrix[i][j + 1] == '.')
                        matrix[i][j + 1] = '*';
                }
            }
        }
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                if(matrix[i][j] == '*')
                    matrix[i][j] = '@';
    }

    int sum = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(matrix[i][j] == '@')
                sum += 1;

    cout << sum << endl;
    return 0;
}
```


