//2016年2月18日14时44分15秒
//2016年2月18日15时05分04秒
#include <cstdio>

int main()
{
	int count[10] = {0};
	bool flag = false;//flag标记是否还有0没输出
	for(int i = 0; i < 10; i++) scanf("%d", &count[i]);
	for(int i = 1; i < 10; i++){
		if(flag && count[i]){//0已经全部输出，此时可以按照从小到达的顺序输出数组的下表
			while(count[i]--) printf("%d", i);
		}
		else if(count[i]){//还没有处理0，要输出一个元素后再处理0，然后再输出当前下表的余下元素
			printf("%d", i); count[i]--;
			while(count[0]){ printf("0"); count[0]--; }
			flag = true;
			while(count[i]){ printf("%d", i); count[i]--;}
		}
	}
	return 0;
}
