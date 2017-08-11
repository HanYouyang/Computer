#include <iostream>
#include  <stdio.h>
//某医院想统计一下某项疾病的获得与否与年龄是否有关，需要对以前的诊断记录进行整理。
using namespace std;

int main(){
    int nSize, StageOne = 0, StageTwo = 0, StageThree = 0, StageFour = 0;
    double pStageOne, pStageTwo, pStageThree, pStageFour;
    cin >> nSize;
    int age[nSize];

    for(int i = 0; i < nSize; i++){
        cin >> age[i];
    }

    for(int i = 0; i < nSize; i++){
        if(age[i] <= 18){
            StageOne += 1;
        }else if(age[i] >= 19 && age[i] <= 35){
            StageTwo += 1;
        }else if(age[i] >= 36 && age[i] <= 60){
            StageThree += 1;
        }else if(age[i] > 60){
            StageFour += 1;
        }
    }

    pStageOne = StageOne*1.0000 / nSize;
    pStageTwo = StageTwo*1.0000 / nSize;
    pStageThree = StageThree*1.0000 / nSize;
    pStageFour = StageFour*1.0000 / nSize;

    printf("1-18: %0.2f%%\n", pStageOne*100);
    printf("19-35: %0.2f%%\n", pStageTwo*100);
    printf("36-60: %0.2f%%\n", pStageThree*100);
    printf("60-: %0.2f%%\n", pStageFour*100);

    return 0;
}
