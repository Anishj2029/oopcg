// Imagine a publishing company which does marketing for book and audio cassette versions.
// Create a class publication that stores the title (a string) and price (type float) of publications.
// From this class derive two classes: book which adds a page count (type int) and tape which
// adds a playing time in minutes (type float).
// Write a program that instantiates the book and tape class, allows user to enter data and
// displays the data members. If an exception is caught, replace all the data member values with
// zero values.

#include<iostream>
using namespace std;

class publish {
protected:
	string name;
	float price;

public:
	publish() {
		name="";
		price=0;
	}

	virtual void input() {
		try {
			cout<<"Enter the title : "<<endl;
			getline(cin,name);
			cin.ignore();
			cout<<"Price is: "<<endl;
			cin>>price;

			if(price<0) 
		 		throw price;
		}
		catch(...) {
			cout<<"The price is less than zero !!!";
			price =0;
		}
	}

	virtual void display() {
		cout<<"The title is: "<<name<<endl;
		cout<<"Price is: "<<price<<endl;
	}
};

class book:public publish
{
protected:
	int count;
public:

	book():publish(), count(0) {}

	void input() {
		try {
			publish::input();
			cout<<"Enter the page count: "<<endl;
			cin>>count;

			if(count<0)
				throw count;
		}
		catch(...) {
			cout<<"price is lower than zero!!!"<<endl;
		}
	}
	void display() {
		publish::display();
		cout<<"The page count is: "<<count<<endl;
	}
};

class tape:public publish
{
protected:
	float min;
public:
	tape():publish(), min(0) {}

	void input() {
		try {
			publish::input();
			cout<<"Enter the min of tape played: "<<endl;
			cin>>min;

			if(min<0) 
				throw min;
		}
		catch(...) {
			cout<<"The mins are less than zero!!!"<<endl;
		}
	}

		void display()
		{
			publish::display();
			cout<<"The mins tape played is: "<<min<<endl;
		}
	};

	int main()
	{
		book b;
		tape t;

		int ch;
		do{
		    cout<<"\nMenu\n";
		    cout<<"\n1.add book\n2.add tape\n3.display book\n.4.display tape\n5.exit\n";
		    cout<<"\nEnter the choice: \n";
		    cin>>ch;
		    cin.ignore();
		    switch(ch){
		        case 1:
		        cout<<"\nAdd book details: \n";
		        b.input();
		        break;
		        
		        case 2:
		        cout<<"\nAdd tape details: \n";
		        t.input();
		        break;
		        
		        case 3:
		        b.display();
		        break;
		        
		        case 4:
		        t.display();
		        break;
		        
		        case 5:
		        exit(0);
		    }
		}while(ch != 5);
	}
