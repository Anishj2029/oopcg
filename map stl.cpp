// . Write a program in C++ to use map associative container. The keys will be the names of states 
// and the values will be the populations of the states. When the program runs, the user is 
// prompted to type the name of a state. The program then looks in the map, using the state 
// name as an index and returns the population of the state.

#include<iostream>
#include<map>
#include<string>
using namespace std;

int main(){
    map<string,int> statepopulation;
    
    statepopulation =  {
        {"California", 39538223},
        {"Texas", 29145505},
        {"Florida", 21538187},
        {"New York", 20201249},
        {"Pennsylvania", 13002700},
        {"Illinois", 12812508},
        {"Ohio", 11799448},
        {"Georgia", 10711908},
        {"North Carolina", 10439388},
        {"Michigan", 10077331}
    };
    
    string statename;
    
    cout<<"Enter the sate name to be search: ";
    getline(cin,statename);
    cin.ignore();
    
    auto it =statepopulation.find(statename);
    
    if(it != statepopulation.end()){
        cout<<"state name is "<<statename<<" and population is "<< it->second <<endl;
    }
    else
    {
        cout<<"the state name is not found!!!"<<endl;
    }
    return 0;
    
}
