//2016年2月27日14时05分06秒
//2016年2月27日14时35分47秒
/*问题：
	有n件物品，每件物品的重量为w[i]，价值为c[i]。现在需要选出若干件物品放入一个
	容量为V的背包中，使得在选入背包的物品重量和不超过容量V的前提下，让背包中物品
	的价值之和最大，求最大价值。(1 <= n <= 20)
	输入格式：
	5 8//5件物品，背包容量为8
	3 5 1 2 2//5件物品的重量分别为3 5 1 2 2
	4 5 2 1 3//5件物品的价格分别为4 5 2 1 3
*/
#include <cstdio>

const int maxn = 30;

int n, V, maxValue = 0;//物品件数n，背包容量V，最大价值maxValue
int w[maxn], c[maxn];//每件物品的重量w[]，每件物品的价格c[]

//递归+剪枝//没使用剪枝方法的DFS在下面
void DFS(int index, int sumW, int sumC){
	if(index == n) return;
	DFS(index + 1, sumW, sumC);
	if(sumW + w[index] <= V){
		if(sumC + c[index] > maxValue){
			maxValue = sumC + c[index];
		}
		DFS(index + 1, sumW + w[index], sumC + c[index]);
	}
}

int main()
{
	scanf("%d%d", &n, &V);//输入物品件数，背包容量
	for(int i = 0; i < n; i++){
		scanf("%d", &w[i]);//输入每件物品的重量
	}
	for(int i = 0; i < n; i++){
		scanf("%d", &c[i]);//输入每件物品的价格
	}
	DFS(0, 0, 0);//初始是为第0件物品，当前总重量和总价值均为0
	printf("%d\n", maxValue);//输入最大价值
	return 0;
}


////没使用剪枝方法的DFS
//void DFS(int index, int sumW, int sumC){
////index是当前处理的物品编号
////sumW和sumC分别为当前总重量和当前总价格
//	if(index == n){//已经完成对n件物品的选择（死胡同）
//		if(sumW <= V && sumC > maxValue){
//			maxValue = sumC;//不超过背包容量时更新更大价值maxValue
//		}
//		return;
//	}
//	DFS(index + 1, sumW, sumC);//不选第index件物品
//	DFS(index + 1, sumW + w[index], sumC + c[index]);//选第index件物品
//}
