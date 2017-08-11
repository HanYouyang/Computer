#include <iostream>
using namespace std;

int main(){
    int nSize, max_mark = 0;
    cin >> nSize;
    int mark[nSize];

    for(int i = 0; i < nSize; i++){
        cin >> mark[i];
    }

    for(int i = 0; i < nSize; i++){
        if(mark[i] >= max_mark){
            max_mark = mark[i];
        }
    }

    cout << max_mark << endl;

    return 0;
}
