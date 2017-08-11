#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

//函数对象
class cmp {
public:
    bool operator()(string a, string b) {
        return a>b;
    }
};

void print(int deep, string s) {
    for(int i=0; i<deep; i++)
        cout << "|     ";
    cout << s << endl;
}


int fun(int deep, string s) {
    priority_queue<string, vector<string>, cmp> q;
    if (deep == 0) {
        cout << "ROOT" << endl;
        if (s[0] == 'f')
            q.push(s);
        if (s[0] == 'd')
            fun(deep+1, s);
        if (s[0]==']' || s[0]=='*') {
            while(!q.empty()) {
                print(deep, q.top());
                q.pop();
            }
            return 1;
        }
    }
    else print(deep, s);
    while(cin >> s) {
        if(s[0]=='f') q.push(s);
        if(s[0]=='d') fun(deep+1, s);
        if(s[0]==']' || s[0]=='*') {
            while(!q.empty()) {
                print(deep, q.top());
                q.pop();
            }
            if (s[0]=='*') cout << endl;
            return 1;
        }
    }
}


int main() {
    int t=0;
    while(1) {
        string s;
        cin >> s;
        if (s[0] == '#') 
            return 0;
        t++;
        cout << "DATA SET " << t << ':' << endl;
        fun(0, s);
    }
    return 0;
}