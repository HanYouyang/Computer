#include<iostream>
#include<iomanip>
#include<string>
using namespace std;

class headquarters {
    public:    
        headquarters(const int theLifeValue, const int theRedOrBlue, const int theWarriorValue[], 
		const string theWarriorNames[], const int order[], const string theHeadquarterNames[]);
    
        ~headquarters() {};

        // ��ȡ����ֵ��������main���������սʿ����С����ֵ�Ƚϣ��Լ���սʿ����ֵ�ıȽ�
        int getLifeValue() { return lifeValue; };

        // ��ȡ��Ҫ������սʿ������ֵ
        int getWarriorValue(int position) { return warriorValues[position]; };

        void product(int time, int position);
    
    private:
        int lifeValue;
        int redOrBlue; // ��ɫ�ܲ�ֵΪ0����ɫ�ܲ�ֵΪ1
        int count; // ������սʿ����
        int warriorCounts[5]; // ��¼ÿ��սʿ����������
        string headquarterName; // �ܲ�������
        string warriorNames[5]; // ��¼ÿ��սʿ���ֵ�����
        int warriorValues[5]; // ��¼ÿ��սʿ����ֵ������

};
/**
 * ָ����ʼ��
 */
headquarters::headquarters(const int theLifeValue, const int theRedOrBlue, const int theWarriorValue[], 
const string theWarriorNames[], const int order[], const string theHeadquarterNames[]) {
    count = 0;
    lifeValue = theLifeValue;
    redOrBlue = theRedOrBlue;
    headquarterName = theHeadquarterNames[redOrBlue]; // ���ܲ����ֵ�����ȡ�ø��ܲ�������
    for (int i = 0; i < 5; ++i) {
        warriorCounts[i] = 0;
        warriorNames[i] = theWarriorNames[order[i]]; // �ɸ�����˳���ԭʼսʿ���ֵ����飬�õ����ܲ�սʿ���ֵ�����
        warriorValues[i] = theWarriorValue[order[i]]; // �ɸ�����˳���ԭʼսʿ���ֵ����飬�õ����ܲ�սʿ����ֵ������
    }
}
/**
     * ����սʿ
     * time��������սʿ�����Ļغ�
     * position����������սʿ��˾�����սʿ�е�λ��
     */
void headquarters::product(int time, int position) {
    count++;
    warriorCounts[position]++; // ����սʿ��������һ
    // �����ĿҪ������
    cout << setfill('0')<<setw(3) << time << " " << headquarterName << " " << warriorNames[position]
    << " " << count << " born with strength " << warriorValues[position] << "," << warriorCounts[position]
    << " " << warriorNames[position] << " in " << headquarterName << " headquarter" << endl;
    lifeValue -= warriorValues[position];
}

int main() {
    const int redOrder[5] = {2, 3, 4, 1, 0}; // ��ɫ�ܲ��ĳ���˳��
    const int blueOrder[5] = {3, 0, 1, 2, 4}; // ��ɫ�ܲ��ĳ���˳��
    const string headquartersNames[2] = {"red", "blue"}; // ��¼�ܲ����ֵ�����
    const string priorNames[5] = { "dragon", "ninja", "iceman", "lion", "wolf" }; // ��¼սʿ���ֵ�����
    int n = 0; // ������
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int priorValue[5], headquartersValue, minValue, redPosition = 0, bluePosition = 0;
        bool redHadStop = false, blueHadStop = false;

        cin >> headquartersValue; // ��ȡ�ܲ�����ֵ
        // ��ȡÿ��սʿ������ֵ
        for (int j = 0; j < 5; j++) {
            cin >> priorValue[j];
        }
        
        cout << "Case:" << i << endl;
        // �����սʿ�е���С����ֵ
        minValue = priorValue[0];
        for (int j = 1; j < 5; j++) {
            if (priorValue[j] < minValue) {
                minValue = priorValue[j];
            }
        }
        // ��ʼ������ܲ��������ܲ�
        headquarters redOne = headquarters(headquartersValue, 0, priorValue, priorNames, redOrder, headquartersNames);
        headquarters blueOne = headquarters(headquartersValue, 1, priorValue, priorNames, blueOrder, headquartersNames);

        for (int time = 0;!redHadStop || !blueHadStop; time++) {
            // ������û��ֹͣ����������
            if (!redHadStop) {
                // ���������ֵС����Сսʿ����ֵ�� ֹͣ��������ӡ����
                if (redOne.getLifeValue() < minValue) {
                    cout << setfill('0')<<setw(3) << time << " red headquarter stops making warriors" << endl;
                    redHadStop = true;
                }
                else {
                    // ��������жϾ�ɸѡ������һ���ܳ�����
                    // �ӵ�ǰposition��ʼ���ӣ���ĳ��λ�ó�����ֹͣ
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
