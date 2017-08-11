#include <iostream>
using namespace std;
int N = 0; //数组总长度

int partition(int array[], int i, int j) 
{
    //左小右大排列，求第i个数在第几位
    int pivot = array[i];
    while (i < j)
    {
        while (i < j && array[j] >= pivot)  //因为循环里面i和j在变动，所以循环之前也要判断j是否小于j
            j--;
        array[i] = array[j];
        while (i < j && array[i] <= pivot)
            i++;
        array[j] = array[i];
    }
    array[j] = pivot;
    return i;
}

void search(int *array, int i, int j, int k)
{
    if (i <= j)
    {
        int q = partition(array, i, j);
        if (j - q + 1 == k)
        {
            cout << "The " << N - q << "th max number is: " << array[q] << endl;
            // cout << array[q];
            return;
        }
        else if (j - q + 1 > k)
            //右边
            search(array, q + 1, j, k);
        else
            //左边
            search(array, i, q - 1, k - (j - q + 1));
    }
}


int main(int argc, char const *argv[])
{
    int n, k;
    cin >> n >> k;
    N = n;
    int* array = new int[n];
    for (int i = 0; i < n; ++i)
    {
        cin >> array[i];
    }
    search(array, 0, n - 1, k);
    delete[] array;
    return 0;
}