#include <iostream>
#include <cstdio>
using namespace std;

int main(){
    int L, M;    
    cin >> L >> M;
    
    int tree[10001];    
    for (int i = 0; i <= L; i++) {
    	tree[i] = 1;
	} 
	
    int begin[101], end[101];    
    for (int i = 0; i < M; i++) {
    	cin >> begin[i] >> end[i];
	}
    
    for (int i = 0; i < M; i++) {
    	for (int j = begin[i]; j <= end[i]; j++) {
    		tree[j] = 0;
		}
	}
    
    int sum = 0;
    for (int i = 0; i <= L; i++) {
    	if (tree[i] == 1) {
    		sum = sum + 1;
		}
	}
    
    cout << sum << endl;
    
    return 0;
}
