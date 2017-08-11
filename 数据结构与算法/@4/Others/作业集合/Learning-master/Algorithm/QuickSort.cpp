#include <iostream>
#include <vector>
using namespace std;

template <class T>
void swap(vector <T> & arr, int i, int j) {
    T tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
}

int SelectPivot(int left, int right) {
    //选择轴值，参数left，right分别表示序列的左右下标
    return (left + right) / 2;  //选择中间记录作为轴值
}

template <class T>
int Partition(vector <T> & arr, int left, int right) {
    // 分割函数，分割后轴值已到达正确位置
    int l = left; // l 为左指针
    int r = right; // r 为右指针
    T TempRecord = arr[r]; // 保存轴值
    while (l != r) { // l, r 不断向中间移动，直到相遇
        // l 指针向右移动，直到找到一个大于轴值的记录
        while (arr[l] <= TempRecord && r > l){
            l++;
        }
        if (l < r) { // 未相遇，将逆置元素换到右边空位
            arr[r] = arr[l];
            r--; // r 指针向左移动一步
        }
        // r 指针向左移动，直到找到一个大于轴值的记录
        while (arr[r] >= TempRecord && r > l) {
            r--;
        }
        if (l < r) { // 未相遇，将逆置元素换到左空位
            arr[l] = arr[r];
            l++; // l 指针向右移动一步
        }
    } //end while
    arr[l] = TempRecord; // 把轴值回填到分界位置 l 上
    return l; // 返回分界位置l
}

template <class T>
void QuickSort(vector <T> & arr, int left, int right) {
    //arr为待排向量，left，right分别为向量两端
    if (right <= left) {  //只有0或1个记录，就不需要排序
        return;
    }
    int pivot = SelectPivot(left, right);  //选择轴值
    swap(arr, pivot, right);   //轴值放到向量末端
    pivot = Partition(arr, left, right);  // 分割后轴值正确
    QuickSort(arr, left, pivot -1);  //左子序列递归快排
    QuickSort(arr, pivot + 1, right);  //右子序列递归快排
}

int main() {
    vector <int> arr = {3, 4, 2, 1, 6, 5, 8, 7, 9};
    QuickSort(arr, 0, 8);
    for (auto & i : arr) {
        cout << i << endl;
    }
    return 0;
}