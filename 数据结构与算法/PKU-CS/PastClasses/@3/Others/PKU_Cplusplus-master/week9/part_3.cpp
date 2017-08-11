#include <iostream>
#include <set>
#include <string>
using namespace std;

typedef multiset<int> MSET;
int main()
{
    MSET current;
    MSET history;
    MSET::iterator IT;
    int tmp, isInSet, counter;
    string cmd;
    int n;
    cin >> n;
    for (int i=0; i<n; ++i){
        cin >> cmd;
        if (cmd == "add"){
            cin >> tmp;
            current.insert(tmp);
            history.insert(tmp);
            counter = current.count(tmp);
            cout << counter << endl;
        } else if(cmd == "del"){
            cin >> tmp;
            counter = current.count(tmp);
            cout << counter << endl;
            while (true){
                IT = current.find(tmp);
                if(IT!=current.end()) current.erase(IT);
                else break;
            }

        } else if(cmd == "ask"){
            cin >> tmp;
            IT = history.find(tmp);
            isInSet = (IT == history.end()) ? 0 : 1;
            counter = current.count(tmp);
            cout << isInSet << " " << counter << endl;
        }

    }
    return 0;

}