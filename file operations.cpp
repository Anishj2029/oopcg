// Write a C++ program that creates an output file, writes information to it, closes the file, open 
// it again as an input file and read the information from the file.

#include<iostream>
#include<fstream>
using namespace std;

int main(){
    string name;
    int roll;
    string line;
    
    ofstream fout;
    fout.open("test.txt",ios::out);
    if(!fout){
        cout<<"Error !!!"<<endl;
    }
    
    cout<<"Enter the name of student: "<<endl;
    getline(cin,name);
    cin.ignore();
    cout<<"Enter the roll number of student: "<<endl;
    cin>>roll;
    
    fout<<"The name of student is: "<<name<<endl;
    fout<<"The roll number of student is: "<<roll<<endl;
    
    fout.close();
    
    ifstream fin;
    fin.open("test.txt",ios::in);
    if(!fin){
        cout<<"Error !!!"<<endl;
    }
    
    cout<<"Reading on file"<<endl;
    while(getline(fin,line)){
        cout<<line<<endl;
    }
    fin.close();
    cout<<"File is successfully closed!!!"<<endl;
    return 0;
}