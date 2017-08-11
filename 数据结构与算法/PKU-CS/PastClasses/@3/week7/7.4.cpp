#include <iostream>
#include <string>
#include <sstream>
using namespace std;
string s[100];
int tot;
string copy(string n,string x,string l) {
    int a,b;
    stringstream ss;
    ss<<x;ss>>a;
    ss.clear();
    ss<<l;ss>>b;
    return s[n[0]-'0'].substr(a,b);
}
bool is_num(string a){
    for (int i=0;i<a.size();i++){
        if (!(a[i]>='0'&&a[i]<='9')) return 0;
    }
    return 1;
}
string add(string s1,string s2){
    stringstream ss;
    if (s1.size()<6&&s2.size()<6)
        if (is_num(s1)&&is_num(s2)){
            int a;ss<<s1;ss>>a;
            ss.clear();
            int b;ss<<s2;ss>>b;
            ss.clear();
            ss<<a+b;
            string tt;
            ss>>tt;
            return tt;
        }
    return s1+s2;
}
string find(string st,string n){
    int t;
    if(s[n[0]-'0'].find(st)==string::npos) t=s[n[0]-'0'].size();
    else t=s[n[0]-'0'].find(st);
    string tt;
    stringstream ss;
    ss<<t;ss>>tt;
    return tt;
}
string rfind(string st,string n){
    int t;
    if(s[n[0]-'0'].rfind(st)==string::npos) t=s[n[0]-'0'].size();
    else t=s[n[0]-'0'].rfind(st);
    string tt;
    stringstream ss;
    ss<<t;ss>>tt;
    return tt;
}
void insert(string st,string n,string x){
    s[n[0]-'0'].insert(x[0]-'0',st);
}
void reset(string st,string n){
    s[n[0]-'0']=st;
}
void print(string n){
    cout<<s[n[0]-'0']<<endl;
}
void printall(){
    for (int i=1;i<=tot;i++)
        cout<<s[i]<<endl;
}
stringstream ss;
string getst(){
    string t;
    string s1,s2,s3;
    ss>>t;
    if (t=="find"){
        s1=getst();s2=getst();
        return find(s1,s2);
    }
    if (t=="rfind"){
        s1=getst();s2=getst();
        return rfind(s1,s2);
    }
    if (t=="copy"){
        s1=getst();s2=getst();s3=getst();
        return copy(s1,s2,s3);
    }
    if (t=="add"){
        s1=getst();s2=getst();
        return add(s1,s2);
    }
    return t;
}
int fun(string t){
    ss.clear();
    ss<<t;
    string s1,s2,s3;
    ss>>t;
    if (t=="copy"){
        s1=getst();s2=getst();s3=getst();
        copy(s1,s2,s3);
        return 1;
    }
    if (t=="add"){
        s1=getst();s2=getst();  
        add(s1,s2);
        return 1;
    }
    if (t=="find"){
        s1=getst();s2=getst();
        find(s1,s2);
        return 1;
    }
    if (t=="rfind"){
        s1=getst();s2=getst();
        rfind(s1,s2);
        return 1;
    }
    if (t=="reset"){
        s1=getst();s2=getst();
        reset(s1,s2);
        return 1;
    }
    if (t=="insert"){
        s1=getst();s2=getst();s3=getst();
        insert(s1,s2,s3);
        return 1;
    }
    if (t=="print"){
        s1=getst();
        print(s1);
        return 1;
    }
    if (t=="printall"){
        printall();
        return 1;
    }
    if (t=="over"){
        return 0;
    }
}
int main(int argc, char *argv[])
{
    cin>>tot;
    for (int i=1;i<=tot;i++)
        cin>>s[i];
    string t;
    cin.get();
    getline(cin,t);
    while (fun(t)){
        getline(cin,t);
    }
    return 0;

}
