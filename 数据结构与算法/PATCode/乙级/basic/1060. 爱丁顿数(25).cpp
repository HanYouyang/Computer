#include<iostream>
#include<functional>
#include<vector>
#include<algorithm>
#include<cstdio>
using std::cout;
using std::cin;
int main()
{
	int N,num;
	cin >> N;
	std::vector<int> vec;
	for (int i = 0; i < N; ++i)
	{
		scanf_s("%d", &num);
		vec.push_back(num);
	}

	std::sort(vec.begin(), vec.end(),std::greater<int>());
	
	/*for (int i =0; i <vec.size(); ++i)  ���󣡣�����������E���ﳵ����EӢ����������E,���������ڣ�����
	{
		if (vec[i]<(i + 1))               ���ϵȺŻ�����һ�����Ե��޷�ͨ����
		{
			printf("%d", i);break;        ��©����������й����������������������
		}
	}*/
	int i = 0;
	while (i<vec.size(), vec[i]>i + 1)
	{
		++i;
	}
	printf("%d", i);
	return 0;
}