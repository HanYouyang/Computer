//2016年3月12日19时38分38秒
//2016年3月12日21时17分45秒
//测试点2断错误，3答案错误
#include <cstdio>
#include <cstring>
#include <cmath>

const int maxn = 110;//最多110个数
int n, valid = 0;//实际数据量，有效数据量
double sum = 0.0;//有效数据量的和

bool judge(char str[])
{//判断是否是有效数据（此函数没有考虑[-1000,100]的范围）
//考虑的因素有：
	//第一个元素不是'-'且不是字符'0'-'9'
	//小数点的数量 > 1 无效
	//小数点后精度位数 > 2 无效
	int index = 0, pointNum = 0, afterPointNum = -1;//字符串下标，小数点的数量，小数点后数字的数量
	int length = strlen(str);//数的长度
	if(length == 0) return false;//如果长度是0，返回false
	if(index < length && str[index] == '-') index++;//如果第一个是负号，下标+1
	if(index < length && str[index] < '0' || str[index] > '9') return false;//如果第一个数字不是0-9 返回false
	index++;//下表+1
	while(index < length){//当下标小于数长度时循环
		if(str[index] == '.'){//如果是小数点
			pointNum++;//小数点的数量+1
			if(pointNum > 1) return false;//如果小数点数量大于1，返回false
			if(afterPointNum == -1) afterPointNum = 0;//将记录小数点后位数的变量唤醒
		} else if(str[index] < '0' && str[index] > '9') {//如果既不是小数点也不是0-9，返回false
			return false;
		}
		if(afterPointNum >= 0){//如果记录小数点后位数的变量已经被唤醒
			afterPointNum++;//精度+1
			if(afterPointNum > 3) return false;//如果小数点位数大于3，返回false
		}
		index++;//下标加1
	}
	return true;//如果能过的了上面的关卡，然会true
}

double str2double(char str[])
{
	double temp = 0.0;//存储转换成的double型
	bool flag = false;//是否是负数
	int index = 0, length = strlen(str);
	if(str[index] == '-'){//是负数
		index++;//下标右移
		flag = true;//置flag为true
	}
	while(index < length && str[index] != '.'){//整数部分的处理
		temp = temp * 10 + str[index++] - '0';
	}
	index++;//略过小数点
	int decimal = 1;//小数位数，初始为1
	while(index < length){
		temp += (str[index] - '0') / pow(10.0, 1.0 * decimal);
		index++; decimal++;
	}
	if(flag == true) temp = -temp;//如果是负数，取反
	return temp;
}

int main()
{
	scanf("%d", &n);
	getchar();//吸收换行符
	for(int i = 0; i < n; i++){
		char str[10];
		scanf("%s", str);
		if(judge(str) == false){//如果判断不合法
			printf("ERROR: %s is not a legal number\n", str);
		} else {
			double tempNum = str2double(str);
			if(tempNum < -1000 || tempNum >= 1000){//大于数据的返回[-1000, 1000]
				printf("ERROR: %s is not a legal number\n", str);
			} else {
				sum += tempNum;//求有效数据的和
				valid++;//有效数据的位数
			}
		}
	}
	if(valid == 0){//如果有效数据个数为0
		printf("The average of 0 numbers is Undefined\n");
	} else if(valid == 1){
		printf("The average of %d number is %.2f\n", valid, sum / valid);
	} else {//如果有效数据个数大于0
		printf("The average of %d numbers is %.2f\n", valid, sum / valid);
	}
	return 0;
}
