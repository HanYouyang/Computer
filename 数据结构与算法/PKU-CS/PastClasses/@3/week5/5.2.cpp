#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class headquarters
{
public:

    headquarters(const int theLifeValue, const int theRedOrBlue, const int theWarriorValue[],
                 const string theWarriorNames[], const int order[], const string theHeadquarterNames[]);

    ~headquarters();

    //��ȡ������������սʿ��id����
    int getCount() { return  count;}

    // ��ȡ����ֵ��������main���������սʿ����С����ֵ�Ƚϣ��Լ���սʿ����ֵ�ıȽ�
    int getLifeValue() { return lifeValue; }

    // ��ȡ��Ҫ������սʿ������ֵ
    int getWarriorValue(int position) { return warriorValues[position]; }

    // ��ȡ��Ҫ������սʿ������
    string getWarriorName(int position) { return warriorNames[position];}

    // ����սʿ
    void product(int time, int position);

private:
    int lifeValue;
    int redOrBlue; // ��ɫ�ܲ�ֵΪ0����ɫ�ܲ�ֵΪ1
    int count; // ������սʿ����
    int *warriorCounts; // ��¼ÿ��սʿ����������
    string headquarterName; // �ܲ�������
    string *warriorNames; // ��¼ÿ��սʿ���ֵ�����
    int *warriorValues; // ��¼ÿ��սʿ����ֵ������

};

/**
 * ָ����ʼ��
 */
headquarters::headquarters(const int theLifeValue, const int theRedOrBlue, const int theWarriorValue[],
                           const string theWarriorNames[], const int order[], const string theHeadquarterNames[])
{
    count = 0;
    lifeValue = theLifeValue;
    redOrBlue = theRedOrBlue;
    headquarterName = theHeadquarterNames[redOrBlue]; // ���ܲ����ֵ�����ȡ�ø��ܲ�������
    warriorCounts = new int[5]{0};
    warriorValues = new int[5];
    warriorNames = new string[5];
    for (int i = 0; i < 5; ++i) {
        warriorNames[i] = theWarriorNames[order[i]]; // �ɸ�����˳���ԭʼսʿ���ֵ����飬�õ����ܲ�սʿ���ֵ�����
        warriorValues[i] = theWarriorValue[order[i]]; // �ɸ�����˳���ԭʼսʿ���ֵ����飬�õ����ܲ�սʿ����ֵ������
    }
}

headquarters::~headquarters() {
    if (warriorCounts) delete []warriorCounts;
    if (warriorValues) delete []warriorValues;
    if (warriorNames) delete []warriorNames;
}

/**
     * ����սʿ
     * time��������սʿ�����Ļغ�
     * position����������սʿ��˾�����սʿ�е�λ��
     */
void headquarters::product(int time, int position)
{
    count++;
    warriorCounts[position]++; // ����սʿ��������һ
    // �����ĿҪ������
    cout << setfill('0')<<setw(3) << time << " " << headquarterName << " " << warriorNames[position]
    << " " << count << " born with strength " << warriorValues[position] << "," << warriorCounts[position]
    << " " << warriorNames[position] << " in " << headquarterName << " headquarter" << endl;
    lifeValue -= warriorValues[position];
}

class warrior{
private:
    int id;
    int lifeValue;
    string *weaponNames;
public:
    warrior():id(0),lifeValue(0) {}
    warrior(int theId, int theLifeValue):id(theId), lifeValue(theLifeValue) {
        weaponNames = new string[3] {"sword", "bomb", "arrow"};
    }
    ~warrior() {
        if (weaponNames) delete []weaponNames;
    }
    int getId() { return id;}
    string* getWeaponNames() { return weaponNames;}
};

class dragon:public warrior {
private:
    float morale; //ʿ������
public:
    dragon(int theId, int theLifeValue, int headquarterLifeValue):warrior(theId, theLifeValue) {
        morale = (float)(headquarterLifeValue) / theLifeValue;
    }
    ~dragon() {};
    float getMorale() { return morale;}
    string getWeaponName() {
        int index = this->getId() % 3;
        return this->getWeaponNames()[index];
    }
    void print() {
        cout<<"It has a "<<this->getWeaponName()<<",and it's morale is "<< setprecision(2)<<fixed<< this->getMorale()<<endl;
    }
};

class ninja:public warrior {
public:
    ninja(int theId, int theLifeValue):warrior(theId, theLifeValue) {}
    ~ninja() {}
    string getFirstWeaponName() {
        int index = this->getId() % 3;
        return this->getWeaponNames()[index];
    }
    string getSecondWeaponName() {
        int index = (this->getId() + 1) % 3;
        return this->getWeaponNames()[index];
    }
    void print() {
        cout<<"It has a "<<this->getFirstWeaponName()<<" and a "<<this->getSecondWeaponName()<<endl;
    }
};

class iceman:public warrior {
public:
    iceman(int theId, int theLifeValue):warrior(theId, theLifeValue) {}
    ~iceman() {};
    string getWeaponName() {
        int index = this->getId() % 3;
        return this->getWeaponNames()[index];
    }
    void print() {
        cout<<"It has a "<<this->getWeaponName()<<endl;
    }
};

class lion:public warrior {
private:
    int loyalty;
public:
    lion(int theId, int theLifeValue, int headquarterLifeValue):warrior(theId, theLifeValue) {
        loyalty = headquarterLifeValue;}
    ~lion() {}
    int getLoyalty() { return loyalty;}
    void print() {
        cout<<"It's loyalty is "<<this->getLoyalty()<<endl;
    }
};

