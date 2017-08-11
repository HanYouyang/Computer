//排序算法
//Miibotree 
//2015.2.24

//1.直接插入排序
void InsertSort(int a[], int n)//递增排序
{
	int i, j;
	for(i = 2; i <= n; i++)//依次将a[2]-a[n]插入到前面已排序序列
	{
		if(a[i] < a[i-1])//需要把a[i]插入到前面的某个位置
		{
			a[0] = a[i];
			for(j = i - 1; a[0] < a[j]; j--)
				a[j+1] = a[j];
			a[j+1] = a[0];
		}
	}
}

//2.二路归并排序
//b为辅助数组
void Merge(int a[], int low, int mid, int high)
{
	int i, j, k;
	for(int k = low; k <= high; k++)
		b[k] = a[k];
	for(i = low, j = mid + 1, k = i; i <= mid && j <= high; k++)
	{
		if(b[i] <= b[j])//小者复制到a数组中
			a[k] = b[i++];
		else
			a[k] = b[j++];
	}
	while(i <= mid)	a[k++] = b[i++];
	while(j <= high) a[k++] = b[j++];
}

void MergeSort(int a[], int low, int high)
{
	if(low < high)
	{
		int mid = (low + high) / 2;
		MergeSort(a, low, mid);
		MergeSort(a, mid+1, high);
		Merge(a, low, mid, high);
	}
}