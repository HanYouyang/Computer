#include <iostream>
#include <vector>
using namespace std;
int main(){
    vector<int> v(100);
    for(int i = 0; i <v.size(); ++i)
        cout << v[i];
    vector<int>::iterator i;
    for(i = v.begin(); i != v.end(); ++i)
        cout << *i;
    for(i = v.begin(); i < v.end(); ++i)
        cout << *i;
    i = v.begin();
    while(i < v.end()){
        cout << *i;
        i += 2;
    }
}