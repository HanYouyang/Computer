//2016年2月20日13时48分16秒
//2016年2月20日14时58分49秒
//改进版
#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 110;
int origin[maxn], temp[maxn], changed[maxn];
int n;


bool isEqual(int a[], int b[])
{
  for(int i = 1; i <= n; i++){
    if(a[i] != b[i]) return false;
  }
  return true;
}


void printArray(int a[]){
  for(int i = 1; i <= n; i++){
    if(i != 1) printf(" ");
    printf("%d", a[i]);
  }
}

bool insertSort()
{
  bool flag = false;
  int i, j;
  for(i = 2; i <= n; i++){
    if(i != 2 && isEqual(temp, changed)) flag = true;
    temp[0] = temp[i];
    for(j = i; j > 1 && temp[0] < temp[j - 1]; j--) temp[j] = temp[j - 1];
    temp[j] = temp[0];
    if(flag) return true;
  }
  return false;
}

bool mergeSort()
{
  bool flag = false;
  for(int step = 2; step / 2 <= n; step *= 2){
    if(step != 2 && isEqual(temp, changed)) flag = true;
    for(int i = 1; i <= n; i += step){
      //sort的第二个参数容易写
      sort(temp + i, temp + min(n + 1, i + step));
    }
    if(flag) return true;
  }
  return false;
}

int main()
{
  scanf("%d", &n);
  for(int i = 1; i <= n; i++){
    scanf("%d", origin + i);
    temp[i] = origin[i];
  }
  for(int i = 1; i <= n; i++){
    scanf("%d", changed + i);
  }
  if(insertSort()){
    printf("Insertion Sort\n");
    printArray(temp);
  } else {
    for(int i = 1; i <= n; i++) temp[i] = origin[i];
    mergeSort();
    printf("Merge Sort\n");
    printArray(temp);
  }
  return 0;
}

//#include <iostream>
//#include <cstdio>
//#include <algorithm>
//
//using namespace std;
//
////本题大部分变量采用全局变量，这样可以避免调用函数的参数调用
////使逻辑更清晰
//const int maxn = 110;
//int n, a[maxn], b[maxn], c[maxn];
//
//bool isEqual(int d[], int e[])
//{
//  for(int i = 1; i <= n; i++){
//    if(d[i] != e[i]) return false;
//  }
//  return true;
//}
//
////非递归形式的归并排序的基础上修改而来
//bool MergeSort()
//{
//  int step, i;
//  for(step = 2; step / 2 <= n; step *= 2){
//    for(i = 1; i <= n; i += step){
//      //因为题目只要求求出归并排序每一趟结束时的序列，所以可以使用sort代替merge
//      sort(c + i, c + min(i + step, n + 1));
//    }
//    //每一次排序之后比较是否与给定数列相等
//    if(isEqual(c, b)){
//      step *= 2;
//      for(i = 1; i <= n; i += step){
//        sort(c + i, c + min(i + step, n + 1));
//      }
//      return true;
//    }
//  }
//  return false;
//}
//
////插入排序的基础上修改而来
//bool InsertSort()
//{
//  for(int i = 2; i <= n; i++){
//    int j;
//    a[0] = a[i];
//    for(j = i - 1; j >= 1; j--){
//      if(a[0] < a[j]) a[j + 1] = a[j];
//      else break;
//    }
//    a[j + 1] = a[0];
//    //若相等则说明数组b是通过此排序方法得到
//    if(isEqual(a, b)){
//      if(i++ == n) return true;
//      a[0] = a[i];
//      for(j = i - 1; j >= 1; j--){
//        if(a[0] < a[j]) a[j + 1] = a[j];
//        else break;
//      }
//      a[j + 1] = a[0];
//      return true;
//    }
//  }
//  return false;
//}
//
//int main()
//{
//  scanf("%d", &n);
//  for(int i = 1; i <= n; i++){
//    scanf("%d", &a[i]);
//    c[i] = a[i];
//  }
//  for(int i = 1; i <= n; i++){
//    scanf("%d", &b[i]);
//  }
//  //如果时插入排序，输出结果
//  if(InsertSort()){
//    printf("Insertion Sort\n");
//    for(int i = 1; i <= n; i++){
//      if(i > 1) printf(" ");
//      printf("%d", a[i]);
//    }
//  }
//  //否则执行归并排序并输出结果
//  else if(MergeSort()){
//    printf("Merge Sort\n");
//    for(int i = 1; i <= n; i++){
//      if(i > 1) printf(" ");
//      printf("%d", c[i]);
//    }
//  }
//  return 0;
//
