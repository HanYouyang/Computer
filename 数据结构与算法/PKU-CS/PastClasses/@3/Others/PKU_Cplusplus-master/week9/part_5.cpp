#include <iostream>
#include <map>
#include <string>
using namespace std;

typedef map<int, int> MAP1;
typedef map<int, int, greater<int> > MAP2;
int main()
{
    MAP1 map1;
    MAP2 map2;
    MAP1::iterator IT1;
    MAP2::iterator IT2;
    map1[1000000000] = 1;
    map2[1000000000] = 1;
    int id, force, n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> id >> force;
        IT1 = map1.upper_bound(force);  //强的那个
        IT2 = map2.upper_bound(force);  //弱的那个

        if(IT2 == map2.end()){
            cout << id << " " << IT1->second << endl;
        } else if(IT1 == map1.end()){
            cout << id << " " << IT2->second << endl;
        } else{
            if((IT1->first - force) < (force - IT2->first)) cout << id << " " << IT1->second << endl;
            else cout << id << " " << IT2->second << endl;
        }
        map1[force] = id;
        map2[force] = id;
    }
    return 0;

}