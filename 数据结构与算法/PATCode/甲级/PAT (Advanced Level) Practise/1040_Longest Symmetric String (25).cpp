#include <cstdio>
#include <cstring>
using namespace std;

int work(char *str)
{//����ż��������ַ�������ö��
    char *left;
    char *right;
    int ans = 1;
    char *ptr = str;
    while(*ptr != '\0')
    {
        //�������
        left = ptr - 1;
        right = ptr + 1;
        while(left >= str && *right != '\0' && *left == *right)
        {
            left--;
            right++;
        }
        if(right - left - 1 > ans)
            ans = right - left - 1;
        //ż�����
        left = ptr;
        right = ptr+1;
        while(left >= str && *right != '\0' && *left == *right)
        {
            left--;
            right++;
        }
        if(right - left - 1 > ans)
            ans = right - left - 1;
        ptr++;
    }
    return ans;
}

int main()
{
    char str[1005];
    gets(str);
    printf("%d\n", work(str));
    return 0;
}
