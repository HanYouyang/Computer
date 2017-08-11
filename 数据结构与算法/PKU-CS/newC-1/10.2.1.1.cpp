#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
template <class T>
void PrintVector(const vector<T> & v)
 {   typename vector<T>::const_iterator i;
    for(i = v.begin(); i != v.end(); ++i)
        cout << *i << " ";
    cout << endl;
 }
 int main(){
    int a[5] = {1,2,3,4,5};
    vector<int> v(a, a+5);
    cout << "1)" << v.end() - v.begin() << endl;
    cout << "2)"; PrintVector(v);
    v.insert(v.begin()+2, 13);
    cout << "3)"; PrintVector(v);
    v.erase(v.begin(), 2);
    cout << "4)"; PrintVector(v);
    vector<int> v2(4, 100);
    v2.insert(v2.begin(); v2.begin()+1, v2.begin()+3);
    cout << "5)v2:"; PrintVector(v2);
    v.erase(v.begin()+1;v.begin()+3);
    cout << "6)"; PrintVector(v);
    return 0;
 }