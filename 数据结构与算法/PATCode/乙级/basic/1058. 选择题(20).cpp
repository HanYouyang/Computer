#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
struct T
{
	int score,option;
	std::string r_ans;
}t;

int main()
{
	int N, M;
	std::cin >> N >> M;
	std::vector<T> tvec;
	std::string ans;
	std::vector<std::string> avec;
	std::vector<int> sco;
	int err[110] = {0};
	for (int i = 0; i < M; ++i)
	{
		std::cin >> t.score >> t.option;
		std::cin.get();
		std::getline(std::cin, t.r_ans);
		tvec.push_back(t);
	}
	for (int i = 0; i < N; ++i)
	{
		std::getline(std::cin,ans);
		avec.push_back(ans);
	}
	int flag=0,sum, count,k; std::string str;
	for (int j = 0; j < avec.size(); ++j)
	{
		count = 0, k = 0,sum=0;
		for (int i = 0; i < avec[j].size(); ++i)
		{
			if (avec[j][i] == ')')
			{
				flag = 0;
				if (str != tvec[k].r_ans)
					err[k + 1]++,k++;
				else
					count++,sum+=tvec[k].score,k++;
				str ="";
			}
			if (flag)
				str = str + avec[j][i];
			if (avec[j][i] == '(')
				flag = 1;
		}
		sco.push_back(sum);
	}

	for (int i = 0; i < sco.size(); ++i)
		std::cout << sco[i] << std::endl;

	int *max = std::max_element(err, err + k);
	if (*max == 0)
		printf("Too simple");
	else
	{
		int m;
		std::cout << *max << ' ';
		for (int i = 0; i < k + 1; ++i)
		{
			if (err[i] == *max)
			{
				std::cout << i; m = i; break;
			}
		}
		for (int i = m + 1; i < k + 1; ++i)
		{
			if (err[i] == *max)
				std::cout << ' ' << i;
		}
	}

	return 0;
}