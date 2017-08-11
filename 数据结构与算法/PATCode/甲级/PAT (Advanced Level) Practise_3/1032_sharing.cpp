//2016年2月26日18时00分46秒
//2016年2月26日18时51分32秒

#include <cstdio>

const int maxn = 100010;

struct LNode{//结构体存储链表节点
	char c;
	int next;
}node[maxn];//用下标表示链表节点的位置

int getLength(int start)
{//得到链表的长度
	int len = 0;
	for(int i = start; i != -1; i = node[i].next){
		len++;
	}
	//刚开始令len = 1且for循环写成for(int i = start; node[i].next != -1; i = node[i].next)
	//上面的写法会导致测试点3超时，因为测试点3是长度为零的情况***********************
	return len;
}

int main()
{
	int startA, startB, n;
	scanf("%d%d%d", &startA, &startB, &n);
	for(int i = 0; i < n; i++){
		int addr, next;
		char c;
		scanf("%d %c %d", &addr, &c, &next);
		node[addr].c = c;
		node[addr].next = next;
	}
	if(startA == startB){//特判，如果开始节点相同，则两个单词相同
		printf("%05d\n", startA);//输出最开始的节点位置
		return 0;
	}
	int lenA = getLength(startA);//得到链表A的长度
	int lenB = getLength(startB);//得到链表B的长度
	if(lenA == 0 || lenB == 0){
		printf("-1\n");
		return 0;
	}
	int p = startA, q = startB;//下面均用p，q遍历链表A和B
	if(lenA > lenB){//如果A的长度大于B的长度
		int a = lenA, b = lenB;
		while(a > b && node[p].next != -1){
			p = node[p].next;//A节点指针（p）向后移动
			a--;
		}
	} else if(lenA < lenB){//如果A的长度小于B的长度
		int a = lenA, b = lenB;
		while(b > a && node[p].next != -1){
			q = node[q].next;//B节点指针（q）向后移动
			b--;
		}
	}
	while(node[p].next != -1 && node[q].next != -1 && node[p].next != node[q].next){
		//当p，q都不为最后一个节点，且p节点的下一个节点地址不等于q节点的下一个节点地址时
		//p，q都向后移动
		p = node[p].next;
		q = node[q].next;
	}
	if(node[p].next != -1 && node[q].next != -1){
	//如果p，q都没到最后
		printf("%05d\n", node[p].next);
	} else {//有一个到达到最后节点
		printf("-1\n");
	}
	return 0;
}






////2016年2月26日19时05分18秒
////2016年2月26日19时18分44秒
//#include <cstdio>
//#include <cstring>
//
//const int maxn = 100010;
//
//struct LNode{
//	char c;
//	int next;
//	bool flag;
//}node[maxn];
//
//int main()
//{
//	for(int i = 0; i < maxn; i++){
//		node[i].flag = false;
//	}
//	int startA, startB, n;
//	scanf("%d%d%d", &startA, &startB, &n);
//	for(int i = 0; i < n; i++){
//		int addr, next;
//		char c;
//		scanf("%d %c %d", &addr, &c, &next);
//		node[addr].c = c;
//		node[addr].next = next;
//	}
//	for(int i = startA; i != -1; i = node[i].next){
//		node[i].flag = true;
//	}
//	int p = startB;
//	for(p = startB; p != -1; p = node[p].next){
//		if(node[p].flag == true) break;
//	}
//	if(p != -1){
//		printf("%05d\n", p);
//	} else {
//		printf("-1\n");
//	}
//	return 0;
//}






