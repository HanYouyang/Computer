//2016年3月12日21时20分43秒
//2016年3月12日21时38分48秒
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;
const int maxn = 10010;//最大人数
int n, row, col;//实际人数，行，列
struct Node
{
	char name[10];
	int height;
}node[maxn];//存储成员的姓名与身高

bool cmp(Node a, Node b)
{//比较
	if(a.height != b.height) return a.height < b.height;//身高不同，按照身高从矮到高排序
	else return strcmp(a.name, b.name) > 0;//身高相同，按照姓名的字典序的逆序排序
}

void print(int L, int R, int num)
{//按照格式输出下标[L, R]这段的身高信息
//根据条件，最高的人在中间(m / 2 + 1)，次高从左边靠近最高,第三高从右边靠近最高；依此类推，找规律如下代码
	int printNum = 0, index = L;
	if(num % 2 == 1) index++;//如果是偶数个从第二个开始输出
	while(index <= R){
		printf("%s ", node[index].name);
		printNum++;//记录已经输出了多少个姓名
		index += 2;//步长为2递增
	}
	if(index == R + 2) index = R - 1;//到边界R的右边返回
	else index = R;
	while(index >= L){
		printf("%s", node[index].name);
		printNum++;
		if(printNum < num) printf(" ");//如果不是最后一个，输出空格
		else printf("\n");//否则输出换行
		index -= 2;//不长为2递减
	}
}

int main()
{
	scanf("%d%d", &n, &row);
	col = n / row;//前row-1行每行的人数
	for(int i = 0; i < n; i++){
		getchar();//吸收掉上一行的换行符
		scanf("%s %d", node[i].name, &node[i].height);//输入成员姓名与高度
	}
	sort(node, node + n, cmp);//排序
	print((row - 1) * col, n - 1, col + n % row);//最后一行单独考虑
	for(int line = row - 1; line >= 1; line--){//前row-1行按照格式输出
		print((line - 1) * col, line * col - 1, col);
	}
	return 0;
}
