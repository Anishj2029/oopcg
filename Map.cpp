#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    map<string, int> myMap;

    myMap["California"]=15975463;
    myMap["Texas"]=152894;
    myMap["Florida"]=152876;
    myMap["satara"]=548923;
    myMap["Pune"]=154892;
    myMap["Sangali"]=459723;
    myMap["mumbai"]=987456;


    string name;
    cout<<"Enter the name to be searched!!";
    cin>>name;
    map<string, int>:: iterator it = myMap.find(name);
    if(it != myMap.end()){
        cout<<name<<" -- >"<<it->second<<endl;
    }
    else
    {
        cout<<"Not found !!!";
    }
    return 0;
}


