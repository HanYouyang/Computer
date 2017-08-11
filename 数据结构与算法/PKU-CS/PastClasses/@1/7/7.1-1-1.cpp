#include "iostream"
#include <iomanip>
using namespace std;
int main(int argc, char const *argv[]) {
  int n;
  cin >> n;
  int age[n], agg[4] = {0};
  for (int i = 0; i < n; ++i) {
    cin >> age[n];
    if (age[n] <= 18)
      agg[0]++;
    else if (age[n] <= 35)
      agg[1]++;
    else if (age[n] <= 60)
      agg[2]++;
    else
      agg[3]++;
  }
  cout << "1-18: " << fixed << setprecision(2) << agg[0] / double(n) * 100
       << '%' << endl;
  cout << "19-35: " << fixed << setprecision(2) << agg[1] / double(n) * 100
       << '%' << endl;
  cout << "36-60: " << fixed << setprecision(2) << agg[2] / double(n) * 100
       << '%' << endl;
  cout << "60-: " << fixed << setprecision(2) << agg[3] / double(n) * 100 << '%'
       << endl;
  return 0;
}
