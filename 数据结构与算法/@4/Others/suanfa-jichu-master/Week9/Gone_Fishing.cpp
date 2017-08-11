#include "iostream"
#include <memory.h>
using namespace std;
//所有时间都以5分钟为单位
int n, h;//n为lake数，h为hour数
int f[25], d[25]; //f为初始数，d为衰减数
int t[25];//t为路程时间
int current_f[25];
int stay_time[25], best_stay_time[25];
int result,best_result;
int remain_time;

int main(int argc, char const *argv[])
{
	while(cin >> n && n != 0){
		cin >> h;
		h = h * 12;	
		best_result = -1;
		for (int i = 0; i < n; ++i)
			cin >> f[i];
		for (int i = 0; i < n; ++i)
			cin >> d[i];
		for (int i = 0; i < n - 1; ++i)
			cin >> t[i];
		//开始枚举
		for (int last_lake = 0; last_lake < n; ++last_lake)
		{
			memset(stay_time, 0, sizeof(stay_time));
			result = 0;
			remain_time = h; //钓鱼的时间
			int max_amount, lake_index;
			for (int i = 0; i < n; ++i)
			{
				current_f[i] = f[i]; //重置
			}
			
			while(remain_time > 0){  //贪心钓鱼
				max_amount = current_f[0];
				lake_index = 0;
				for (int i = 1; i <= last_lake; ++i)
				{
					if (current_f[i] > max_amount)
					{
						max_amount = current_f[i];
						lake_index = i;
					}
				}
				if (max_amount == 0)
				{
					stay_time[0] += remain_time;
					break;
				}else{
					stay_time[lake_index]++;
					result += current_f[lake_index];
					current_f[lake_index] -= d[lake_index];
					if (current_f[lake_index] < 0)
					{
						current_f[lake_index] = 0;
					}
				}
				remain_time--;
			}
			if(last_lake != n - 1)
				h -= t[last_lake];
			if (result > best_result)
			{
				best_result = result;
				for (int i = 0; i < n; ++i)
				{
					best_stay_time[i] = stay_time[i];
				}
			}
		}
        for(int i = 0;i < n;i++)  
        {  
        	cout << best_stay_time[i] * 5;
        	if (i != n-1)
        	{
        		cout << ", ";
        	}
        }  
        cout << endl;  
        cout << "Number of fish expected: "<< best_result <<endl;  
        cout << endl; 

	}
	return 0;
}