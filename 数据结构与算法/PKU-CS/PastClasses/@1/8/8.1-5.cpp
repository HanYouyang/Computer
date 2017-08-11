#include <iostream>
using namespace std;
int main() {
  int n;
  int total = 0;
  cin >> n;
  for (int i = 10; i < n; i++) {
    int n1 = 0, n2 = 0, n3 = 0;
    n1 = i / 100;
    n2 = (i - n1 * 100) / 10;
    n3 = (i - n1 * 100 - n2 * 10) / 1;
    total = n1 + n2 + n3;
    if (i % total == 0)
      cout << i << endl;
  }

  return 0;
}
