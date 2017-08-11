#include <iostream>
#include <cstring>
#include <iomanip>

using namespace std;

class QueueNode{
public:
    int hp;
    int quantity = 0;
    string knight_name;
    QueueNode * p;
};

class RingQueue{
public:
    QueueNode * current;
    QueueNode RQ[5];
    RingQueue(const int *Pint, const string * Pstr){
        for(int i = 0; i<4; i++){
            RQ[i].hp = Pint[i];
            RQ[i].p = &RQ[i+1];
            RQ[i].knight_name = Pstr[i];
        }
        RQ[4].hp = Pint[4];
        RQ[4].p = &RQ[0];
        RQ[4].knight_name = Pstr[4];
        current = &RQ[0];
    }
};

class HeadQuarter{
    RingQueue queue;
    string name;
    int whole_hp;
    int number = 1;
public:
    HeadQuarter(RingQueue q, string QuarterName, int initial_hp);
    bool isStop = false;
    void createKnight(int time);
};

HeadQuarter::HeadQuarter(RingQueue q, string QuarterName, int initial_hp):queue(q), name(QuarterName), whole_hp(initial_hp) {

}

void HeadQuarter::createKnight(int time) {
    if(isStop== true) return;
    for(int i = 0; i<=5; ++i){
        if(queue.current->hp<=whole_hp){
            whole_hp -= queue.current->hp;
            queue.current->quantity += 1;
            cout<<setw(3)<<setfill('0')<<time<<" "<<name<<" "<<queue.current->knight_name<<" "<<number<<" born with strength "<<queue.current->hp;
            cout<<","<<queue.current->quantity<<" "<<queue.current->knight_name<<" in "<<name<<" headquarter"<<endl;
            queue.current = queue.current->p;
            number += 1;
            return;
        }
    }
    isStop = true;
    cout<<setw(3)<<setfill('0')<<time<<" "<<name<<" headquarter stops making warriors"<<endl;
    return;
}

int main () {
    int HPArray[5];
    const string RedName[5] = {"iceman", "lion", "wolf", "ninja", "dragon"};
    const string BlueName[5] = {"lion", "dragon", "ninja", "iceman", "wolf"};

    int iteration, initial_HP;
    cin>>iteration;

    for(int i = 1; i<=iteration; ++i) {

        cin>>initial_HP;
        cin>>HPArray[0]>>HPArray[1]>>HPArray[2]>>HPArray[3]>>HPArray[4];

        const int RedHP[5] = {HPArray[2], HPArray[3], HPArray[4], HPArray[1], HPArray[0]};
        const int BlueHP[5] = {HPArray[3], HPArray[0], HPArray[1], HPArray[2], HPArray[4]};

        RingQueue RedQueue = RingQueue(RedHP, RedName);
        RingQueue BlueQueue = RingQueue(BlueHP, BlueName);

        HeadQuarter r(RedQueue, "red", initial_HP);
        HeadQuarter b(BlueQueue, "blue", initial_HP);
        int time = 0;
        cout<<"Case:"<<i<<endl;
        while (!(r.isStop && b.isStop)) {
            r.createKnight(time);
            b.createKnight(time);
            ++time;
        }
    }
    return 0;
}
