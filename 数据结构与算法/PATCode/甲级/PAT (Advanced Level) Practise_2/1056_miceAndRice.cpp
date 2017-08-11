//2016年2月26日10时30分56秒
//2016年2月26日12时02分57秒
#include <cstdio>
#include <queue>

using namespace std;

const int maxn = 1010;

struct Mouse{
//用结构体保存老鼠的重量和最后的排名
//这样可以很好的解决最后按照原始输入的顺序输出
	int weight;//重量
	int rank;//排名
}mou[maxn];

int main()
{
	int np, ng, order;//程序员总数，每个组的最大人数，顺序
	queue<int> q;//定义一个队列q
	scanf("%d%d", &np, &ng);
	for(int i = 0; i < np; i++){//输入老鼠的重量
		scanf("%d", &mou[i].weight);
	}
	for(int i = 0; i < np; i++){//输入顺序
		scanf("%d", &order);
		q.push(order);//将顺序入队
	}
	int total = np, group;//当前总老鼠数，组数
	while(q.size() != 1){//队列中元素的个数大于1
		if(total % ng == 0) group = total / ng;//刚好能够把老鼠完整划分
		else group = total / ng + 1;//最后有一组少于NG只老鼠单独分组
		for(int i = 0; i < group; i++){//遍历组
			int maxWeiOrder = q.front();//最大重量老鼠的顺序
			for(int j = 0; j < ng; j++){//遍历组内老鼠
				if(i * ng + j >= total) break;//如果超出当前组内总老鼠数，退出
				int front = q.front();//获取队首元素
				if(mou[front].weight > mou[maxWeiOrder].weight){
				//将队首老鼠的重量与当前最大重量的老鼠重量进行比较
				//队首老鼠的重量大则更新
					maxWeiOrder = front;
				}
				mou[front].rank = group + 1;//对失败的老鼠排名
				q.pop();//弹出队首元素
			}
			q.push(maxWeiOrder);//将胜利的老鼠顺序入队
		}
		total = group;//更新当前组总老鼠数
	}
	mou[q.front()].rank = 1;//队列中仅有一个元素时，令其排名为1
	for(int i = 0; i < np; i++){//按照原始顺序输出老鼠信息
		if(i) printf(" ");
		printf("%d", mou[i].rank);
	}
	return 0;
}
