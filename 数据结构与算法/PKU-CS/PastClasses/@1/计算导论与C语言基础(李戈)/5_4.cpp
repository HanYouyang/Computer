# include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x, ans = 0;
        cin >> x;
        while (x > 0) {
            ans += x % 2;
            x /= 2;
        }
        cout << ans << endl;
    }
    return 0;
}
//�����Ľⷨ���Ƿ����س���2�������λ��1����0����Щ֪��λ�����ͬѧϲ����λ���㣬����ʵû��Ҫ����Ϊ�������Ż�֮��ĳ�����ʵЧ����һ���ġ�
