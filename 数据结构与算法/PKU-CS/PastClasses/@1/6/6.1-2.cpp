#include <iostream>
using namespace std;
int main() {
  int h, r, numbers;
  cin >> h >> r;
  numbers = (20000 / (h * r * r * 3.14)) + 1;
  cout << numbers << endl;

  return 0;
}
