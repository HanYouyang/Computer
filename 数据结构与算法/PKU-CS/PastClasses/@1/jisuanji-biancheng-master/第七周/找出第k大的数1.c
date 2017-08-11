#include <iostream>
using namespace std;
template<typename T>
int partition(T array[], int low, int high)
{
    T x = array[low];
    while(low < high)
    {
        while(low < high && array[high] <= x) --high;
        array[low] = array[high];
        while(low < high && array[low] >= x) ++low;
        array[high] = array[low];
    }
    array[low] = x;
    return low;
}    
 
/*返回a中第k大的元素，复杂度为O(n)*/                
void search(int *a, int i, int j, int k)               
{
    if(i <= j)
    {
        int q = partition(a, i, j);
        /*if a[q] is the key looking for, then print it*/
        if(q-i+1 == k)
        {
            /*be careful about the index*/
            cout << a[q];
            return;
        }
        else if(q-i+1 < k)
        {
            /*look for the k-(q-i+1) th max number in [q+1, j]*/
            search(a, q+1, j, k-(q-i+1));
        }
        else
        {
            /*look for the k th max number in [i, q-1]*/
            search(a, i, q-1, k);    
        }
    }
}

int main(int argc, char const *argv[])
{
    int n, k;
    cin >> n >> k;
    int* array = new int[n];
    for (int i = 0; i < n; ++i)
    {
        cin >> array[i];
    }
    search(array, 0, n - 1, k);
    delete[] array;
    return 0;
}