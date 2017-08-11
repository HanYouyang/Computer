//˼·��̰��
//���뿴����http://blog.csdn.net/Hackbuteer1/article/details/7402127
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;

vector<pair<double,double> > elem;
int cmp(const pair<double,double> &a, const pair<double,double> &b)
{
    return a.second < b.second;
}

int main()
{
    double capacity,dist,tmpd,tmpp,index,minPrice;
    int n,i,j,avg;
    scanf("%lf %lf %d %d",&capacity, &dist, &avg, &n);
    for(i = 0; i < n; i++)
    {
        scanf("%lf %lf", &tmpp, &tmpd);
        elem.push_back(make_pair(tmpp,tmpd));
    }
    sort(elem.begin(), elem.end(), cmp);
    elem.push_back(make_pair(0,dist));

    if(elem[0].second > 0)
    {//�����ʼλ���޷�����
        printf("The maximum travel distance = 0.00\n");
        return 0;
    }
    int ok = 1;
    double cur = 0;
    double sum = 0;
    for(i = 0; i < n;)
    {
        if(elem[i+1].second - elem[i].second > capacity*avg)
        {//�������������Ҳ�޷��ߵ���һ�����͵�
            printf("The maximum travel distance = %.2lf\n", capacity*avg+elem[i].second);
            ok = 0;
            break;
        }
        else
        {
            //�ҳ��ܵ���ļ���վ���ͼ�����˵�
            index = i;
            minPrice = elem[i].first;
            for(j = i + 1 ; elem[j].second - elem[i].second <= cur*avg && j <= n ; j++)
            {
                if(elem[j].first < minPrice)
                {
                    minPrice = elem[j].first;
                    index = j;
                }
            }
            if(index != i)
            {
                cur -= (elem[index].second - elem[i].second)/avg;
                i = index;
                continue;
            }
            //�������һ���ͼ۱��˵ģ���һЩ�����ܵ�
            index = i;
            for(j = i + 1; elem[j].second - elem[i].second <= capacity*avg && j <= n; j++)
            {
                if(elem[j].first < elem[i].first)
                {
                    index = j;
                    break;
                }
            }
            if(index != i)
            {
                sum += ((elem[index].second - elem[i].second)/avg - cur)*elem[i].first;
                cur = 0;
                i = index;
                continue;
            }

            //�Ҳ����ȵ�ǰ��վ�ļ۸񻹱��˵���վ��ʱ��,�ڵ�ǰ��վ��Ҫ�����ͣ��ܵ����ܵ�������վ���ͼ���С���Ǹ���վ
            index = i;
            minPrice = 1e18;
            for(j = i + 1; elem[j].second - elem[i].second <= capacity*avg && j <= n; j++)
            {
                if(elem[j].first < minPrice)
                {
                    minPrice = elem[j].first;
                    index = j;
                }
            }
            sum += (capacity - cur) * elem[i].first;
            cur = capacity - (elem[index].second - elem[i].second)/avg;
            i = index;
        }
    }
    if(ok)
    {
        printf("%.2lf\n", sum);
    }
    return 0;
}
