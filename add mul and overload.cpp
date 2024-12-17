// complex numebr operator overloading of plus and multiplication operator

#include<iostream>
using namespace std;

class complex{
    public:
    int real, img;
    int value;
    
    
    complex(int r =0, int i =0){
        real = r;
        img = i;
    }
    
    complex operator+(const complex &obj)
    {
        complex result;
        result.real = real + obj.real;
        result.img = img + obj.img;
        return result;
    }
    
    complex operator*(const complex &obj)
    {
        complex result;
        result.real = real * obj.real;
        result.img = img * obj.img;
        return result;
    }
    
    void display()
    {
        cout<<real<<"+ i"<<img<<endl;
    }
    void display1()
    {
        cout<<real<<" * i"<<img<<endl;
    }
    friend istream& operator>>(istream& in, complex& obj)
    {
        cout<<"Enter a number";
        in>>obj.value;
        return in;
    }
    
    friend ostream& operator<<(ostream& out, complex& obj)
    {
        out<<"the number is: "<<obj.value;
        return out;
    }
};

int main(){
    complex c1(1,2), c2(2,3);
    complex c3;
    int ch;
    c3 = c1 + c2;
    c3 = c1* c2;
    
    
    while(true){
        cout<<"\nMenu\n";
        cout<<"\n1.add\n2.sub\n3.operator >>\n4.operator <<\n"<<endl;
        cout<<"Enter your choice: ";
        cin>>ch;
        
        switch(ch){
            case 1:
            c3.display();
            break;
            
            case 2:
            c3.display1();
            break;
            
            case 3:
            cin>>c3;
            
            case 4:
            cout<<c3<<endl;
            
            
            break;
        }
    }
}