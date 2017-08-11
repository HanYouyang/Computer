#include<iostream>
#include<string>
int main()
{
	std::string in;
	std::string r_in;
	std::string count;
	std::cin >> in >> r_in;
	
	for (int i = 0; i < in.size(); ++i)
	{
		if (r_in.find(in[i])>100)
		{
			if (count.find((char)toupper(in[i])) > 100)
			{
				std::cout << (char)toupper(in[i]);
				count.push_back((char)toupper(in[i]));
			}
		}
	}

	return 0;
}
