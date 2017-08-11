//2016年1月29日13时32分54秒
//2016年1月29日14时40分34秒
#include <iostream>

using namespace std;

int main()
{
	int T;
	cin >> T;
	for(int i = 1; i <= T; ++i){
		long double a, b, c, ans;
		cin >> a >> b >> c;
		cout << "Case #" << i << ": " << (a+b>c ? "true" : "false") << endl;
	}
	return 0;
}
//#include <iostream>
//#include <cstdio>
//
//using namespace std;
//
//int main(){
//	int T = 0;
//	long long A, B, C;
//	int count = 1;
//	cin >> T;
//	while(T--){
//		cin >> A >> B >> C;
//		long long sum = A + B;
//		if(A > 0 && B > 0 && sum < 0){
//			//cout << A + B << endl;
//			//cout << sizeof(A + B) << endl;
//			//cout << sizeof(long double) << endl;
//			printf("Case #%d: true\n", count++);
//			continue;
//		}
//		else if(A < 0 && B < 0 && sum >= 0){
//			printf("Case #%d: false\n", count++);
//			continue;
//		}
//		else if(sum > C)
//			printf("Case #%d: true\n", count++);
//		else
//			printf("Case #%d: false\n", count++);
//	}
//	return 0;
//}
