#include <iostream>
using namespace std;
//约瑟夫问题：有ｎ只猴子，按顺时针方向围成一圈选大王（编号从１到ｎ），从第１号开始报数，一直数到ｍ
//数到ｍ的猴子退出圈外，剩下的猴子再接着从1开始报数。就这样，直到圈内只剩下一只猴子时，这个猴子就是猴王
//编程求输入ｎ，ｍ后，输出最后猴王的编号。
int main(){
    int nSize = 0, nMonkey[300], nKing[300], aLoop[300];
    bool bInputFlag = false;

    while(nSize <= 300 && bInputFlag == false){
        cin >> nMonkey[nSize] >> nKing[nSize];
        if(nMonkey[nSize] == 0 && nKing[nSize] == 0){
            bInputFlag = true;
        }else{
            nSize += 1;
        }
    }

    for(int j = 0; j < nSize; j++){
        for(int i = 0; i < nMonkey[j]; i++)
            aLoop[i] = i + 1;

        int nPtr = 0;

        for(int i = 0; i < nMonkey[j]; i++){
            int nCount = 0;
            while(nCount < nKing[j]){
                while(aLoop[nPtr] == 0)
                    nPtr = (nPtr + 1)%nMonkey[j];
                nCount++;
                nPtr =(nPtr + 1)%nMonkey[j];
            }
            nPtr--;
            if(nPtr < 0)
                nPtr = nMonkey[j] - 1;
            if(i == nMonkey[j] - 1)
                cout << aLoop[nPtr] << endl;
            aLoop[nPtr] = 0;
        }
    }

    return 0;
}
