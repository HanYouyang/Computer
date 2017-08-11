#include <iostream>
using namespace std;

int main(){
    int start, end, sum = 0;
    cin >> start;
    cin >> end;

    if(end >=  start && start >= 0 && end <= 300){
        for(int i = start; i < end + 1; i++){
            if(i % 2 != 0){
                sum += i;
            }
        }
        cout << sum << endl;
    }else{
        cout << "Invalid Input" << endl;
    }

    return 0;
}
