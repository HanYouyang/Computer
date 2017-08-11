#include <iostream>
#include <cstring>
#include <string.h>
#include <stdio.h>
#include <memory.h>
#include <vector>
#include <algorithm>
using namespace std;

class bigint {
    vector<int> v;
    int pon; //positive or negative
public:
    bigint(string);
    void addZero(int a);
    void minusZero ();
    void print();
    friend int bigger(bigint& B1, bigint& B2);
    friend bigint operator+ (bigint & B1, bigint & B2 );
    friend bigint operator- (bigint & B1, bigint & B2 );
    friend bigint mul(bigint& B, int);
    friend bigint operator* (bigint & B1, bigint & B2 );
    friend bigint operator/ (bigint & B1, bigint & B2 );
};

bigint:: bigint(string s){
    if(s != ""){
        for( int i = s.length() - 1; i >= 0; i--){
            v.push_back(s[i] - '0');
        }
    }
    pon = 1;
}

void bigint:: print(){
    string s = "";
    for (int i = v.size() - 1; i >= 0; i--) {
        s += v[i]+'0';
    }
    if (pon == 0) {
        cout << '-';
    }
    cout << s << endl;
    
}

bigint operator+ (bigint& b1, bigint& b2){
    string sum_s;
    for( int i = 0; i < max(b1.v.size(),b2.v.size()); i++){
        sum_s += '0';
    }
    bigint sum(sum_s);
    int tem = 0;
    int temsum = 0;
    for( int i = 0; i <max(b1.v.size(),b2.v.size()); i++){
        temsum = 0;
        if (i < b1.v.size()) {
            temsum += b1.v[i];
        }
        if (i < b2.v.size()) {
            temsum += b2.v[i];
        }
        temsum += tem;
        tem = 0;
        if(temsum >= 10){
            tem = temsum /10;
            temsum = temsum % 10;
        }
        sum.v[i] = temsum;
    }
    if(tem > 0 ){
        sum.v.push_back(tem);
    }
    return sum;
}


int bigger(bigint& b1, bigint& b2){
    if(b1.v.size() < b2.v.size()){
        return 0;
    }
    if (b1.v.size() == b2.v.size()) {
        for(int i = b1.v.size() -1; i >= 0; i--){
            if (b1.v[i] > b2.v[i]) {
                return 1;
            }
            if (b1.v[i] < b2.v[i]) {
                return 0;
            }
        }
    }
    
    return 1;
}


void bigint::  minusZero (){    //去前面的0
    int i = v.size()-1;
    while (v[i] == 0 && i > 0) {
        v.pop_back();
        i--;
    }
}


bigint operator- (bigint& b1, bigint& b2){
    string minus_s;
    for( int i = 0; i < max(b1.v.size(),b2.v.size()); i++){
        minus_s += '0';
    }
    bigint minus(minus_s);
    if(bigger(b1,b2)){
        int tem = 0;
        int temminus = 0;
        for( int i = 0; i < b1.v.size(); i++){
            if(i < b2.v.size()){
                if(b1.v[i] - tem - b2.v[i] >= 0){
                    temminus = b1.v[i] - tem - b2.v[i];
                    tem = 0;
                }
                else{
                    temminus = 10 + b1.v[i] - tem - b2.v[i];
                    tem = 1;
                }
            }
            else{
                if (b1.v[i] - tem >= 0) {
                    temminus = b1.v[i] - tem;
                    tem = 0;
                }
                else{
                    temminus = 10 + b1.v[i] - tem;
                    tem = 1;
                }
                
            }
            minus.v[i] = temminus;
        }
    }
    else{
        minus.pon = 0;
        int tem = 0;
        int temminus = 0;
        for( int i = 0; i < b2.v.size(); i++){
            if(i < b1.v.size()){
                if(b2.v[i] - tem - b1.v[i] >= 0){
                    temminus = b2.v[i] - tem - b1.v[i];
                    tem = 0;
                }
                else{
                    temminus = 10 + b2.v[i] - tem - b1.v[i];
                    tem = 1;
                }
            }
            else{
                if (b2.v[i] - tem >= 0) {
                    temminus = b2.v[i] - tem;
                    tem = 0;
                }
                else{
                    temminus = 10 + b2.v[i] - tem;
                    tem = 1;
                }
                
            }
            minus.v[i] = temminus;
        }
    }
    minus.minusZero();
    return minus;
}


bigint mul(bigint& b,int a){
    bigint r(b);
    int tem = 0;
    int temmul = 0;
    for(int i = 0; i <b.v.size(); i++){
        temmul = 0;
        temmul = b.v[i] * a + tem;
        tem = temmul /10;
        temmul = temmul % 10;
        r.v[i] = temmul;
    }
    if (tem > 0) {
        r.v.push_back(tem);
    }
    return r;
}

void bigint:: addZero(int j){
    if (j >= 0){
        for( int i = 0; i <j; i++){
            v.insert(v.begin(), 0);
        }
    }
    else{
        for (int i = 0; i < -j; i++){
            v = vector<int>(v.begin()+1,v.end());
        }
    }
}

bigint operator* (bigint& b1, bigint& b2){
    bigint rd("");
    bigint temp("");
    for( int i = 0; i < b2.v.size(); i++){
        temp = mul(b1,b2.v[i]);
        temp.addZero(i);
        rd = rd + temp;
    }
    return rd;
    
}



bigint operator/ (bigint& b1, bigint& b2){
    string div_s;
    for( int i = 0; i < max(b1.v.size(),b2.v.size()); i++){
        div_s += '0';
    }
    bigint div(div_s);
    if (bigger(b1, b2) ) {
        bigint tem("");
        for(int j = b1.v.size() - 1; j >= 0; j--){
            tem.v.insert(tem.v.begin(), b1.v[j]);
            if(bigger(tem, b2)){
                for (int z = 1; z < 10; z++) {
                    tem = tem - b2; 
                    if (bigger(tem, b2) == 0) {
                        div.v[j] = z ;
                        break;
                    }
                }
            }
            else{
                div.v[j] = 0;
            }
        }
    }
    div.minusZero();
    
    return div;
}



int main() {
    string s1;
    string s2;
    char o;
    cin >> s1 >> o >> s2;
    
    bigint b1 (s1);
    bigint b2 (s2);
    
    if (o == '-') {
        (b1 - b2).print();
    }
    if (o == '+') {
        (b1 + b2).print();
    }
    if (o == '*') {
        (b1 * b2).print();
    }
    if (o == '/') {
        (b1 / b2).print();
    }
    
    return 0;
}
