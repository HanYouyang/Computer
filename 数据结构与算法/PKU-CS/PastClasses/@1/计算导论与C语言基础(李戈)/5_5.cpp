#include <iostream>
using namespace std;
int a[100];
int main() {
    int n;
    cin >> n;
    for (int i = 0; i<n; i++)
        cin >> a[i];
    while (n--) { //���õĵ������ѭ�����ȼ���while(n-->0)
        cout << a[n];
        if (n > 0) cout << " "; //����������һ������ô��Ҫ�ÿո�ָ���
    }
    return 0;
}
//˳�����뵹������������������Ҫ��ͨ���޸����鱾��ʵ�������ط�Ӧ����ô���أ�
