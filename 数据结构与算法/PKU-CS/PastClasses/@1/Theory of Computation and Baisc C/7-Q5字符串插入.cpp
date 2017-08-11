#include <iostream>
#include <cstring>
using namespace std;
//字符串插入
int main()
{
    int max, maxpos, sizeOFstr, sizeOFsubstr;
    char str[15], substr[15];
    while(cin >> str >> substr)
    {
        max = 0;
        sizeOFstr = strlen(str);
        sizeOFsubstr = strlen(substr);
        for(int i = 0; str[i] != '\0'; i++)
        {
            if(str[i] > max)
            {
                max = str[i];
                maxpos = i;
            }
        }
        for(int i = 0; i <= maxpos; i++)
        {
            cout << str[i];
        }
        for(int i = 0; i < sizeOFsubstr; i++)
        {
            cout << substr[i];
        }
        for(int i = maxpos + 1; i < sizeOFstr; i++)
        {
            cout << str[i];
        }
        cout << endl;
    }
}
