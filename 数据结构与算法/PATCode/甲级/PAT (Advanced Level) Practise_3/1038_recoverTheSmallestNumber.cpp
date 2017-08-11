//2016年2月18日22时46分31秒
//2016年2月18日
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

const int maxn = 10010;
string str[maxn];

//字符串中的a+b代表a与b拼接（a在前）
bool cmp(string a, string b){
	return a + b < b + a;
}

int main()
{
	int n;
	cin >> n;
	for(int i = 0; i < n; i++) cin >> str[i];
	sort(str, str + n, cmp);
	string ans;
	for(int i = 0; i < n; i++) ans += str[i];
	//ans.begin()返回的是起始元素的位置
	while(ans.size() && ans[0] == '0') ans.erase(ans.begin());
	if(ans.size() == 0) cout << 0;
	else cout << ans;
	return 0;
}
