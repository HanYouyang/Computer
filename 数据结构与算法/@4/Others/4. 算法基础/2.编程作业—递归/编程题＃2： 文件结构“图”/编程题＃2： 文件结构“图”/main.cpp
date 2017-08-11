
#include <iostream>
#include<string>
#include<algorithm>


using namespace std;
int layer= 0; //层数
string s[200];
string r[200];
int a = 0; //s数组的下标
int b = 0; //rank排序数组的下标；
int num = 1; //测试组数
int cintotal = 0; //用来判断输出头的序号


void print() {
    for( int i = 0; i < layer; i++){
        cout << "|     ";
    }
}


void process (){
    while(cin.peek() != '#'){
        if(cintotal == 0){
            if(num == 1){
                cout <<"DATA SET " << num <<":"<< endl;
                cout <<"ROOT" << endl;
            }
            if(num > 1){
                cout << endl;
                cout <<"DATA SET " << num <<":"<< endl;
                cout <<"ROOT" << endl;

            }
        }

        
        
        if(cin.peek() == 'd'){
            getline(cin,s[a]);
            layer++;
            print();
            cout << s[a] << endl;;
            a++;
            cintotal++;
        }
        
        if(cin.peek() == 'f'){
            getline(cin,s[a]);
            a++;
            cintotal++;
        }
        
        if(cin.peek() == ']'){
            string tem;
            getline(cin,tem) ;
            a--;
            while(s[a][0] != 'd'){
                r[b] = s[a];
                b++;
                a--;
            }
            if(b>0){
                sort(r,r+b);
                for(int i = 0; i < b; i++){
                    print();
                    cout<< r[i] << endl;
                }
            }
            b = 0;
            layer--;
            cintotal++;
        }
    
        if(cin.peek() == '*') {
            string tem;
            getline(cin,tem);
            a--;
            while(a >= 0){
                r[b] = s[a];
                b++;
                a--;
            }
            if(b >0){
                sort(r,r+b);
                for(int i = 0; i < b ; i++){
                    print();
                    cout<< r[i] << endl;
                }
            }
            a = 0;
            layer= 0;
            b = 0;
            num++;
            cintotal = 0;
        }
    }
    
}


int main(){
    
    process();
    
    return 0;
}