class wolf:public warrior {
public:
    wolf(int theId, int theLifeValue):warrior(theId, theLifeValue) {}
    ~wolf() {}
};

int main()
{
    const int redOrder[5] = {2, 3, 4, 1, 0}; // ��ɫ�ܲ��ĳ���˳��
    const int blueOrder[5] = {3, 0, 1, 2, 4}; // ��ɫ�ܲ��ĳ���˳��
    const string headquartersNames[2] = {"red", "blue"}; // ��¼�ܲ����ֵ�����
    const string priorNames[5] = { "dragon", "ninja", "iceman", "lion", "wolf" }; // ��¼սʿ���ֵ�����
    int n = 0; // ������
    cin >> n;
    for (int i = 1; i <= n; i++)
    {

        int priorValue[5], headquartersValue, minValue, redPosition = 0, bluePosition = 0;
        bool redHadStop = false, blueHadStop = false;

        cin >> headquartersValue; // ��ȡ�ܲ�����ֵ
        // ��ȡÿ��սʿ������ֵ
        for (int j = 0; j < 5; j++)
        {
            cin >> priorValue[j];
        }

        cout << "Case:" << i << endl;

        // �����սʿ�е���С����ֵ
        minValue = priorValue[0];
        for (int j = 1; j < 5; j++)
        {
            if (priorValue[j] < minValue)
            {
                minValue = priorValue[j];
            }
        }

        // ��ʼ������ܲ��������ܲ�
        headquarters redOne = headquarters(headquartersValue, 0, priorValue, priorNames, redOrder, headquartersNames);
        headquarters blueOne = headquarters(headquartersValue, 1, priorValue, priorNames, blueOrder, headquartersNames);


        for (int time = 0;!redHadStop || !blueHadStop; time++)
        {
            // ������û��ֹͣ����������
            if (!redHadStop)
            {
                // ���������ֵС����Сսʿ����ֵ�� ֹͣ��������ӡ����
                if (redOne.getLifeValue() < minValue)
                {
                    cout << setfill('0')<<setw(3) << time << " red headquarter stops making warriors" << endl;
                    redHadStop = true;
                }
                else {
                    // ��������жϾ�ɸѡ������һ���ܳ�����
                    // �ӵ�ǰposition��ʼ���ӣ���ĳ��λ�ó�����ֹͣ
                    while (true)
                    {
                        if (redOne.getLifeValue() >= redOne.getWarriorValue(redPosition))
                        {
                            redOne.product(time, redPosition); // ����

                            if (redOne.getWarriorName(redPosition) == "dragon") {
                                dragon theDragon(redOne.getCount(), redOne.getWarriorValue(redPosition), redOne.getLifeValue());
                                theDragon.print();
                            } else if (redOne.getWarriorName(redPosition) == "ninja") {
                                ninja theNinja(redOne.getCount(), redOne.getWarriorValue(redPosition));
                                theNinja.print();
                            } else if (redOne.getWarriorName(redPosition) == "iceman") {
                                iceman theIceman(redOne.getCount(), redOne.getWarriorValue(redPosition));
                                theIceman.print();
                            } else if (redOne.getWarriorName(redPosition) == "lion") {
                                lion theLion(redOne.getCount(), redOne.getWarriorValue(redPosition), redOne.getLifeValue());
                                theLion.print();
                            } else {
                                wolf theWolf(redOne.getCount(), redOne.getWarriorValue(redPosition));
                            }

                            if (redPosition == 4 ? redPosition = 0: redPosition++);
                            break;
                        }
                        else
                        {
                            if (redPosition == 4 ? redPosition = 0: redPosition++);
                        }
                    }
                }
            }

            if (!blueHadStop)
            {
                if (blueOne.getLifeValue() < minValue)
                {
                    cout << setfill('0')<<setw(3)<< time << " blue headquarter stops making warriors" << endl;
                    blueHadStop = true;
                }
                else {
                    while (true)
                    {
                        if (blueOne.getLifeValue() >= blueOne.getWarriorValue(bluePosition))
                        {
                            blueOne.product(time, bluePosition);

                            if (blueOne.getWarriorName(bluePosition) == "dragon") {
                                dragon theDragon(blueOne.getCount(), blueOne.getWarriorValue(bluePosition), blueOne.getLifeValue());
                                theDragon.print();
                            } else if (blueOne.getWarriorName(bluePosition) == "ninja") {
                                ninja theNinja(blueOne.getCount(), blueOne.getWarriorValue(bluePosition));
                                theNinja.print();
                            } else if (blueOne.getWarriorName(bluePosition) == "iceman") {
                                iceman theIceman(blueOne.getCount(), blueOne.getWarriorValue(bluePosition));
                                theIceman.print();
                            } else if (blueOne.getWarriorName(bluePosition) == "lion") {
                                lion theLion(blueOne.getCount(), blueOne.getWarriorValue(bluePosition), blueOne.getLifeValue());
                                theLion.print();
                            } else {
                                wolf theWolf(blueOne.getCount(), blueOne.getWarriorValue(bluePosition));
                            }

                            if (bluePosition == 4 ? bluePosition = 0: bluePosition++);
                            break;
                        }
                        else
                        {
                            if (bluePosition == 4 ? bluePosition = 0: bluePosition++);
                        }
                    }
                }
            }

        }

    }

    return 0;
}
