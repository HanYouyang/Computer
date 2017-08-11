//2016年3月7日19时20分44秒
//2016年3月7日20时00分22秒
/*思路
输入存储阶段
	首先定义结构体类型Car存储单条记录的信息，然后定义一个Car型数组all存储所有信息，定义Car型数组valid存储有效信息
	其次，用map<string, int> parkTime记录每辆车在校园中的停留总时间，注意同一辆车可能多次进出，进入处理阶段
处理阶段：
	首先将所有记录存于all数组并对其按照车牌号id从小到大排序，车牌号相同按照时间从小到大排序
	然后遍历所有记录，寻找有效记录存入valid数组。并在得到有效记录的同时存储这辆车的总停留时间，并更新记录最长总停留时间的变量maxTime
	此时已经把所有有效记录存于valid数组，接下来把valid数组按照时间先后顺序从小到大排序，然后就可以进入查询阶段。
查询阶段：
	因为查询的时刻是顺序递增的，因此我们可以设置一个变量now指向valid数组里面的记录，使得now指向的记录的时刻不超过本次欲查询的时刻，
	同时设置一个变量nowCar记录当前校园的车辆数。则当valid[now]是"in"的时候，nowCar加1，当valid[now]是"out"的时候，numCar减1
输出停留最长时间的车辆的车牌号和对应的时间：
	只需遍历一次parkTime，输出停留时间等于maxTime的车牌号
	根据maxTime即可输出最长时间
*/
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

const int maxn = 10010;//最大记录数量

struct Car
{//存放单个记录的结构体数组
	char id[8];//车牌号
	int time;//车辆进或者出的时间
	char status[4];//车辆进或者出的状态
}all[maxn], valid[maxn];//所有记录，有效记录
map<string, int> parkTime;//车牌号与停留时间的映射

int time2int(int hh, int mm, int ss)
{//时间转换成秒
	return hh * 3600 + mm * 60 + ss;
}

bool cmpByIdAndTime(Car a, Car b)
{//根据车牌号从小到大排序，车牌号相同的根据时间从小到大排序
	if(strcmp(a.id, b.id) != 0) return strcmp(a.id, b.id) < 0;
	else return a.time < b.time;
}

bool cmpByTime(Car a, Car b)
{//根据时间从小到大排序
	return a.time < b.time;
}

int main()
{
	int n, k;//记录数，查询数
	scanf("%d%d", &n, &k);
	for(int i = 0; i < n; i++)
	{//输入所有车辆出入信息并存入all结构体数组
		int hh, mm, ss;
		scanf("%s %d:%d:%d %s", all[i].id, &hh, &mm, &ss, all[i].status);
		all[i].time = time2int(hh, mm, ss);
	}
	sort(all, all + n, cmpByIdAndTime);//按车牌号和时间排序
	int index = 0, maxTime = -1;//有效信息的下标，最久的停留时间
	for(int i = 0; i < n - 1; i++)
	{//遍历一遍获取有效信息并存入valid结构体数组
	//并且在此过程中用map记录车牌与在校园停留时间的对应值
		if(strcmp(all[i].id, all[i + 1].id) == 0){//i和i+1是同一辆车
			if(strcmp(all[i].status, "in") == 0){//i是“in”
				if(strcmp(all[i + 1].status, "out") == 0){//i+1是“out”
					valid[index++] = all[i];
					valid[index++] = all[i + 1];
					if(parkTime.count(all[i].id) == 0){
						parkTime[all[i].id] == 0;//map中还没有这个车牌号，置零
					}
					int inTime = all[i + 1].time - all[i].time;//总停留时间
					parkTime[all[i].id] += inTime;//增加该车辆的总停留时间
					if(parkTime[all[i].id] > maxTime){//更新最大总停留时间
						maxTime = parkTime[all[i].id];
					}
				}
			}
		}
	}
	sort(valid, valid + index, cmpByTime);//对valid根据时间排序
	int now = 0, numCar = 0;
	for(int i = 0; i < k; i++){
		int hh, mm, ss;
		scanf("%d:%d:%d", &hh, &mm, &ss);
		int time = time2int(hh, mm, ss);
		while(now < index && valid[now].time <= time){//让now处理至当前查询时间
			if(strcmp(valid[now].status, "in") == 0) numCar++;//in是入，nowCar + 1
			else numCar--;//out是出，nowCar - 1
			now++;
		}
		printf("%d\n", numCar);//输出该时刻校园内车辆数
	}
	map<string, int>::iterator it;
	for(it = parkTime.begin(); it != parkTime.end(); it++){
		if(it->second == maxTime){
			printf("%s ", it->first.c_str());//按照id从小到大的顺序输出所有停留时间等于总停留时间的车辆
		}//map会以键从小到达的顺序自动排序
	}
	printf("%02d:%02d:%02d\n", maxTime / 3600, maxTime % 3600 / 60, maxTime % 60);//输出最长停留时间
	return 0;
}
