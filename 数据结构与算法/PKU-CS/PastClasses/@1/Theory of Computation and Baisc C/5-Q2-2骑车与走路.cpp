#include <iostream>

using namespace std;
//骑车与走路
int main(){
    int nSize;
    double timeWalk, timeBike;
    cin >> nSize;
    int distance[nSize];

    for(int i = 0; i < nSize; i++){
        cin >> distance[i];
    }

    for(int i = 0; i < nSize; i++){
        timeWalk = distance[i] / 1.2;
        timeBike = distance[i] / 3.0 + 50;
        if(timeWalk > timeBike)
            cout << "Bike" << endl;
        else if(timeWalk < timeBike)
            cout << "Walk" << endl;
        else
            cout << "All" << endl;
    }

    return 0;
}
