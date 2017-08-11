#include "iostream"
#include <stdio.h>
using namespace std;
//LL 0, LV 1, VL 2, VV 3
int n, k;
int LLnum, LVnum, VLnum, VVnum;
long long answer;
long long saved[4][20000];

int find_index(int LLnum_, int LVnum_, int VLnum_, int VVnum_){
	return LLnum_ * (LVnum + 1) * (VLnum + 1) * (VVnum + 1) + LVnum_ * (VLnum + 1) * (VVnum + 1)
	+ VLnum_ * (VVnum + 1) + VVnum_;
}

int char2int(char c1, char c2) {
	return (c1 == 'V') * 2+ (c2 == 'V');
}

void reset() {
	LLnum = LVnum = VLnum = VVnum = 0;
	answer = 0;
	for (int i = 0; i < 4; ++i)
		for (int j = 0; j < 20000; ++j)
				saved[i][j] = -1;
}
long long dp(int LLnum, int LVnum, int VLnum, int VVnum, int goal, int k) {
	long long result;
	if (LLnum < 0 || LVnum < 0 || VLnum < 0 || VVnum < 0 || k <= 0)
		return 0;
	if (saved[goal][find_index(LLnum, LVnum, VLnum, VVnum)] != -1)
		return saved[goal][find_index(LLnum, LVnum, VLnum, VVnum)];
	if (k == 1) {
		switch (goal) {
		case 0: return LLnum != 0; break;
		case 1: return LVnum != 0; break;
		case 2: return VLnum != 0; break;
		case 3: return VVnum != 0; break;
		}
	}
	switch (goal) {
	case 0: result = dp(LLnum - 1, LVnum, VLnum, VVnum, 0, k - 1) + dp(LLnum, LVnum, VLnum - 1, VVnum, 1, k - 1); break;
	case 1: result = dp(LLnum, LVnum - 1, VLnum, VVnum, 0, k - 1) + dp(LLnum, LVnum, VLnum, VVnum - 1, 1, k - 1); break;
	case 2: result = dp(LLnum - 1, LVnum, VLnum, VVnum, 2, k - 1) + dp(LLnum, LVnum, VLnum - 1, VVnum, 3, k - 1); break;
	case 3: result = dp(LLnum, LVnum - 1, VLnum, VVnum, 2, k - 1) + dp(LLnum, LVnum, VLnum, VVnum - 1, 3, k - 1); break;
	}
	saved[goal][find_index(LLnum, LVnum, VLnum, VVnum)] = result;
	return result;
}

int main(int argc, char const *argv[])
{
	int goal; //LLnum, LVnum, VLnum, VVnum;
	char c1, c2;
	while (cin >> n >> k) {
		reset();
		cin >> c1 >> c2;
		goal = char2int(c2, c1); //相反
		for (int i = 0; i < n; ++i)
		{
			cin >> c1 >> c2;
			switch (char2int(c1, c2)) {
			case 0: LLnum++; break;
			case 1: LVnum++; break;
			case 2: VLnum++; break;
			case 3: VVnum++; break;
			}
		}
		answer = dp(LLnum, LVnum, VLnum, VVnum, goal, k);
		if (answer)
			cout << "YES" << endl << answer << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}