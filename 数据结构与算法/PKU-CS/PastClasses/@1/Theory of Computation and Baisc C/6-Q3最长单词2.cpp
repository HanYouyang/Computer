#include <iostream>
using namespace std;
//最长单词2
int main(){
    char s[500], ch[500][500];
    int size[500] ={0}, j = 0, k = 0;

    cin.get(s, 500);
    cin.get();

    for(int i = 0; s[i] != '.'; i++){
        if(s[i] != ' '){
            size[j] += 1;
            ch[j][k] = s[i];
            k += 1;
        }else if(s[i] == ' '){
            j += 1;
            k = 0;
        }
    }

    int order_max = 0, size_max = 0;

    for(int i = 0; size[i] != 0; i++){
        if(size[i] > size_max){
            size_max = size[i];
            order_max = i;
        }
    }

    cout << ch[order_max] << endl;

    return 0;
}
