#include<iostream>
using namespace std;
//字符串中次数第2多的字母
struct charStatus{
    char ch;
    int count;
};

 int main(){
     struct charStatus s[501], max, second;
     char input[501];
     cin >> input;
     int i, j, k = 0;

     for(i = 0; input[i] != '\0'; i++){
         if((input[i] >= 'A' && input[i] <= 'Z') || (input[i] >= 'a' && input[i] <= 'z')){
             char temp;
             if(input[i] >= 'a')
                 temp = input[i] - 32;
             else
                 temp = input[i];
             bool found = false;
             for(j = 0; j < k; j++){
                 if(s[j].ch == temp){
                     s[j].count++;
                     found = true;
                 }
             }
             if(!found){
                 s[k].ch = temp;
                 s[k].count = 1;
                 k++;
             }
         }
     }

     max = s[0];
     bool foundSecond = false;
     i = 0;

     while(!foundSecond){
         if(s[i].count > max.count){
             second = max;
             max = s[i];
             foundSecond = true;
         }
         else if(s[i].count < max.count){
             second = s[i];
             foundSecond = true;
         }
         i++;
     }

     for(i; i < k - 1; i++){
         if(s[i].count > max.count){
             second = max;
             max = s[i];
         }else if(s[i].count < max.count && s[i].count > second.count){
             second = s[i];
         }
     }

     cout << second.ch << "+" << (char)(second.ch+32) << ":" << second.count;
     return 0;
}
