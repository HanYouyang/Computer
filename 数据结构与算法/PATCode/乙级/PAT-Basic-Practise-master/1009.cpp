#include<stdio.h>
#include<string.h>  
int main()  
{  
    char s1[81], s2[81];  
    gets(s1);  
    int len;  
    *s2 = 0;  
    len=strlen(s1);  
    for(; len>=0; len--){  
        if( *(s1+len)==' '){  
            *(s1+len)=0;  
            strcat(s2,(s1+len+1));  
            strcat(s2," ");
        }  
    }
    strcat(s2,s1);  
    puts(s2);  
}
