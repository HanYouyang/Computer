#define TEST
#undef TEST

#define MAX_SIZE 50
#define MAX_N 700
#define INF 14

#include<stdio.h>
#include<memory.h>
#include<stdlib.h>

typedef struct
{
    int dx,dy,k;
}
record_type;

typedef struct
{
    int x,y,times;
}
point_type;

int cases,r,c,n,min;
int t[MAX_SIZE+1][MAX_SIZE+1],total;
point_type p[MAX_N];

int compare_point(const void* e1,const void* e2)
{
    const point_type* p1=(const point_type*) e1;
    const point_type* p2=(const point_type*) e2;
    if (p1->x!=p2->x)
        return p1->x-p2->x;
    else
        return p1->y-p2->y; 
} 

inline int dis(int x,int y)
{
    return x*x+y*y;
} 

int compare_record(const void* e1,const void* e2)
{
    const record_type* p1=(const record_type*) e1;
    const record_type* p2=(const record_type*) e2;
    if (p2->k!=p1->k)
        return p2->k-p1->k;
    else
        return dis(p1->dx,p1->dy)-dis(p2->dx,p2->dy); 
}

inline bool is_inside(int x,int y)
{
    return (1<=x && x<=r && 1<=y && y<=c);
}

void dfs(int now,int point)
{
    if ((min-now)*r<total && (min-now)*c<total)
        return;
    int dx,dy,k,num_j=0,i0,last,l=0;
    record_type record[MAX_N];
    #ifdef TEST
    printf("now=%d\n",now);
    for (int i=1;i<=r;i++)
        for (int j=1;j<=c;j++)
            printf("%d%c",t[i][j],j==c?'\n':' '); 
    #endif
    if (total==0)
    {
        if (now-1<min) 
            min=now-1;
        return;
    }
    for (int i=point;i<=n;i++)
      if (t[p[i].x][p[i].y])
      {
        for (int j=i+1;j<=n;j++)
          if (t[p[j].x][p[j].y])    
          {
            dx=p[j].x-p[i].x;
            dy=p[j].y-p[i].y;
            if (is_inside(p[i].x-dx,p[i].y-dy))
                continue;
            for (k=2;;k++)
            {
                if (is_inside(p[i].x+k*dx,p[i].y+k*dy))
                {
                    if (t[p[i].x+k*dx][p[i].y+k*dy]==0)
                    {
                        k=-1;
                        break;
                    }
                }
                else
                    break;
            }
            if (k>2)
            {
                record[num_j].k=k;
                record[num_j].dx=dx;
                record[num_j].dy=dy;
                num_j++;
            }
          }
        i0=i;
        break;
      }
    qsort(record,num_j,sizeof(record_type),compare_record);
    last=0;
    for (int i=0;i<num_j;i++)
    {
        if (record[i].k<record[last].k)
        {
            last=i;
            l++;
            if (l>=2)
                return;
        }
        //贪心求近似解 
        dx=record[i].dx;
        dy=record[i].dy;
        k=record[i].k;
        for (int i1=0;i1<k;i1++)
            t[p[i0].x+i1*dx][p[i0].y+i1*dy]--;
        total-=k;
        if (t[p[i0].x][p[i0].y])
            dfs(now+1,i0);
        else
            dfs(now+1,i0+1);
        for (int i1=0;i1<k;i1++)
            t[p[i0].x+i1*dx][p[i0].y+i1*dy]++;
        total+=k;
    }
    return;
}

int main()
{
    #ifdef TEST
    freopen("input.txt","r",stdin); 
    freopen("output.txt","w",stdout); 
    #endif
    scanf("%d",&cases);
    while (cases--)
    {
        min=INF;
        scanf("%d%d%d",&r,&c,&n);
        memset(t,0,sizeof(t));
        total=0;
        for (int i=0;i<n;i++)
        {
            scanf("%d%d%d",&p[i].x,&p[i].y,&p[i].times);
            t[(p+i)->x][(p+i)->y]=(p+i)->times;
            total+=(p+i)->times;
        }
        qsort(p,n,sizeof(point_type),compare_point);
        dfs(1,0);
        printf("%d\n",min);
    }
    return 0; 
}