//2016年2月26日21时37分58秒
//2016年2月26日21时54分13秒
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 100010;
const int TABLE = 1000010;

struct LNode {//定义静态链表
	int address, data, next;
	int order;//节点在链表上的序号，无效节点记为2 * maxn
} node[maxn];

bool isExist[TABLE] = {false};//节点是否已经存在
bool cmp(LNode a, LNode b){//按照order从小到大进行排序
	return a.order < b.order;
}

int main()
{
	memset(isExist, false, sizeof(isExist));//初始化isExist未存在
	for(int i = 0; i < maxn; i++){//初始化
		node[i].order = 2 * maxn;//初始时均为无效节点
	}
	int n, begin, address;//节点总数，起始地址，地址
	scanf("%d%d", &begin, &n);
	for(int i = 0; i < n; i++){
		scanf("%d", &address);
		scanf("%d%d", &node[address].data, &node[address].next);
		node[address].address = address;
	}
	int countValid = 0, countRemoved = 0, p = begin;
	//未删除的有效节点的个数，已删除的有效节点的个数
	while(p != -1){//枚举链表
		if(!isExist[abs(node[p].data)]){//如果节点data的绝对值未存在
			isExist[abs(node[p].data)] = true;//标记为已存在
			node[p].order = countValid++;//不删除，order从零开始
		} else {//节点data的绝对值已经存在
			node[p].order = maxn + countRemoved++;//被删除，order从maxn开始
		}
		p = node[p].next;//下一个节点
	}
	sort(node, node + maxn, cmp);//按order从小到大排序
	int count = countValid + countRemoved;//有效节点总数
	for(int i = 0; i < count; i++){//输出有效节点
		if(i != countValid - 1 && i != count - 1){//非最后一个节点
			printf("%05d %d %05d\n", node[i].address, node[i].data, node[i+1].address);
		} else {//最后一个节点单独处理
			printf("%05d %d -1\n", node[i].address, node[i].data);
		}
	}
	return 0;
}

////2016年2月26日20时19分41秒
////2016年2月26日21时30分03秒
////只得了15分的思路：用结构体LNode存储链表 用address[]数组存储链表的位置
////对于没有重复的节点不做任何操作，对于重复的链表，将上一个节点的next指向重复的下一个节点
////并且将重复节点的位置记录在removeAddr[]数组中
////最后输出不重复和重复的节点
//#include <cstdio>
//#include <cstdlib>
//#include <cstring>
//
//const int maxn = 100010;
//bool flag[maxn] = {false};
//
//struct LNode{
//	int data;
//	int next;
//}node[maxn];
//
//int main()
//{
//	int head, n, address[maxn];
//	memset(address, -1, sizeof(address));
//	scanf("%d%d", &head, &n);
//	for(int i = 0; i < n; i++){
//		int addr, data, next;
//		scanf("%d%d%d", &addr, &data, &next);
//		node[addr].data = data;
//		node[addr].next = next;
//	}
//	int p = head;
//	for(int i = 0; i < n; i++){
//		if(p == -1){
//			n = i;
//			break;
//		}
//		address[i] = p;
//		p = node[p].next;
//	}
//	int removeAddr[maxn], j = 0;
//	memset(removeAddr, -1, sizeof(removeAddr));
//	if(n > 0){
//		for(int i = 0; i < n; i++){
//			int key = abs(node[address[i]].data);
//			if(flag[key] == false){
//				flag[key] = true;
//			} else {
//				node[address[i - 1]].next = address[i + 1];
//				removeAddr[j++] = address[i];
//			}
//		}
//		int q = head;
//		for(q = head; node[q].next != -1; q = node[q].next){
//			printf("%05d %d %05d\n", q, node[q].data, node[q].next);
//		}
//		printf("%05d %d -1\n", q, node[q].data);
//		for(q = 0; q < j - 1; q++){
//			printf("%05d %d %05d\n", removeAddr[q], node[removeAddr[q]].data, removeAddr[q + 1]);
//		}
//		if(j) printf("%05d %d %d\n", removeAddr[q], node[removeAddr[q]].data, removeAddr[q + 1]);
//	}
//	return 0;
//}
