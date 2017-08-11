#include <iostream>
using namespace std;
int main() {
  /* code */
  int n[3];
  int inpnum;
  cin >> inpnum;
  n[0] = inpnum / 100;
  n[1] = (inpnum - 100 * n[0]) / 10;
  n[2] = (inpnum - 100 * n[0] - 10 * n[1]) / 1;
  for (int i = 0; i < 3; i++) {
    /* code */
    cout << n[i] << endl;
  }
  return 0;
}
