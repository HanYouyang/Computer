//2016年2月18日17时37分24秒
//2016年2月18日19时35分33秒
#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 510;//Max number of gas station

struct Station{
	double price;
	double dis;
}sta[maxn];

bool cmp(Station a, Station b)
{
	return a.dis < b.dis;
}

int main()
{
	double c, d, davg;
	int n;
	double sum = 0.0;//总费用
	scanf("%lf%lf%lf%d", &c, &d, &davg, &n);
	double maxDrive = c * davg;
	for(int i = 0; i < n; i++){
		scanf("%lf%lf", &sta[i].price, &sta[i].dis);
	}
	sta[n].price = 0.0; sta[n].dis = d;
	sort(sta, sta + n, cmp);
	if(sta[0].dis != 0.0) {
		printf("The maximum travel distance = 0.00");
		return 0;
	}
	//当前车在i站，满油状态能达到最远的站为farthest
	int next = 0;//下一站
	int mins;//下一站与最远站之间油价最低的站点
	double currentOil = 0.0;
	for(int i = 0; i <= n; i = next){
		int farthest = i;
		//如果到达了终点（n站台），输出总费用
		if(i == n) {
			printf("%.2f", sum);
			return 0;
		}
		//求最远到达的站点farthest
		while(farthest < n && ((sta[farthest + 1].dis - sta[i].dis) <= maxDrive)) farthest++;
		//如果满油状态都无法到达下一站，则退出
		if(farthest == i) {
			printf("The maximum travel distance = %.2f", sta[i].dis + maxDrive); 
			return 0;
		}
		//前往更低油价的加油站
		bool flag = false;
		for(mins = i + 1; mins <= farthest; mins++){
			if(sta[mins].price < sta[i].price) {
				flag = true;
				break;
			}
		}
		if(flag){
			double needFuel = (sta[mins].dis - sta[i].dis) / davg;
			if(needFuel >= currentOil){
				sum += sta[i].price * (needFuel - currentOil);
				currentOil = 0.0;
			}
			else currentOil = currentOil - needFuel;
			next = mins;
			continue;
		}
		//没有比当前油价更低的加油站，则找到一个尽量低的站点
		mins = i + 1;
		for(int k = i + 1; k <= farthest; k++){
			if(sta[k].price >= sta[mins].price) mins = k;
		}
		double fuel = c - currentOil;
		sum += sta[i].price * fuel;
		currentOil = c - (sta[mins].dis - sta[i].dis) / davg;
		next = mins;
		continue;
	}
	return 0;
}
