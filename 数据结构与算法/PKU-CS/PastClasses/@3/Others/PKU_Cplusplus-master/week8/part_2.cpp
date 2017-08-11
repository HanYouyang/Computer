#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <cstdlib>
#include <cstring>
#include <cstdio>
using namespace std;

vector<string> strInput;
queue<string> cmd;
char* itoa1 = new char[101];

void pushToQueue(const char *ch);
bool Process();
string Operation();
string MyCopy(int n, int x, int l);
string MyAdd(string s1, string s2);
int MyFind(int n, string s);
int MyRfind(int n, string s);
void MyInsert(int n, int x, string s);
void MyReset(int n, string s);
void MyPrint(int n);
void PrintAll();

void pushToQueue(const char *ch) {
    string str;
    for (int i = 0; ch[i] != '\0'; i++) {
        if (ch[i] != ' ') {
            str.push_back(ch[i]);
        }
        else {
            cmd.push(str);
            str.clear();
        }
    }

    cmd.push(str);
}

bool Process()
{
    string str = cmd.front();
    cmd.pop();
    if (str == "insert") {
        string s = Operation();
        int n = atoi(Operation().c_str());
        int x = atoi(Operation().c_str());
        MyInsert(n, x, s);
    }
    else if (str == "reset") {
        string s = Operation();
        int n = atoi(Operation().c_str());
        MyReset(n, s);
    }
    else if (str == "print") {
        int n = atoi(Operation().c_str());
        MyPrint(n);
    }
    else if (str == "printall") {
        PrintAll();
    }
    else if (str == "over") {
        return false;
    }
    return true;
}

string Operation() {
    string str = cmd.front();
    cmd.pop();
    if (str == "copy") {
        int n = atoi(Operation().c_str());
        int x = atoi(Operation().c_str());
        int l = atoi(Operation().c_str());
        return MyCopy(n, x, l);
    }
    else if (str == "add") {
        string s1 = Operation();
        string s2 = Operation();
        return MyAdd(s1, s2);
    }
    else if (str == "find") {
        string s = Operation();
        int n = atoi(Operation().c_str());
        sprintf(itoa1, "%d", MyFind(n, s));
        return itoa1;
    }
    else if (str == "rfind") {
        string s = Operation();
        int n = atoi(Operation().c_str());
        sprintf(itoa1, "%d", MyRfind(n, s));
        return itoa1;
    }
    else {
        return str;
    }

}

string MyCopy(int n, int x, int l) {
    string str = strInput.at(n-1);
    return str.substr(x, l);
}

string MyAdd(string s1, string s2) {
    for (int i = 0; i < s1.size(); i++) {
        if (s1.at(i) < '0' || s1.at(i) > '9') {
            return s1 + s2;
        }
    }
    for (int i = 0; i < s2.size(); i++) {
        if (s2.at(i) < '0' || s2.at(i) > '9') {
            return s1 + s2;
        }
    }
    long a = atoi(s1.c_str());
    long b = atoi(s2.c_str());
    if (a >= 0 && a <= 99999 && b >= 0 && b <= 99999) {
        long c = a + b;
        sprintf(itoa1, "%d", c);
        return itoa1;
    }
    else {
        return s1 + s2;
    }
}

int MyFind(int n, string s) {
    int pos = strInput.at(n-1).find(s);
    if (pos == string::npos) {
        return s.size();
    }
    else {
        return pos;
    }
}

int MyRfind(int n, string s) {
    int pos = strInput.at(n-1).rfind(s);
    if (pos == string::npos) {
        return s.size();
    }
    else {
        return pos;
    }
}

void MyInsert(int n, int x, string s) {
    strInput.at(n-1).insert(x, s);
}

void MyReset(int n, string s) {
    strInput.at(n-1).swap(s);
}

void MyPrint(int n) {
    cout << strInput.at(n-1) << endl;
}

void PrintAll() {
    for (unsigned int i = 0; i < strInput.size(); i++) {
        cout << strInput.at(i) << endl;
    }

}

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        strInput.push_back(str);
    }
    cin.get();

    char* ch = new char[501];
    while(1) {
        cin.getline(ch, 500, '\n');
        pushToQueue(ch);
        int t = Process();
        if (t == false) {
            break;
        }
    }
    delete ch;
    delete itoa1;
    return 0;
}

