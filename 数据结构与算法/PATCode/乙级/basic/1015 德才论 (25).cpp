#include<iostream>
#include<vector>
#include<algorithm>
struct student
{
	int ID;
	int d_score;
	int c_score;
};
bool compare(const student &x, const student & y)
{
	if ((x.d_score + x.c_score) > (y.c_score + y.d_score))
		return true;
	else if ((x.d_score + x.c_score) == (y.c_score + y.d_score))
	{
		if (x.d_score > y.d_score)
			return true;
		else if (x.d_score == y.d_score)
		{
			return x.ID < y.ID;
		}
	}
	return false;
}
void show(const std::vector<student>&x)
{
	for (int i = 0; i < x.size(); ++i)
	{
		printf("%d %d %d\n", x[i].ID, x[i].d_score, x[i].c_score);
	}
}
int main()
{

	int N, L, H;
	std::cin >> N >> L >> H;
	student stu;
	std::vector<student> vec;
	std::vector<student> vec1;
	std::vector<student> vec2;
	std::vector<student> vec3;
	std::vector<student> vec4;

	for (int i = 0; i < N; ++i)
	{
		std::cin >> stu.ID >> stu.d_score >> stu.c_score;
		vec.push_back(stu);
	}

	for (int i = 0; i < vec.size(); ++i)
	{
		if (vec[i].d_score >= H && vec[i].c_score >= H)
			vec1.push_back(vec[i]);
		else if (vec[i].d_score >= H &&vec[i].c_score >= L)
			vec2.push_back(vec[i]);
		else if ((vec[i].d_score>=vec[i].c_score) && (vec[i].c_score >= L))
			vec3.push_back(vec[i]);
		else if ((vec[i].c_score >= L) && (vec[i].d_score >= L))
			vec4.push_back(vec[i]);
	}

	std::sort(vec1.begin(), vec1.end(), compare);
	std::sort(vec2.begin(), vec2.end(), compare);
	std::sort(vec3.begin(), vec3.end(), compare);
	std::sort(vec4.begin(), vec4.end(), compare);
	std::cout << vec1.size() + vec2.size() + vec3.size() + vec4.size() << std::endl;
	show(vec1); show(vec2); show(vec3); show(vec4);

	return 0;
}
