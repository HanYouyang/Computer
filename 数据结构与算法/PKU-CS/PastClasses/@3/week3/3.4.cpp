#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class bas{
  public:   
    int totallife;
    string color;

    bas(int n, string co){
        totallife = n;
        color = co;
    }    
};


class monster{
public:

    string color;
    string thismonstername;
    int lifevalue;
    int timethisstep;
    
    int order;

    static int redID[5];
    static int blueID[5];

    static const string redmonster[5];
    static const string bluemonster[5];       
   
    int attack;
    
    monster(string thiscolor, string monstername, int n, int timeleft){
        color = thiscolor;
        thismonstername = monstername;
        lifevalue = n;
        timethisstep = timeleft;

        if(color == "red"){       
            for(int i = 0; i < 5; i++){
                if (redmonster[i] == thismonstername){
                    order = i;
                    redID[order] += 1;

                }
            }
        }
        if (color == "blue"){          
            for(int i = 0; i < 5; i++){
                if (bluemonster[i] == thismonstername){
                    order = i;
                    blueID[order] += 1;

                }
            }     
        }
        };

    int count(){
        if (color == "red"){     

            cout << setw(3) << setfill('0') << timethisstep << " ";
            cout << color << " " << thismonstername << " " << timethisstep + 1 << " born with strength " << lifevalue << ", " << redID[order] << " " << thismonstername << " in " << color << " headqurter" << endl;     
        }
        if (color == "blue"){
             
            cout << setw(3) << setfill('0') << timethisstep << " ";
            cout << color << " " << thismonstername << " " << timethisstep + 1 << " born with strength " << lifevalue << ", " << blueID[order]  << " " << thismonstername << " in " << color << " headqurter" << endl;     
        }
        
    return 0;
    };
     

    int stop(){
        cout << setw(3) << setfill('0') << timethisstep << " ";
        cout << color << " headquarter stops making warriors" << endl;
        return 0;
    };
};

const string monster::redmonster[5] = {"iceman", "lion", "wolf", "ninja", "dragon"};
const string monster::bluemonster[5] = {"lion", "dragon", "ninja", "iceman", "wolf"};

int monster::redID[5] = {0,0,0,0,0};
int monster::blueID[5] = {0,0,0,0,0};

int main(){
    int timeleft = 0;
    string red("red");
    string blue("blue");

    int casenumber;
    cin >> casenumber;
while (casenumber--){
    
    int totallife;
    cin >> totallife;
    bas bared(totallife, red);
    bas bablue(totallife, blue);

    int lifedragon, lifeninja, lifeiceman, lifelion, lifewolf;
    scanf("%d %d %d %d %d", &lifedragon, &lifeninja, &lifeiceman, &lifelion, &lifewolf);
    int redlife[5] = {lifeiceman, lifelion, lifewolf, lifeninja, lifedragon};
    int bluelife[5] = {lifelion, lifedragon, lifeninja, lifeiceman, lifewolf};
    string redmonster[5] = {"iceman", "lion", "wolf", "ninja", "dragon"};
    string bluemonster[5] = {"lion", "dragon", "ninja", "iceman", "wolf"};

    cout << "Case: " << casenumber + 1 << endl;
    while(bared.totallife > 0 || bablue.totallife >0){
        for(int i = 0; i < 5; i++){
            
            monster a(red, redmonster[i],redlife[i], timeleft);
            monster b(blue, bluemonster[i],bluelife[i], timeleft);
           
            if (bared.totallife > 0 ){
                if (bared.totallife - redlife[i] > 0){               
                    a.count();               
                }
                else{             
                    a.stop();
                }
                bared.totallife -= redlife[i];
            }
            
            if (bablue.totallife > 0){
                if (bablue.totallife - bluelife[i] > 0){
                    b.count();
                }
                else {
                    b.stop();
                }
                bablue.totallife -= bluelife[i];
            }          
            timeleft += 1;
        }
       
    }
    }
    
}
