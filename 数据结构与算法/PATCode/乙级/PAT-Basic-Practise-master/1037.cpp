#include <iostream>
using namespace std;
int main()
{
	int pg, ps, pk, ag, as, ak;
	scanf("%d.%d.%d %d.%d.%d", &pg, &ps, &pk, &ag, &as, &ak);
	//1g = 17s  1s = 29k
	int a, b, c;
	bool flag;
	if(pg > ag || (pg == ag && ps > as) || (pg == ag && ps == as && pk > ak)){
		flag = false;
		cout << "-";
	} else {
		flag = true;
	}
	if(flag){
		if(ak >= pk){
			c = ak - pk;
		} else {
			c = ak + 29 - pk;
			as--;
		}
		if(as >= ps){
			b = as - ps;
		} else {
			b = as + 17 - ps;
			ag--;
		}
		a = ag - pg;
	} else {
		if(pk >= ak){
			c = pk - ak;
		} else {
			c = pk + 29 - ak;
			ps--;
		}
		if(ps >= as){
			b = ps - as;
		} else {
			b = ps + 17 - as;
			pg--;
		}
		a = pg - ag;
	}
	cout << a << "." << b << "." << c << endl;
	return 0;
}
