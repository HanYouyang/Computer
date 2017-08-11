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
