#include <iostream>
using namespace std;
class tidy
{
public:
    char ch;//字母
    int num;//数量
    int pos;//出现位置
};
int main()
{
    char a[500],t;
    tidy tidys[26],td;
    int k=0,n,m,pos;
    cin>>a;
    for(n=0;a[n]!='\0';n++)//统计所以字母
    {
        if(a[n]>='A' && a[n]<='Z' || a[n]>='a' && a[n]<='z')
        {
            if(a[n]>='a')
                t=a[n]-32;
            else
                t=a[n];
            for(m=0;m<k;m++)//查找tidys数组中是否存在该字母
            {
                if(tidys[m].ch>='a')
                {
                    if(tidys[m].ch-32==t)
                        break;
                }
                else
                {
                    if(tidys[m].ch==t)
                        break;
                }
            }
            if(m==k)
            {
                tidys[k].ch=a[n];
                tidys[k].num=1;
                tidys[k].pos=n;
                for(m=0;a[m]!='\0';m++)
                {
                    if(n!=m)
                    {
                        if(a[m]>='a')
                        {
                            if(t==a[m]-32)
                            {
                                tidys[k].num+=1;
                            }
                        }
                        else
                        {
                            if(t==a[m])
                            {
                                tidys[k].num+=1;
                            }
                        }
                    }
                }
                k++;
            }
        }
    }
    for(n=0;n<k;n++)//排序
    {
        for(m=n;m<k;m++)
        {
            if(tidys[n].num<tidys[m].num)
            {
                td.ch=tidys[n].ch;
                td.num=tidys[n].num;
                tidys[n].ch=tidys[m].ch;
                tidys[n].num=tidys[m].num;
                tidys[m].ch=td.ch;
                tidys[m].num=td.num;
            }
        }
    }
    if(k>1)
    {
        for(m=0;m<k;m++)//寻找第二多的字母，并比较那个最先出现
        {
            if(tidys[m].num<tidys[0].num)
            {
                pos=m;
                for(n=m;n<k;n++)
                {
                    if(tidys[m].num==tidys[n].num)
                    {
                        if(tidys[n].pos<tidys[m].pos)
                            pos=n;
                    }
                    else
                        break;
                }
                break;
            }
        }
        if(m==k)
            pos==0;
        if(tidys[pos].ch>='a')
        {
            cout<<(char)(tidys[pos].ch-32)<<'+'<<tidys[pos].ch<<':'<<tidys[pos].num<<endl;
        }
        else
        {
            cout<<tidys[pos].ch<<'+'<<(char)(tidys[pos].ch+32)<<':'<<tidys[pos].num<<endl;
        }
    }
    return 0;
}
