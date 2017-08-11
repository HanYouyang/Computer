//2016年3月4日18时29分22秒
//2016年3月4日18时34分12秒
/*合并果子
	在一个果园里，多多已经将所有的果子打了下来，而且按果子的不同种类分成了不同的堆。多多决定把所有的果子合成一堆。
	每一次合并，多多可以把两堆果子合并到一起，消耗的体力等于两堆果子的重量之和。可以看出，所有的果子经过n-1次合并
	之后，就只剩下一堆了。多多在合并果子时总共消耗的体力等于每次合并所耗体力之和。
	因为还要花大力气把这些果子搬回家，所以多多在合并果子时要尽可能地节省体力。假定每个果子重量都为1，并且已知果子
	的种类数和每种果子的数目，你的任务是设计出合并的次序方案，使多多耗费的体力最少，并输出这个最小的体力耗费值。
	例如
	有3种果子，数目依次为1，2，9。可以先将1、2堆合并，新堆数目为3，耗费体力为3。接着，将新堆与原先的第三堆合并，又
	得到新的堆，数目为12，耗费体力为12。所以多多总共耗费体力=3+12=15。可以证明15为最小的体力耗费值。
	输入：
	3//果子堆数
	1 3 9//每堆的重量
*/

#include <cstdio>
#include <queue>

using namespace std;

priority_queue<long long, vector<long long>, greater<long long> > q;
//代表小顶堆的优先队列

int main()
{
	int n;//果子堆数
	long long temp, x, y, ans = 0;
	//暂时记录每组输入的重量，队列中的第一个元素，队列中的第二个元素，结果存储
	scanf("%d", &n);//输入果子堆数
	for(int i = 0; i < n; i++){
		scanf("%lld", &temp);
		q.push(temp);//将每堆的重量入队
	}
	while(q.size() > 1){//队列中堆数大于1，执行合并操作
		x = q.top();
		q.pop();
		y = q.top();
		q.pop();
		ans += x + y;
		q.push(x + y);
	}
	printf("%lld\n", ans);//输出结果
	return 0;
}
//////优先队列
//基本数据类型的优先级设置（以int为例，char、double 相似）
	/*大堆顶的优先队列（元素大的排在前面）
		priority_queue<int> q;
		priority_queue<int, vector<int>, less<int> > q;//注意最后两个>之间有一个空格
	*/
	/*小堆顶的优先队列（元素小的排在前面）
		priority_queue<int, vector<int>, greater<int> > q;
	*/
//结构体的优先级设置
	/*大堆顶的优先队列
		struct fruit{
			string name;
			int price;
			friend bool operator < (fruit f1, fruit f2){
				return f1.price < f2.price;
			}
		};
		priority_queue<fruit> q;
	或者：
		struct fruit{
			string name;
			int price;
		};
		struct cmp{
			bool operator () (fruit f1, fruit f2){
				return f1.price < f2.price;
			}
		};
		priority_queue<fruit, vector<fruit>, cmp> q;
	*/
	/*小堆顶的优先队列
		只需要把return中的小于号改成大于号即可
	*/
