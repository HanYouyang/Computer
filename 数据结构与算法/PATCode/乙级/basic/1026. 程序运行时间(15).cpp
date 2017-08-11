#include<iostream>
#include<algorithm>

int main()
{
	double c1, c2;
	std::cin >> c1 >> c2;
	int time = std::round((c2 - c1) / 100);//不用std也可
	int h_time = time / 3600;
	int m_time = (time - h_time * 3600) / 60;
	int s_time = time - h_time * 3600 - m_time * 60;
	printf("%02d:%02d:%02d", h_time, m_time, s_time);
	return 0;
}
