#include <iostream>
using namespace std;

int horizontal(int n);
int vertical(int n);

int count(int n) {
    if (n == 0) return 1;
    if(n % 2) return 0;
    return horizontal(n)+vertical(n);
}

int horizontal(int n) {
    if (n == 0) return 1;
    if (n == 1) return 0;
    return 2 * vertical(n-1) + horizontal(n-2);
}

int vertical(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return horizontal(n-1) + vertical(n-2);
}

int main()
{
    int n;
    cin >> n;
    while (n != -1) {
        cout<<count(n);
        cin>>n;
        if (n != -1) cout<<endl;
    }
    return 0;
}