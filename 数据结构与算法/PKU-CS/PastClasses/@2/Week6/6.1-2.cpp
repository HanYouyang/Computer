#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

typedef struct patient {
    int number;
    float level;
};

int main() {
    int m = 0;
    float a = 0.0;
    cin >> m >> a;
    vector <patient> d(m);
    int number = 0;
    float level = 0.0;
    int n = 0;
    for (int i = 0; i < m; i++) {
        cin >> number >> level;
        if (level >= a) {
            d[n].number = number;
            d[n].level = level;
            n = n + 1;
        }
    }
    if (n == 0) {
        cout << "None." << endl;
        return 0;
    } else {
        for (int i = 0; i < n-1; i++) {
            for (int j = i+1; j < n; j++) {
                if (d[i].level < d[j].level) {
                    int tempnumber;
                    float templevel;
                    tempnumber = d[i].number;
                    templevel = d[i].level;
                    d[i].number = d[j].number;
                    d[i].level = d[j].level;
                    d[j].number = tempnumber;
                    d[j].level = templevel;
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        cout << setfill('0') << setw(3) << d[i].number << " ";
        cout << fixed << setprecision(1) << d[i].level << endl;
    }
    return 0;
}
