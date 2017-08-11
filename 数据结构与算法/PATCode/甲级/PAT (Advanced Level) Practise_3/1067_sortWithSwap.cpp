#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 100010;
int pos[maxn];

int main()
{
	int n, ans = 0;
	scanf("%d", &n);
	int left = n - 1, num;
	for(int i = 0; i < n; i++){
		scanf("%d", &num);
		pos[num] = i;
		//除0以外有在本位上的数
		if(num == i && num != 0){
			left--;
		}
	}
	int k = 1;
	while(left > 0){
		if(pos[0] == 0){
			while(k < n){
				if(pos[k] != k) {
					swap(pos[0], pos[k]);
					ans++;
					break;
				}
				k++;
			}
		}
		while(pos[0] != 0) {
			swap(pos[0], pos[pos[0]]);
			ans++;
			left--;
		}
	}
	printf("%d", ans);
	return 0;
}

////测试点1，2运行超时
////2016年2月18日20时23分59秒
////2016年2月18日21时58分27秒
//#include <cstdio>
//#include <algorithm>
//
//using namespace std;
//
//const int maxn = 100010;
//int num[maxn];
//
//int findx(int n, int x){
//	for(int i = 0; i < n; i++){
//		if(num[i] == x) return i;
//	}
//}
//
//int main()
//{
//	int n, times = 0;
//	int left = 0;//不在最终位置的元素个数
//	scanf("%d", &n);
//	for(int i = 0; i < n; i++){
//		scanf("%d", &num[i]);
//		if(num[i] != i) left++;
//	}
//	while(left){
//		int pos0 = findx(n, 0);
//		//如果0的位置在0上
//		if(pos0 == 0){
//			int i;
//			for(i = 1; i < n; i++){
//				if(num[i] != i){
//					swap(num[0], num[i]);
//					pos0 = i;
//					times++;
//					left++;
//					break;
//				}
//			}
//			if(i == n) break;
//		}
//		int posi = findx(n, pos0);
//		swap(num[pos0], num[posi]);
//		times++;
//		left--;
//	}
//	printf("%d\n", times);
//	return 0;
//}


////题目理解错误
////2016年2月18日20时23分59秒
////2016年2月18日
//#include <cstdio>
//#include <algorithm>
//
//using namespace std;
//
//const int maxn = 100010;
//int num[maxn];
//bool isOrdered[maxn] = {false};
//int myCount = 0;
//
//int main()
//{
//	int n, min = 0;
//	scanf("%d", &n);
//	for(int i = 0; i < n; i++){
//		scanf("%d", &num[i]);
//		if(i == num[i]){
//			isOrdered[i] = true;
//			myCount++;
//		}
//	}
//	for(int i = 0; i < n; i++){
//		if(isOrdered[i]) continue;
//		int a = i, b = num[i];
//		if(a == num[b]){
//			num[a] = a; isOrdered[a] = true; myCount++;
//			num[b] = b; isOrdered[b] = true; myCount++;
//			min++;
//		}
//	}
//	while(myCount < n){
//		int newCount = 0;
//		for(int i = 0; i < n; i++){
//			if(isOrdered[i]) continue;
//			int a = i, b = num[i], c = num[b];
//			if(a == num[c]){
//				num[a] = a; isOrdered[a] = true; newCount++;
//				num[b] = b; isOrdered[b] = true; newCount++;
//				num[c] = c; isOrdered[c] = true; newCount++;
//				min += 2;
//			}
//		}
//		if(newCount == 0){
//			for(int i = 0; i < n; i++){
//				if(isOrdered[i]) continue;
//				int a = i, b = num[i];
//				num[a] = num[b];
//				num[b] = b; isOrdered[b] = true; newCount++;
//				min++;
//			}
//		}
//		myCount += newCount;
//	}
//	printf("%d\n", min);
//	return 0;
//}
