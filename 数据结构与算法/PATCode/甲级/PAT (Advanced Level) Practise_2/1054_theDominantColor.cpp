//2016年2月25日14时12分34秒
//2016年2月25日14时32分50秒

//本题如果使用hash的话需要2^24个int型数组，这样可能会内存超限
//因此使用map<int, int>
#include <cstdio>
#include <algorithm>
#include <map>

using namespace std;
map<int, int> mp;

int main()
{
	int m, n;//列，行
	scanf("%d%d", &m, &n);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			int temp;//像素值
			scanf("%d", &temp);
			if(mp.find(temp) == mp.end()){
			//如果map中没有对应的键，添加并把值置为1
				mp[temp] = 1;
			} else {//已经有了，则将值加1
				mp[temp]++;
			}
		}
	}
	int domiKey, maxNum = 0;//Dominant color， 最大的颜色数
	for(map<int, int>::iterator it = mp.begin(); it != mp.end(); it++){
	//遍历map，找到最多的颜色
	//既可以通过下标访问，又可以通过迭代器访问
		if(it->second > maxNum){//如果颜色数大于当前颜色的数目
			domiKey = it->first;//更新当前最大颜色
			maxNum = it->second;//更新当前最大颜色的数目
		}
	}
	printf("%d\n", domiKey);//输出
	return 0;
}
