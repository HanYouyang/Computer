#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int first, k, n, temp;
    cin >> first >> n >> k;
    int data[100005], next[100005], list[100005];
    for (int i = 0; i < n; i++) {
        cin >> temp;
        cin >> data[temp] >> next[temp]; 
    }
    int num = 0;
    while (first != -1) {
        list[num++] = first; //存储所有结点地址 
        first = next[first];
    }
    
    for (int i = 0; i < (num - num % k); i += k){ 
        reverse(begin(list) + i, begin(list) + i + k);
    }
	
    for (int i = 0; i < num - 1; i++){ 
        printf("%05d %d %05d\n", list[i], data[list[i]], list[i + 1]);
    } 
    printf("%05d %d -1", list[num - 1], data[list[num - 1]]);
	return 0;
}
