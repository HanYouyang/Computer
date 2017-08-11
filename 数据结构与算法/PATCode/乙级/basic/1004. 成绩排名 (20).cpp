#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;

struct STU
{
	string name, id;
	int score;
}stu;
vector<STU> vec;
bool comp(STU&s1, STU&s2)
{
	return s1.score > s2.score;
}
int main()
{
	int N;
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> stu.name >> stu.id >> stu.score;
		vec.push_back(stu);
	}
	sort(vec.begin(), vec.end(), comp);

	cout << vec[0].name << ' ' << vec[0].id << endl;
	cout << vec[N - 1].name << ' ' << vec[N - 1].id;
}