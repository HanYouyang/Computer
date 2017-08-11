//2016年2月26日19时48分16秒
//2016年2月26日20时10分43秒
#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 100010;

struct LNode{
	int data;
	int next;
}node[maxn];//节点的地址就是下表

bool cmp(int a, int b)
{//间接比较，将所有节点的地址存放在数组中，根据地址中存的数据从小到达对地址进行排序
	return node[a].data < node[b].data;
}

int main()
{
	int n, head, address[maxn];
	scanf("%d%d", &n, &head);
	for(int i = 0; i < n; i++){
		int addr, data, next;
		scanf("%d%d%d", &addr, &data, &next);
		node[addr].data = data;
		node[addr].next = next;
	}
	int temp = head;//用temp来代替头结点
	for(int i = 0; i < n; i++){
		if(temp == -1){//忽略无效的节点
			n = i;
			break;
		}
		address[i] = temp;//将有效节点地址都保存在数组address中
		temp = node[temp].next;
	}
	if(n > 0){//如果有有效节点
		sort(address, address + n, cmp);//对有效节点进行排序
		printf("%d %05d\n", n, address[0]);
		for(int i = 0; i < n - 1; i++){
			printf("%05d %d %05d\n", address[i], node[address[i]].data, address[i + 1]);
		}
		printf("%05d %d -1\n", address[n - 1], node[address[n - 1]].data);
	} else {//没有一个有效节点，输出0 -1
		printf("0 -1\n");
	}
	return 0;
}
