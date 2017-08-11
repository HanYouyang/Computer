#include <iostream>
#include <list>
#include <algorithm>
using namespace std;
int main(){
    int a[5] = {1,2,3,4,5};
    list<int>lst(a,a+5);
    list<int>::iterator p =lst.begin();
    advance(p,2);
    cout <<"1)"<< *p << endl;
    advance(p, -1);
    cout <<"2)"<< *p << endl;
    list<int>::iterator q = lst.end();
    q--;
    cout <<"3)"<< distance(p, q)<<endl;
    iter_swap(p, q);
    cout <<"4)";
    for(p = lst.begin();p != lst.end(); ++p)
        cout << *p << " ";
    return 0;
}