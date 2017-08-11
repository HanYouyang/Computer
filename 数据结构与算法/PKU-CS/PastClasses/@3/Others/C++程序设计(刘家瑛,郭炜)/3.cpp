#include<iostream>
#include<iomanip>
#include<string>
using namespace std;

class headquarters {
    public:    
        headquarters(const int theLifeValue, const int theRedOrBlue, const int theWarriorValue[], 
		const string theWarriorNames[], const int order[], const string theHeadquarterNames[]);
    
        ~headquarters() {};

        // 获取生命值，用于在main程序中与各战士的最小生命值比较，以及与战士生命值的比较
        int getLifeValue() { return lifeValue; };

        // 获取将要出生的战士的生命值
        int getWarriorValue(int position) { return warriorValues[position]; };

        void product(int time, int position);
    
    private:
        int lifeValue;
        int redOrBlue; // 红色总部值为0，蓝色总部值为1
        int count; // 生产的战士数量
        int warriorCounts[5]; // 记录每种战士数量的数组
        string headquarterName; // 总部的名字
        string warriorNames[5]; // 记录每种战士名字的数组
        int warriorValues[5]; // 记录每种战士生命值的数组

};
/**
 * 指定初始化
 */
headquarters::headquarters(const int theLifeValue, const int theRedOrBlue, const int theWarriorValue[], 
const string theWarriorNames[], const int order[], const string theHeadquarterNames[]) {
    count = 0;
    lifeValue = theLifeValue;
    redOrBlue = theRedOrBlue;
    headquarterName = theHeadquarterNames[redOrBlue]; // 从总部名字的数组取得该总部的名字
    for (int i = 0; i < 5; ++i) {
        warriorCounts[i] = 0;
        warriorNames[i] = theWarriorNames[order[i]]; // 由给定的顺序和原始战士名字的数组，得到该总部战士名字的数组
        warriorValues[i] = theWarriorValue[order[i]]; // 由给定的顺序和原始战士名字的数组，得到该总部战士生命值的数组
    }
}
/**
     * 生产战士
     * time参数给定战士出生的回合
     * position参数给定该战士在司令部出生战士中的位置
     */
void headquarters::product(int time, int position) {
    count++;
    warriorCounts[position]++; // 该种战士的总数加一
    // 输出题目要求的语句
    cout << setfill('0')<<setw(3) << time << " " << headquarterName << " " << warriorNames[position]
    << " " << count << " born with strength " << warriorValues[position] << "," << warriorCounts[position]
    << " " << warriorNames[position] << " in " << headquarterName << " headquarter" << endl;
    lifeValue -= warriorValues[position];
}

int main() {
    const int redOrder[5] = {2, 3, 4, 1, 0}; // 红色总部的出兵顺序
    const int blueOrder[5] = {3, 0, 1, 2, 4}; // 蓝色总部的出兵顺序
    const string headquartersNames[2] = {"red", "blue"}; // 记录总部名字的数组
    const string priorNames[5] = { "dragon", "ninja", "iceman", "lion", "wolf" }; // 记录战士名字的数组
    int n = 0; // 测试数
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int priorValue[5], headquartersValue, minValue, redPosition = 0, bluePosition = 0;
        bool redHadStop = false, blueHadStop = false;

        cin >> headquartersValue; // 获取总部生命值
        // 获取每种战士的生命值
        for (int j = 0; j < 5; j++) {
            cin >> priorValue[j];
        }
        
        cout << "Case:" << i << endl;
        // 计算出战士中的最小生命值
        minValue = priorValue[0];
        for (int j = 1; j < 5; j++) {
            if (priorValue[j] < minValue) {
                minValue = priorValue[j];
            }
        }
        // 初始化红军总部和蓝军总部
        headquarters redOne = headquarters(headquartersValue, 0, priorValue, priorNames, redOrder, headquartersNames);
        headquarters blueOne = headquarters(headquartersValue, 1, priorValue, priorNames, blueOrder, headquartersNames);

        for (int time = 0;!redHadStop || !blueHadStop; time++) {
            // 如果红军没有停止出兵，继续
            if (!redHadStop) {
                // 红军的生命值小于最小战士生命值， 停止出兵，打印命令
                if (redOne.getLifeValue() < minValue) {
                    cout << setfill('0')<<setw(3) << time << " red headquarter stops making warriors" << endl;
                    redHadStop = true;
                }
                else {
                    // 从上面的判断句筛选后，现在一定能出兵。
                    // 从当前position开始增加，到某个位置出兵了停止
                    while (true) {
                        if (redOne.getLifeValue() >= redOne.getWarriorValue(redPosition)) {
                            redOne.product(time, redPosition);
                            if (redPosition == 4 ? redPosition = 0: redPosition++);
                            break;
                        }
                        else {
                            if (redPosition == 4 ? redPosition = 0: redPosition++);
                        }
                    }
                }
            }
            
            if (!blueHadStop) {
                if (blueOne.getLifeValue() < minValue) {
                    cout << setfill('0')<<setw(3)<< time << " blue headquarter stops making warriors" << endl;
                    blueHadStop = true;
                }
                else {
                    while (true) {
                        if (blueOne.getLifeValue() >= blueOne.getWarriorValue(bluePosition)) {
                            blueOne.product(time, bluePosition);
                            if (bluePosition == 4 ? bluePosition = 0: bluePosition++);
                            break;
                        }
                        else {
                            if (bluePosition == 4 ? bluePosition = 0: bluePosition++);
                        }
                    }
                }
            }            
        }        
    }    
    return 0;
}
