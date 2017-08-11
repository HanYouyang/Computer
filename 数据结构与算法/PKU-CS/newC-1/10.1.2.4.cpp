#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
    int a[10] = {10, 20, 30 ,40};
    vector<int> v;
    v.push_back(1);v.push_back(2);
    v.push_back(3);v.push_back(4);
    vector<int>::iterator p;
    p = find(v.begin(), v.end(), 3);
    if(p != v.end())
        cout << "1)" << *p << endl;
    p = find(v.begin(), v.end(), 9);
    if(p == v.end())
        cout << "not found" << endl;
    p = find(v.begin()+1, v.end()-1, 4 );
    cout << "2)" << *p << endl;
    int *pp = find(a, a+4, 20);
        if(pp == a+4)
        cout << "not found" << endl;
    else
        cout << "3)" << *pp << endl;
}