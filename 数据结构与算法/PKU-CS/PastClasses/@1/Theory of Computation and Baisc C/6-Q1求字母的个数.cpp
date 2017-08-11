#include <iostream>
using namespace std;
//在一个字符串中找出元音字母a,e,i,o,u出现的次数。
int main(){
    int sizeOfa = 0, sizeOfe = 0, sizeOfi = 0, sizeOfo = 0, sizeOfu = 0;
    int length = 0;
    char ch[80];
    cin.get(ch,80);

    while(ch[length] != '\0'){
        if(ch[length] == 'a')
            sizeOfa += 1;
        else if(ch[length] == 'e')
            sizeOfe += 1;
        else if(ch[length] == 'i')
            sizeOfi += 1;
        else if(ch[length] == 'o')
            sizeOfo += 1;
        else if(ch[length] == 'u')
            sizeOfu += 1;
        length += 1;
    }

    cout << sizeOfa << " " << sizeOfe << " " << sizeOfi << " " << sizeOfo << " " << sizeOfu << endl;
    return 0;
}
