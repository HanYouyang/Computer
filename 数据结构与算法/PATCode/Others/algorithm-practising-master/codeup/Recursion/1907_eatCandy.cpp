//2016年2月18日09时20分18秒
//2016年2月18日09时25分43秒
#include <cstdio>

int eatingPlan(int n)
{
	if(n == 1) return 1;
	else if(n == 2) return 2;
	else return eatingPlan(n - 1) + eatingPlan(n - 2);
}

int main()
{
	int n;
	while(scanf("%d", &n) != EOF)
		printf("%d\n", eatingPlan(n));
	return 0;
}


////2016年2月18日09时03分55秒
////2016年2月18日09时19分06秒
//#include <cstdio>
//
////maxn为20时codeup会出现答案错误
//const int maxn = 30;
//
//int main(){
//	int plan[maxn] = {0};
//	plan[1] = 1; plan[2] = 2;
//	for(int i = 3; i < maxn; i++){
//		plan[i] = plan[i - 1] + plan[i - 2];
//	}
//	int n;
//	while(~scanf("%d", &n)){
//		printf("%d\n", plan[n]);
//	}
//	return 0;
//}

