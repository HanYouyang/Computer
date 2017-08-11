#include <iostream.h>
// ��̬�滮�㷨������Ŷ�������������
//�������:a[]�ڲ�����Ȩ,b[]�ⲿ����Ȩ,n�����
//�������:**wȨ���ܺ�,**r���������,**c�������Ĵ���

#define N 4

void OptimalBST(int a[], int b[], int n, int c[N+1][N+1], int r[N+1][N+1], int w[N+1][N+1])
{
	
    for(int i=0;i<=n;i++)
       for(int j=0;j<=n;j++)
	   {
		   c[i][j]=0;
		   r[i][j]=0;
		   w[i][j]=0;
	   }
	// ��ʼ��

	for (i = 0; i <=n; i++) {
		w[i][i] = b[i];
		//���Ȩ��w[i.j]
		for(int j=i+1;j<=n;j++)
			w[i][j]=w[i][j-1]+a[j]+b[j];
	}

	//ȷ��һ��������Ѷ���������
	for(int j=1;j<=n;j++)
	{
		c[j-1][j]=w[j-1][j];
		r[j-1][j]=j;
	}
	//ȷ��d��������Ѷ�����
	int m,k0,k;
	for(int d=2;d<=n;d++)
	{
		for(int j=d;j<=n;j++)
		{
			i=j-d;
		    m=c[i+1][j];
			k0=i+1;
			for(k=i+2;k<=j;k++)
			{
				if(c[i][k-1]+c[k][j]<m)
				{
					m=c[i][k-1]+c[k][j];
					k0=k;
				}
			}
			c[i][j]=w[i][j]+m;
			r[i][j]=k0;
		}
	}


}


void main()
{
	//��������ͼ12-28����Ѷ�����
	int a[N+1]={0,1,5,4,3};
	int b[N+1]={5,4,3,2,1};
	int c[N+1][N+1];
	int r[N+1][N+1];
	int w[N+1][N+1];
	int n=N;
	//������Ѷ�����
    OptimalBST(a,b,n,c,r,w);
	for(int i=0;i<=n;i++)
	{
	
        for(int j=0;j<i;j++)
			cout<<"  ";
		cout<<"0 ";
		for(j=i+1;j<=n;j++)
		{
			cout<<r[i][j]<<" ";
		}
		cout<<endl;
	}
}

