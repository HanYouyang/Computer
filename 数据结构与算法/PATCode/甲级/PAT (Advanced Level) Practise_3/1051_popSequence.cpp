//2016年2月25日21时08分31秒
//2016年2月26日10时00分07秒
#include <iostream>
#include <stack>
#include <algorithm>
#include <cstdio>

using namespace std;
const int maxn = 1010;

int main()
{
	int m, n, k;//栈的容量，出栈序列的长度，待检测序列的个数
	scanf("%d%d%d", &m, &n, &k);
	for(int i = 0; i < k; i++){
		stack<int> st;//初始化栈
		int seq[maxn];//存储出栈序列
		for(int j = 0; j < n; j++){
		//输入出栈序列
			scanf("%d", &seq[j]);
		}
		int index = 0;//当前待出栈元素的下标
		int flag = true;//超出栈容量时为false
		for(int j = 1; j <= n; j++){
			st.push(j);//入栈
			if(st.size() > m){//超出了栈的容量
				flag = false;
				break;//直接退出
			}
			while(!st.empty() && st.top() == seq[index]){
			//反复判断当前index所指的出栈序列的元素（待出栈元素）是否等于栈顶元素
			//是的话栈顶元素出栈并且index自增以指向下一个待出栈的元素
			//使用st.top()与st.pop()之前必须先判空*****************************************************
				st.pop();
				index++;
			}
		}
		if(st.empty() && flag == true){
		//操作结束了，如果栈空且flag = true 输出YES
			printf("YES\n");
		} else {//否则输出NO
			printf("NO\n");
		}
	}
	return 0;
}
