//2016年2月26日14时42分49秒
//2016年2月26日16时33分00秒
#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 100010;//节点的最大长度

struct LNode{//用结构体存储链表信息
	int data;//节点值
	int next;//下一个节点地址
}node[maxn];//并用下表表示该元素的地址

int address[maxn] = {0};//按照链表顺序存储每个元素的地址

void print(int index, int n){//输出
	for(int i = 0; i < n - 1; i++){
		printf("%05d %d %05d\n", index, node[index].data, node[index].next);
		index = node[index].next;
	}
	printf("%05d %d %d\n", index, node[index].data, node[index].next);
	//将-1的输出与其他地址的输出分开
	return;
}

int main()
{
	int start, newStart, n, k;
	//起始地址，新的起始地址，节点数目，子链表的长度
	scanf("%d%d%d", &start, &n, &k);
	for(int i = 0; i < n; i++){
		int addr;//当前节点的地址，直接用下标表示
		scanf("%d", &addr);
		scanf("%d%d", &node[addr].data, &node[addr].next);
	}
	int index = start;//节点地址（也即下标）
	for(int i = 0; i < n; i++){//将链表元素的地址按照链表顺序存放在数组address中
		address[i] = index;
		if(node[index].next != -1){//下一节点不为空时
			index = node[index].next;
		} else {//下一节点为空，则去掉这些节点，不予输出
			n = i + 1;
			break;
		}
	}
	if(n < k){//如果去除无效节点之后长度小于字链表的长度k，直接输出原链表
		newStart = start;//新的其实节点不变，链表也不变
	} else {//子链表长度不大于有效链表总长度
		newStart = address[k - 1];//新的起始地址
		int group = n / k;//逆转的组数
		int temp = start;//每组的最后一个地址
		for(int i = 0; i < group; i++){
			if((i + 1) * k > n) break;//如果最后一组节点数小于k 不逆转
			if(i) node[address[temp]].next = address[(i + 1) * k - 1];
			//每组逆转后的最后一个元素的下一个指针指向下一组第一个元素
			for(int j = (i + 1) * k - 1; j > i * k; j--){
				node[address[j]].next = address[j - 1];
			}
			temp = i * k;
		}
		if(n % k != 0){//如果最后一组小于k
			node[address[temp]].next = address[n - n % k];
			//上一组最后一个元素的下地址赋值为最后一族的第一个元素
		} else {//最后一组刚好等于k
			node[address[temp]].next = -1;//逆转后最后一组的最后一个节点的下地址设置为-1
		}
	}
	print(newStart, n);//输出
	return 0;
}
