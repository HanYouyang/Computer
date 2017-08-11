#include <iostream>
using namespace std;
//校门外的树
int main(){
    int L, M, sum = 0;
    int tree[10001];
    int begin[101], end[101];
    cin >> L >> M;
    
    for(int i = 0; i <= L; i++)
         tree[i] = 1;
    for(int i = 0; i < M; i++)
        cin >> begin[i] >> end[i];
    for(int i = 0; i < M; i++){
         for(int j = begin[i]; j <= end[i]; j++)
              tree[j] = 0;
    }
    for(int i = 0; i <= L; i++){
         if(tree[i] == 1)
              sum++;
    }
    cout << sum << endl;

    return 0;
}
