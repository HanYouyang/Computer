#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
//忽略大小写比较字符串大小
int main(){
    char s1[81], s2[81];
    gets(s1);
    gets(s2);

    for(int i = 0; s1[i] != '\0'; i++)
        if(s1[i] >= 'A' && s1[i] <= 'Z')
            s1[i] += 'a'-'A';

    for(int i = 0; s2[i] != '\0'; i++)
        if(s2[i] >= 'A' && s2[i] <= 'Z')
            s2[i] += 'a'-'A';

    if(strcmp(s1, s2) == 0)
       cout << "=\n";
    else if(strcmp(s1, s2) > 0)
       cout << ">\n";
    else
       cout << "<\n";

    return 0;
}