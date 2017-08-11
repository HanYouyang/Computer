#include <iostream>
#include <vector>
using namespace std;

void aToA(char in[]) {
    int i = 0;
    while (in[i] != '\0') {
        if (in[i] >= 'a' && in[i] <= 'z') {
            in[i] = in[i] - 32;
        }
        i = i + 1;
    }
}

void f(char in[], int out[]) {
    int i = 0;
    while (in[i] != '\0') {
        if (in[i] >= 'A' && in[i] <= 'Z') {
            out[in[i] - 65] = out[in[i] - 65] + 1;
        }
        i = i + 1;
    }
}

void Second(int in[], char out[]) {
    int maxcount = 0; 
    for (int i = 0; i < 26; i++) {
        if (maxcount < in[i]) {
            maxcount = in[i];
        }
    }
    for (int i = 0; i < 26; i++) {
        if (in[i] == maxcount) {
            in[i] = 0;
        }
    }
    int seccount = 0; 
    for (int i = 0; i < 26; i++) {
        if (seccount < in[i]) {
            seccount = in[i];
        }
    }
    int j = 0;
    for (int i = 0; i < 26; i++) {
        if (in[i] == seccount) {
            out[j] = i + 65;
            j = j + 1;
        }
    }
    out[j] = '\0';
}

int main() {
    char a[501];
    int count[26] = {0};
    char second[26];
    cin >> a;
    aToA(a);
    f(a, count);
    Second(count, second);

    int i = 0;
    while (a[i] != '\0') {
        int j = 0;
        while (second[j] != '\0') {
            if (a[i] == second[j]) {
                cout << second[j] << '+' << (char)(second[j]+32) << ':' << count[second[j]-65] << endl;
                return 0;
            }
            j = j + 1;
        }
        i = i + 1;
    }
    return 0;
}
