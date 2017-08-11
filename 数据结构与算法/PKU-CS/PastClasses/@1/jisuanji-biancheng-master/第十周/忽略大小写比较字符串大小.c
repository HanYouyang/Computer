#include "iostream"
using namespace std;
int main(int argc, char const *argv[])
{
	int i;
	char result, s1[80], s2[80];
	cin.getline(s1,80);
	cin.getline(s2,80);
	for (i = 0; s1[i] != '\0'; ++i)
	{
		if(s1[i]>= 'a' && s1[i] <= 'z')
			s1[i] -= 32;
	}
	for (i = 0; s2[i] != '\0'; ++i)
	{
		if(s2[i]>='a' && s2[i] <= 'z')
			s2[i] -= 32;
	}

	i = 0;
	while (s1[i] != '\0' && (s1[i] == s2[i])){
	    i++;
	}
	if (s1[i] > s2[i]) {
	    result = '>';
	} else if (s1[i] < s2[i]) {
	    result = '<';
	} else{
	    result = '=';
	};
	cout << result;
}