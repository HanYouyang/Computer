#include <stdio.h>
#include "iostream"
#include <algorithm>
using namespace std;
int N, C; //N为畜栏数，C为牛数
int location[200000];
bool check(int answer){
    int max=location[0],sum=0;
    for(int i=1;i<N;i++)
    {
        if(location[i]-max>=answer)
        {
            sum++;
            max=location[i];
        }
        if(sum >= C-1)
          {return true;}
    }
    return false;
}
int main(int argc, char const *argv[])
{
	scanf("%d%d", &N, &C);
	for (int i = 0; i < N; ++i)
	{
		scanf("%d",&location[i]);
	}
	sort(location, location + N);
	int l = 0, r = location[N - 1] - location[0];
	int mid;
	while(l <= r){
		mid = (l + r) / 2;
		if(check(mid))
			l = mid + 1;
		else
			r = mid - 1; 
	}
	cout << r;
	return 0;
}