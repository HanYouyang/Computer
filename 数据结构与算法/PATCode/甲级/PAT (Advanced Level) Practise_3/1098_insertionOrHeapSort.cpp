//2016年3月4日14时58分21秒
//2016年3月4日15时43分08秒
#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 110;//最大元素数
int n, origin[maxn], tempOri[maxn], median[maxn];
//实际元素数，原始数组，原始数组备份，目标数组

bool isSame(int A[], int B[])
{//判断数组A和数组B是否相同，相同返回true；数组元素是全局变量n，因此不需要参数传递
	for(int i = 1; i <= n; i++){
		if(A[i] != B[i]) return false;
	}
	return true;
}

bool insertSort()
{//插入排序
	bool flag = false;//记录是否存在数组中间步骤与median数组相同
	for(int i = 2; i < n; i++){//进行n-1趟排序
		if(i != 2 && isSame(tempOri, median)){
			flag = true;//中间步骤与目标相同，且不是初始序列
		}
		sort(tempOri + 1, tempOri + i + 1);//插入部分直接用sort代替
		if(flag == true){
			return true;//如果flag为true，则说明已达到目标数组，返回true
		}
	}
	return false;//无法达到目标数组，返回false
}

void downAdjust(int low, int high)
{//对tempOri数组在[low, high]范围内调整
//其中low为欲调整结点的数组下标，high一般为堆的最后一个元素的数组下标
	int i = low, j = low * 2;//i为欲调整结点，j为其左孩子
	while(j <= high){//存在左孩子结点
		if(j + 1 <= high && tempOri[j + 1] > tempOri[j])
		{//如果右孩子存在且右孩子的值大于左孩子
			j = j + 1;//让j存储右孩子下标
		}
		if(tempOri[i] < tempOri[j]){//如果孩子中最大的权值比父亲大
			swap(tempOri[i], tempOri[j]);//交换最大权值的孩子与父亲
			i = j;//令i为j
			j = i * 2;//令j为i的左孩子，进入下一层
		} else {
			break;//孩子权值均比父亲小，调整结束
		}

	}
}

void heapSort()
{//堆排序
	bool flag = false;//记录是否存在数组中间步骤与median数组相同
	for(int i = n / 2; i >= 1; i--){
		downAdjust(i, n);//建堆***************************************************
	}
	for(int i = n; i > 1; i--){
		if(i != n && isSame(tempOri, median)){
			flag = true;//中间步骤与目标相同，且不是初始序列
		}
		swap(tempOri[1], tempOri[i]);//交换heap[i]与堆顶
		downAdjust(1, i - 1);//调整堆顶
		if(flag == true){
			return;//已达到目标数组，返回true
		}
	}
}

void printArray(int A[])
{//输出数组
	for(int i = 1; i <= n; i++){
		printf("%d", A[i]);
		if(i < n){
			printf(" ");
		} else {
			printf("\n");
		}
	}
}

int main()
{
	scanf("%d", &n);//输入元素个数
	for(int i = 1; i <= n; i++){//输入起始数组
		scanf("%d", &origin[i]);
		tempOri[i] = origin[i];//tempOri数组为备份，排序在tempOri上进行
	}
	for(int i = 1; i <= n; i++){
		scanf("%d", &median[i]);//目标数组
	}
	if(insertSort()){//如果插入排序中找到目标数组
		printf("Insertion Sort\n");
		printArray(tempOri);
	} else {//到达此处一定是堆排序
		for(int i = 0; i < n; i++){	
			tempOri[i] = origin[i];//还原tempOri数组
		}
		printf("Heap Sort\n");
		heapSort();//堆排序
		printArray(tempOri);
	}
	return 0;
}
