#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;


struct PersonalData {
    string name;
    string dob;
    string telephone;
};

bool compareByName(const PersonalData& a, const PersonalData& b) {
    return a.name < b.name; 
}

int main() {
    vector<PersonalData> objs; 
    int ch; 
    do {
        cout << "\nMenu";
        cout << "\n1. Enter Personal Details"
             << "\n2. Display Personal Details"
             << "\n3. Search by Name"
             << "\n4. Sort by Name"
             << "\n5. Exit";
        cout << "\nEnter your choice: ";
        cin >> ch;

        switch (ch) {
            case 1: { 
                int n;
                cout << "\nEnter the number of records to add: ";
                cin >> n;
                cin.ignore(); 

                for (int i = 0; i < n; i++) {
                    PersonalData o;
                    cout << "\nEnter Name: ";
                    cin>>o.name;
                    cout << "Enter Date of Birth (dd/mm/yyyy): ";
                    cin>>o.dob;
                    cout << "Enter Telephone Number: ";
                    cin>>o.telephone;
                   
                }
                break;
            }

            case 2: { 
                if (objs.empty()) {
                    cout << "\nNo records to display!" << endl;
                } else {
                    int i=0;
                    int n;
                    cout<<"Enter the elements which to be display: ";
                    cin>>n;
                    for(i=0;i<n;i++){
                        cout << "\nName: " << objs[i].name
                        << "\nDate of Birth: " << objs[i].dob
                        << "\nTelephone Number: " << objs[i].telephone << endl;
                    }
                    
                }
                break;
            }

            case 3: 
			{ 
                if (objs.empty()) {
                    cout << "\nNo records to search!" << endl;
                } else {
                    string nameToSearch;
                    cout << "\nEnter the name to search: ";
                    cin.ignore(); 
                    getline(cin, nameToSearch);
                    vector<PersonalData>::iterator it;
                    for (it = objs.begin(); it != objs.end(); it++)
					{
    					if (it->name == nameToSearch) {
        					cout << "Found: " << it->name << ", " << it->dob << ", " << it->telephone << endl;
        					break; 
    					}
					}	
            	}
        	}

            case 4: { 
                if (objs.empty()) {
                    cout << "\nNo records to sort!" << endl;
                } else {
                    sort(objs.begin(), objs.end(), compareByName);
                    cout << "\nRecords sorted by name successfully!" << endl;
                }
                break;
            }

            case 5: 
                cout << "\nExiting the program." << endl;
                break;

            default:
                cout << "\nInvalid choice! Please try again." << endl;
        }
    } while (ch != 5);

    return 0;
}
