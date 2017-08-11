#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <deque>
#include <vector>
using namespace std;

#define maxn 10005

struct info
{
    int comeTime;
    int serveTime;
    int tag;
}tmp;

deque<info> noVIP;//�ǹ������
deque<info> VIP;//�������
int table[maxn];//��¼���ӵ�ǰ����ʣ����ʱ��
int numsTableServed[maxn];//��¼���ӷ���Ŀͻ�����
int VIPTableCol[maxn];
int n,hh,mm,ss,tableNums,vipTableNums,id;

int cmp(const info &a, const info &b)
{
    return a.comeTime < b.comeTime;
}

bool isVIPCome(int curTime)
{
    int i;
    for(i = 0; i < VIP.size(); i++)
    {
        if(VIP[i].comeTime <= curTime)
        {
            return true;
        }
    }
    return false;
}

bool hasVIPTable(int &ID)
{
    int i;
    for(i = 0; i < vipTableNums; i++)
    {
        if(table[ VIPTableCol[i] ] == 0)
        {
            ID = VIPTableCol[i];
            return true;
        }
    }
    return false;
}

bool hasNext(int cur, int &from)
{
    info tmp1, tmp2;
    if(!noVIP.empty() && !VIP.empty())
    {
        tmp1 = noVIP.front();
        tmp2 = VIP.front();
        if(tmp1.comeTime <= cur && tmp2.comeTime <= cur)
        {
            if(tmp1.comeTime < tmp2.comeTime)
            {
                from = 0;
                return true;
            }
            else
            {
                from = 1;
                return true;
            }
        }
        else if(tmp1.comeTime <= cur && tmp2.comeTime > cur)
        {
            from = 0;
            return true;
        }
        else if(tmp2.comeTime <= cur && tmp1.comeTime > cur)
        {
            from = 1;
            return true;
        }
        else
        {
            return false;
        }
    }
    else if(!noVIP.empty() && VIP.empty())
    {
        tmp1 = noVIP.front();
        if(tmp1.comeTime <= cur)
        {
            from = 0;
            return true;
        }
        else
        {
            return false;
        }
    }
    else if(noVIP.empty() && !VIP.empty())
    {
        tmp2 = VIP.front();
        if(tmp2.comeTime <= cur)
        {
            from = 1;
            return true;
        }
        else
        {
            return false;
        }
    }
    return false;
}

bool hasTable(int &ID)
{
    int i;
    for(i = 1; i <= tableNums; i++)
    {
        if(table[i] == 0)
        {
            ID = i;
            return true;
        }
    }
    return false;
}

int main()
{
    int i;
    memset(table, 0, sizeof(table));
    memset(numsTableServed, 0, sizeof(numsTableServed));

    cin >> n;
    for(i = 0; i < n; i++)
    {
        scanf("%d:%d:%d %d %d", &hh, &mm, &ss, &tmp.serveTime, &tmp.tag);
        tmp.serveTime = tmp.serveTime > 120 ? 120 : tmp.serveTime;
        tmp.serveTime *= 60;
        tmp.comeTime = hh*60*60+mm*60+ss;
        if(tmp.tag)
        {
            VIP.push_back(tmp);
        }
        else
        {
            noVIP.push_back(tmp);
        }
    }
    cin >> tableNums;
    cin >> vipTableNums;
    for(i = 0; i < vipTableNums; i++)
    {
        cin >> id;
        VIPTableCol[i] = id;
    }
    sort(noVIP.begin(), noVIP.end(), cmp);
    sort(VIP.begin(), VIP.end(), cmp);
    sort(VIPTableCol, VIPTableCol+vipTableNums);
    info curVIP;
    int earlyPairFrom;
    int TableID;
    int cur = 8*60*60;
    while(cur < 21*60*60)
    {
        for(i = 1; i <= tableNums; i++)
        {
            if(table[i] != 0)
                table[i]--;
        }

        while(isVIPCome(cur))//����Ƿ�������VIP��
        {
            //printf("��ǰʱ��%d, ��VIP��\n", cur);
            if(hasVIPTable(TableID))//����Ƿ���VIP���ӿ���
            {
                info curPair = VIP.front();
                VIP.pop_front();
                table[TableID] = curPair.serveTime;
                numsTableServed[TableID]++;

                //printf("ΪVIP�ͻ���������%d\n", TableID);

                printf("%.2d:%.2d:%.2d %.2d:%.2d:%.2d %d\n", curPair.comeTime/60/60,
                       curPair.comeTime/60%60, curPair.comeTime%60, cur/60/60, cur/60%60,
                       cur%60, (cur-curPair.comeTime+30)/60);
            }
            else
            {
                break;
            }
        }

        while(hasNext(cur, earlyPairFrom))//�ҳ��Ѿ�����ʱ�������pair
        {
            if(earlyPairFrom)//���������Ǹ�VIP
            {
                if(hasTable(TableID))//����Ƿ�������
                {
                    info curPair;
                    curPair = VIP.front(); VIP.pop_front();
                    table[TableID] = curPair.serveTime;
                    numsTableServed[TableID]++;
                    printf("%.2d:%.2d:%.2d %02d:%.2d:%.2d %d\n", curPair.comeTime/60/60,
                       curPair.comeTime/60%60, curPair.comeTime%60, cur/60/60, cur/60%60,
                       cur%60, (cur-curPair.comeTime+30)/60);
                }
                else
                {
                    break;
                }

            }
            else//����Ĳ��Ǹ�VIP
            {
                while(isVIPCome(cur))//����Ƿ�������VIP��
                {
                    //printf("��ǰʱ��%d, ��VIP��\n", cur);
                    if(hasVIPTable(TableID))//����Ƿ���VIP���ӿ���
                    {
                        info curPair = VIP.front();
                        VIP.pop_front();
                        table[TableID] = curPair.serveTime;
                        numsTableServed[TableID]++;

                        //printf("ΪVIP�ͻ���������%d\n", TableID);

                        printf("%.2d:%.2d:%.2d %.2d:%.2d:%.2d %d\n", curPair.comeTime/60/60,
                               curPair.comeTime/60%60, curPair.comeTime%60, cur/60/60, cur/60%60,
                               cur%60, (cur-curPair.comeTime+30)/60);
                    }
                    else
                    {
                        break;
                    }
                }
                //Ϊ��˿��������
                if(hasTable(TableID))//����Ƿ�������
                {
                    info curPair;
                    curPair = noVIP.front(); noVIP.pop_front();

                    table[TableID] = curPair.serveTime;
                    numsTableServed[TableID]++;
                    //printf("ΪnoVIP�ͻ���������%d\n", TableID);

                    printf("%.2d:%.2d:%.2d %.2d:%.2d:%.2d %d\n", curPair.comeTime/60/60,
                           curPair.comeTime/60%60, curPair.comeTime%60, cur/60/60, cur/60%60,
                           cur%60, (cur-curPair.comeTime+30)/60);
                }
                else
                {
                    break;
                }
            }
        }
        cur++;
    }
    printf("%d", numsTableServed[1]);
    for(i = 2; i <= tableNums; i++)
    {
        printf(" %d", numsTableServed[i]);
    }
    printf("\n");
    return 0;
}
