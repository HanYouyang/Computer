#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;
int main(){
    char str[10], substr[3], output[14]={};
    char max = {0};
    int index = 0;
     while (cin >> str >> substr){

         for (int i = 0; str[i] != '\0'; i++){
            if (str[i] > max)
                max = str[i];
                index = i;
         }
         for (int i = 0; i < 14; ++i){
 			if (i < index + 1){
 				output[i] = str[i];
 			}
 			else if (i < index + 4){
 				output[i] = substr[i - index - 1];
 			}
 			else{
 				output[i] = str[i - 3];
 			}
 		}
 		cout << output << endl;
 	}

 }
