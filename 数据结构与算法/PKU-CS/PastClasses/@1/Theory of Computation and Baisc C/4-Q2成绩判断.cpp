#include <iostream>

using namespace std;

int main(){
    int mark;

    cin >> mark;

    if(mark >= 95 && mark <= 100){
        cout << "1" << endl;
    }else if(mark >= 90 && mark < 95){
        cout << "2" << endl;
    }else if(mark >= 85 && mark < 90){
        cout << "3" << endl;
    }else if(mark >=80 && mark < 85){
        cout << "4" << endl;
    }else if(mark >= 70 && mark < 80){
        cout << "5" << endl;
    }else if(mark >= 60 && mark < 70){
        cout << "6" << endl;
    }else if(mark < 60){
        cout << "7" << endl;
    }else{
        cout << "Invalid Input" << endl;
    }

    return 0;
}

