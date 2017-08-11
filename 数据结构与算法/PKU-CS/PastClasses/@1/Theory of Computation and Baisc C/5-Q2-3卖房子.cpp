#include <iostream>
#include <math.h>
using namespace std;
//买房子,某程序员开始工作，年薪N万，他希望在中关村公馆买一套60平米的房子，
//现在价格是200万，假设房子价格以每年百分之K增长，并且该程序员未来年薪不变，且不吃不喝，不用交税，每年
//所得N万全都积攒起来，问第几年能够买下这套房子（第一年房价200万，收入N万）
int main(){
    int years = 0;
    int salary, rate;


    while(cin >> salary >> rate){

            while(years <= 20){
                years += 1;

                if(years <= 20 && (pow((1+0.01*rate),years-1) * 200) <= salary * years){
                    cout << years << endl;
                    break;
                }else if(years > 20 && (pow((1+0.01*rate),years-1) * 200) > salary * years){
                    cout << "Impossible" << endl;
                }

            }
            years = 0;

    }

    return 0;
}
