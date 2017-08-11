#include <iostream>
using namespace std;
int main() {
  int achive;
  int array[100];
  cin >> achive;
  for (int i = 0; i < achive; i++) {
    cin >> array[i];
  }
  for (int i = 0; i < achive; i++) {
    for (int j = 0; j < achive - i - 1; j++) {
      if (array[j + 1] > array[j]) {
        int tmpId = array[j];
        array[j] = array[j + 1];
        array[j + 1] = tmpId;
      }
    }
  }
  cout << array[0] << endl;

  return 0;
}
