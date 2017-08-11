#include "iostream"
using namespace std;
int foo(int remain, int number) {
	if (remain - 1 < number)
		return 0;
	if ((remain - 1) % number != 0)
		return 0;
	return (remain - 1) / number * (number - 1);
}
int main(int argc, char const *argv[])
{
	int result;
	int remain;
	int N;
	int remainN;
	while (cin >> N) {
		if (N == 0)
			break;
		result = 1;
		while (result) {
			remain = result;
			remainN = N;
			while (remain > 0 && remainN > 0) {
				remain = foo(remain, N);
				if (remain <= 0)
					break;
				remainN--;
			}
			if (remainN == 0) {
				cout << result << endl;
				break;
			}
			result += N;
		}
	}

	return 0;
}