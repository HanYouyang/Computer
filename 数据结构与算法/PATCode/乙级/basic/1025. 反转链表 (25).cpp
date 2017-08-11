#include<iostream>
#include<algorithm>
const int maxn = 100010;
struct Node
{
	int last, next;
	int element;
	int order = maxn;
}node[maxn];
bool compare(const Node &a, const Node &b)
{
	return a.order < b.order;
}
int main()
{
	int first, N, K, address;
	std::cin >> first >> N >> K;

	for (int i = 0; i < N; ++i)
	{
		std::cin >> address;
		std::cin >> node[address].element >> node[address].next;
		node[address].last = address;
	}
	int p = first, count = 0;
	while (p != -1)
	{
		node[p].order = count++;
		p = node[p].next;
	}
	std::sort(node, node + maxn, compare);
	N = count;


	for (int i = 0; i < N / K; ++i)
	{
		for (int j = i*K + K - 1; j >= K*i; --j)
		{
			if ((j==K*i)&&(N%K==0))
				node[j].next = node[K*(i + 1)+K-1].last;
			else if ((N%K!= 0)&&(j==K*i))
			{
				if (j == K*(N / K - 1))
					node[j].next = node[K*(i + 1)].last;
				else
					node[j].next = node[K*(i + 1) + K - 1].last;//else²»ÄÜÊ¡£¡£¡£¡£¡
			}
			else node[j].next = node[j - 1].last; 

			if (j==N-K&&N%K==0)
				printf("%05d %d %d\n", node[j].last, node[j].element, -1);
			else printf("%05d %d %05d\n", node[j].last, node[j].element, node[j].next);	  
		}
	}



	if (N%K != 0)
	{
		for (int i = N / K*K; i < N - 1; i++)
			printf("%05d %d %05d\n", node[i].last, node[i].element, node[i].next);
		printf("%05d %d %d\n", node[N - 1].last, node[N - 1].element, node[N - 1].next);
	}


	return 0;
}
