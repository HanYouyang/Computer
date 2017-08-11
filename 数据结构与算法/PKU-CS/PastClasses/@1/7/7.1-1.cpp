#include <iomanip>
#include <iostream>
using namespace std;
int main() {
  int n, n18 = 0, n35 = 0, n60 = 0, n99 = 0;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] <= 18)
      n18++;
    else if (a[i] <= 35)
      n35++;
    else if (a[i] <= 60)
      n60++;
    else
      n99++;
  }
  float n1 = n18 * 100 / n;
  float n2 = n35 * 100 / n;
  float n3 = n60 * 100 / n;
  float n4 = n99 * 100 / n;
  cout << "1-18: " << fixed << setprecision(2) << n1 << '%' << endl;
  cout << "19-35: " << fixed << setprecision(2) << n2 << '%' << endl;
  cout << "36-60: " << fixed << setprecision(2) << n3 << '%' << endl;
  cout << "60-: " << fixed << setprecision(2) << n4 << '%' << endl;
  return 0;
}
