#include <iostream>
#include <cstring>
using namespace std;
//文字排版
int main(){
    int num=0;
    char (*word)[41] = new char[num+1][41];
    cin >> num;

    for(int i = 0; i < num; i++){
        cin >> word[i];
    }

    int len=0;

    for(int i = 0; i < num; i++){
        len = len + strlen(word[i]);
            cout << word[i];
            if(len + strlen(word[i+1]) + 1 <= 80 && i+1 < num){
                cout << " ";
                len = len + 1;
            }else{
                cout << endl;
                len=0;
            }
    }

    delete []word;
}
