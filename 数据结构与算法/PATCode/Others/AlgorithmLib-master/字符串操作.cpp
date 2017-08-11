#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct hash  Hash;
struct hash
{
    char HOT[150];
    Hash *next;
    int *sum;
}H[100003];
Hash * creat()
{
    Hash *p;
    p=(Hash*)malloc(sizeof(Hash));
    p->sum=NULL;
    p->next=NULL;
    return p;
}
int getkey(char ID[])
{
    unsigned int key=0,i=0;
    while(ID[i])
    {
        key = key<<5;
        key+=ID[i];
        key%=100003;
        i++;
    }
    return key%100003;
}
Hash * insert(char HOT[])
{
    int key=getkey(HOT);
    if(H[key].sum==NULL)
    {
        strcpy(H[key].HOT,HOT);
        H[key].sum=(int*)malloc(sizeof(int));
        *(H[key].sum)=1;
        H[key].next=NULL;
        return &H[key];
    }
    else
    {
        Hash *p,*q;
        q=p=&H[key];
        while(p)
        {
            if(strcmp(p->HOT,HOT)==0)
            {
                (*(p->sum))++;
                return p;
            }
            q=p;
            p=p->next;
        }
        p=q->next=creat();
        strcpy(p->HOT,HOT);
        p->sum=(int*)malloc(sizeof(int));
        *(p->sum)=1;
        return p;
    }
}
bool get_hot(char HOT[],char t[],int *i)
{
    int k=0,len=0;
    while(t[*i])
    {
        if(t[*i]=='#')
        {
            (*i)++;
            while(t[*i]!='#' && t[*i] && len<40)
            {
                if( ('A'<=t[*i] && t[*i]<='Z') || ('a'<=t[*i] && t[*i]<='z') || ('0'<=t[*i] && t[*i]<='9'))
                {
                    if('A'<=t[*i] && t[*i]<='Z')
                        t[*i]+='a'-'A';
                    HOT[k++]=t[*i];
                }
                else if(k && HOT[k-1]!=' ')
                    HOT[k++]=' ';
                (*i)++;
                len++;
            }
            if(k && HOT[k-1]==' ')
                k--;
            HOT[k]='\0';
            if(HOT[0]<='z' && HOT[0]>='a')
                HOT[0]+='A'-'a';
 
            if(len>=40)
            while(t[*i]!='#')
                (*i)++;
 
            (*i)++;
            return true;
        }
        else
            (*i)++;
    }
    return false;
}
bool exist(char HOT[],char table[40][45],int *k)
{
    int i=0;
    for(i=0;i<*k;i++)
    {
        if(strcmp(HOT,table[i])==0)
            return true;
    }
    strcpy(table[*k],HOT);
    (*k)++;
    return false;
}
int main()
{
    int n,more=0,i,max=0,k=0;
    char HOT[150];
    char t[150];
    char table[140][45];
    Hash *p,*ans;
    for(n=0;n<100003;n++)
        H[n].sum=NULL;
    scanf("%d",&n);
    getchar();
    while(n--)
    {
        gets(t);
        i=0;
        k=0;
        while(get_hot(HOT,t,&i))
        {
            if(exist(HOT,table,&k))
                continue;
            p=insert(HOT);
            if(*(p->sum) > max)
            {
                max=*(p->sum);
                ans=p;
                more=0;
            }
            else if(*(p->sum) == max)
            {
                if(strcmp(p->HOT,ans->HOT)<0)
                    ans=p;
                more++;
            }
        }
    }
    printf("%s\n%d\n",ans->HOT,max);
    if(more)
        printf("And %d more ...\n",more);
    return 0;
}