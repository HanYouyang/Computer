#include <iostream>
#include <set>
#include <string>
#include <iterator>

using namespace std;

int main()
{   
    multiset<int> mset;
    set<int> mm;
    char commend[5];
    int i,n,num,amount;
    multiset<int>::iterator it;
    cin >> n;
    for (i=0; i<n; i++)
    {
        cin >> commend >> num;
        switch(commend[1])
        {
        case 'd': 
            mset.insert(num);
            mm.insert(num);
            cout << mset.count(num) << endl;
            break;                
        case 'e': 
            cout << mset.count(num) << endl;
            mset.erase(num);
            break;
        case 's': 
            if (mm.find(num)==mm.end())
                cout << "0 0" << endl;
            else
            {
                cout << "1 ";
                cout << mset.count(num) << endl;
            }
            break;
        }
    }
    return 0;
}
