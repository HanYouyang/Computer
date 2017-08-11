#include <iostream> 
#include <iterator> 
#include <list> 
#include<cstdio>
#include<string>
#include<set>
#include<vector>
using namespace std;
class MyList{
public:
    int Id;
    list<int> lst;
    MyList(int id) {
        Id = id;
    }
};
void PrintList(const list<int> & lst) {
    int tmp = lst.size();
    if (tmp> 0) {
        list<int>::const_iterator i;
        i = lst.begin();
        for (i = lst.begin(); i != lst.end(); i++)
            cout << (*i) << " ";
    }
    cout << endl;
};
MyList & FindList(vector<MyList> & lst, int id) {
    int tmp = lst.size();
    if (tmp> 0) {
        vector<MyList>::iterator i;
        i = lst.begin();
        return *(i + id - 1);
    }
};
int main(){
    int inLines;
    cin >> inLines;
    vector<MyList> vecs;
    for (int i = 0; i < inLines; i++){
        string cmd;
        cin >> cmd;
        if (cmd == "new"){
            int id;
            cin >> id;
            vecs.push_back(MyList(id));
        }
        else if (cmd == "add"){
            int id;
            cin >> id;
            MyList& list = FindList(vecs, id);
            int num;
            cin >> num;
            list.lst.push_back(num);
            list.lst.sort();
        }
        else if (cmd == "merge"){
            int id1;
            cin >> id1;
            MyList& list1 = FindList(vecs, id1);
            int id2;
            cin >> id2;
            MyList& list2 = FindList(vecs, id2);
            list1.lst.merge(list2.lst);
        }
        else if (cmd == "unique"){
            int id;
            cin >> id;
            MyList& list = FindList(vecs, id);
            list.lst.sort();
            list.lst.unique();
        }
        else if (cmd == "out"){
            int id;
            cin >> id;
            MyList& list = FindList(vecs, id);
            PrintList(list.lst);
        }
    }
    return 0;
}
