#include <iostream>
using namespace std;

// Max 300 monkeys
int succedent[300]; // Use this array to store last monkey
//"next[5] equals 7" means number 5's nexy s number 7. Number 6 qute
int precedent[300]; // Use this array to store the monkey before that.

int main() {
  /* code */
  int n, m;
  while (true) {
    cin >> n >> m;
    if (n == 0 && m == 0)
      break;
    for (int i = 0; i < n - 1; i++) {
      succedent[i] = i + 1;
      precedent[i + 1] = i;
    }
    succedent[n - 1] = 0;
    precedent[0] = n - 1;

    int current = 0;
    while (true) {
      // if must m times, the m-1 times succedent is the monkey
      for (int count = 0; count < m - 1; count++)
        current = succedent[current];

      int pre = precedent[current];
      int suc = succedent[current];
      // let current monkey leave is let before one point to after one.
      // Also let next one's before one point the current before one.
      succedent[pre] = suc;
      precedent[suc] = pre;
      if (pre == suc) {
        cout << pre + 1 << endl;
        break;
      }
      current = suc;
    }
  }

  return 0;
}
