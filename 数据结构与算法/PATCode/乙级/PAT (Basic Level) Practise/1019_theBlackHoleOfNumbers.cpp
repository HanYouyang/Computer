//2016年2月20日20时40分16秒
//2016年2月20日21时17分07秒

//思路：通过getTwoNum得到元素从大到小的数upNum和元素从小到大的数downNum
//在差不等于0和不等于6174时循环
#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;
int mark[11] = {0};

void getTwoNum(int num, int & upNum, int & downNum)
{
	while(num){
		mark[num % 10]++;
		num /= 10;
	}
	for(int i = 9; i >= 0; i--){
		int temp = mark[i];
		while(temp--) upNum = upNum * 10 + i;
	}
	//当number小于四位数时，upNum要通过下面的操作处理成四位数
	while(upNum < 1000) upNum *= 10;
	for(int i = 0; i <= 9; i++){
		int temp = mark[i];
		while(temp--) downNum = downNum * 10 + i;
	}
}

int main()
{
	int number,upNum, downNum;
	scanf("%d", &number);
	do{
		upNum = 0; downNum = 0;
		memset(mark, 0, sizeof(int) * 11);
		getTwoNum(number, upNum, downNum);
		number = upNum - downNum;
		printf("%04d - %04d = %04d\n", upNum, downNum, number);
	}while(number != 6174 && number != 0);
	return 0;

