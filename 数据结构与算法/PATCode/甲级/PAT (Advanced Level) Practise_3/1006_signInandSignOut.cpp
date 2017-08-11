//2016年1月30日16时17分49秒
//2016年1月30日16时49分42秒

#include <iostream>
#include <cstdio>

using namespace std;

struct person{
	char name[20];
	int inh, inm, ins;
	int outh, outm, outs;
}earliest, latest, temp;

// a早于b, return true;
bool isEarlier(person a, person b){
	if(a.inh != b.inh) return a.inh < b.inh;
	else if(a.inm != b.inm) return a.inm < b.inm;
	else return a.ins < b.ins;
}

// a晚于b，return true;
bool isLater(person a, person b){
	if(a.outh != b.outh) return a.outh > b.outh;
	else if(a.outm != b.outm) return a.outm > b.outm;
	else return a.outs > b.outs;
}

void init(){
	earliest.inh = 24; earliest.inm = 60; earliest.ins = 60;
	latest.outh = 0; latest.outm = 0; latest.outs = 0;
}

int main()
{
	init();
	int m;
	scanf("%d", &m);
	while(m--){
		scanf("%s %d:%d:%d %d:%d:%d", temp.name, &temp.inh, &temp.inm, &temp.ins, &temp.outh, &temp.outm, &temp.outs);
		if(isEarlier(temp, earliest)){
			earliest = temp;
		}
		if(isLater(temp, latest)){
			latest = temp;
		}
	}
	printf("%s %s\n", earliest.name, latest.name);
	return 0;
}

//牛客网上面有一个数据是这样子的：CS080718 23:54:49 00:36:07
//sign in时间与sign out时间分别在两天中，但是根据评判结果，可以得出
//对当天最后一个走的人来说，即使实验室有人也会lock实验室。
//如果这儿有限制，那么需要在输入时判断这种情况。
