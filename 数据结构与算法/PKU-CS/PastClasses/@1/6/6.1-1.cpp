#include <iostream>
#include <math.h>
using namespace std;
int main(int argc, char const *argv[]) {
  int n, x, y, ans;
  cin >> n >> x >> y;
  ans = n - ceil(double(y) / x);
  if (ans < 0) {
    ans = 0;
  }
  cout << ans << endl;
  return 0;
}
