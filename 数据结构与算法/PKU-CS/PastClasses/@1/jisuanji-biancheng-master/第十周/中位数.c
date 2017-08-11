#include <iostream>
#include <stdlib.h>
using namespace std;
int N = 0; //数组总长度

int partition(int array[], int i, int j)
{
    //左小右大排列
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

int search(int *array, int i, int j, int k)
{
    if (i <= j)
    {
        int q = partition(array, i, j);
        if (j - q + 1 == k)
        {
            return array[q];
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
    int size, number;
    while(true)
    {
        cin >> size;
        if (size != 0)
        {
            int *array = (int *) malloc(size * sizeof(int));
            for (int i = 0; i < size; ++i)
            {
                cin >> array[i];
            }
            if(size % 2 == 0) {
                cout << (search(array, 0, size - 1, size/2) + search(array, 0, size - 1, size/2 + 1)) / 2 << endl;
                // cout << "-----------" << (search(array, 0, size - 1, size/2) + search(array, 0, size - 1, size/2 + 1)) / 2 << "-----------" << endl;
            }
            else{
                cout << search(array, 0, size - 1, (size + 1) / 2) << endl;
                // cout << "-----------" << search(array, 0, size - 1, (size + 1) / 2) << "-----------" << endl;
            }
            free(array);
        }
        else
            return 0;
    }
}