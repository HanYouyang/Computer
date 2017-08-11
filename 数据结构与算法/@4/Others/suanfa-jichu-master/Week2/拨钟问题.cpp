#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
 int station[9] = {0};
 for (int i = 0; i < 9; i++)
  cin>>station[i];
 int move_count[9] = {0};
 int min_count = 10000;
 for (int i1 = 0; i1 < 4; i1++)
  for (int i2 = 0; i2 < 4; i2++)
   for (int i3 = 0; i3 < 4; i3++)
    for (int i4 = 0; i4 < 4; i4++)
     for (int i5 = 0; i5 < 4; i5++)
      for (int i6 = 0; i6 < 4; i6++)
       for (int i7 = 0; i7 < 4; i7++)
        for (int i8 = 0; i8 < 4; i8++)
         for (int i9 = 0; i9 < 4; i9++)
         {
          if ((0 == (i1 + i2 + i4 + station[0]) % 4) && (0 == (i1 + i2 + i3 + i5 + station[1])
              % 4) && (0 == (i2 + i3 + i6 + station[2]) % 4) && (0 == (i1 + i4 + i5 + i7 +
              station[3]) % 4) && (0 == (i1 + i3 + i5 + i7 + i9 + station[4]) % 4) && (0 ==
              (i3 + i5 + i6 + i9 + station[5])% 4) && (0 == (i4 + i7 + i8 + station[6]) % 4)
          && (0 == (i5 + i7 + i8 + i9 + station[7])% 4) && (0 == (i6 + i8 + i9 + station[8]) % 4))
          {
           int sum = i1 + i2 + i3 + i4 + i5 + i6 + i7 + i8 + i9;
           if (min_count > sum)
           {
            min_count = sum;
            move_count[0] = i1;
            move_count[1] = i2;
            move_count[2] = i3;
            move_count[3] = i4;
            move_count[4] = i5;
            move_count[5] = i6;
            move_count[6] = i7;
            move_count[7] = i8;
            move_count[8] = i9;
           }
          }
         }
 int cur = 0;
 for (cur = 0; cur < 9; cur++)
  while (move_count[cur]--)
   cout<<cur + 1<<" ";
 cout<<endl;
 return 0;
}