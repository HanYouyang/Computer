1.冒泡排序
思想:每一次排序都找到一个当前未排序序列中的最大值到当前未排序序列的末尾
void BubbleSort(int a[], int n)//假设序列是a[1] - a[n]
{
	for(int i = 0; i < n; i++)
	{
		for(int j = 2; j <= n - i; j++)
		{
			if(a[j] < a[j - 1])
				swap(a[j], a[j - 1]);
		}
		PrintLine(a, n);
	}
}

2.选择排序
思想：每次从未排序序列中选择出一个最小值跟未排序序列中的第一个元素交换
void SelectSort(int a[], int n)
{
	for(int i = 1; i < n; i++)
	{
		int k = i;
		for(int j = i; j <= n; j++)
		{
			if(a[k] > a[j])
				k = j;
		}
		swap(a[i], a[k]);
	}
}

3.插入排序
思想：每次排序将未排序序列中的第一个元素插入到前面已排序序列的适当位置
void InsertSort(int a[], int n)
{
	for(int i = 2; i <= n; i++)//枚举a[2] - a[n] 中的所有元素
	{
		int x = a[i];
		for(int j = i - 1; j >= 1; j--)
		{
			if(a[j] > x)
				a[j+1] = a[j];
			else
				break;
		}
		a[j + 1] = x;
	}
}

4.归并排序
void MergeSort(int a[], int n)
{
	for(int step = 2; step / 2 <= n; step *= 2)//这里需要仔细看看
	{
		for(int i = 1; i <= n; i+=step)
			sort(a+i, a+min(i+step, n+1));
	}
}