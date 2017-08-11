#include <iomanip>
#include <iostream>
using namespace std;
int main() {
  int num;
  cin >> num;

  if (num >= 95 && num <= 100)
    cout << "1" << endl;

  else if (num >= 90 && num < 95)
    cout << "2" << endl;

  else if (num >= 85 && num < 90)
    cout << "3" << endl;

  else if (num >= 80 && num < 85)
    cout << "4" << endl;

  else if (num >= 70 && num < 80)
    cout << "5" << endl;

  else if (num >= 60 && num < 70)
    cout << "6" << endl;

  else if (num < 60)
    cout << "7" << endl;

  return 0;
}
