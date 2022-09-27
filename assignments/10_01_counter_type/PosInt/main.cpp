#include <iostream>

#include "posint.h"

using namespace std;

int main()
{
    PosInt x;
    PosInt a(9);
    cout<<"a: "<<a<<endl;

    // cout << a.i; // ERROR
    // a.i = 10;
    cout<<"a: " << a.Get() << endl;

    x = a;
    cout<<"x: "<<x<<endl;
    
    a.Set(7);
    cout<<"a: "<<a<<endl;
    cout<<"x: "<<x<<endl;

    PosInt b(4);
    cout<<"b: ";
    cout<<b;
    cout<<endl;
    cout<<"Testing Prefix ++: Here is a: "<<a<<", and here is ++a: "<<++a<<endl;
    cout<<"here is a after prefix ++: "<<a<<endl;

    cout<<"resetting a: "<<endl;
    a = PosInt(9);

    cout<<"Testing Postfix ++: Here is a: "<<a<<", and here is a++: "<<a++<<endl;
    cout<<"here is a after post ++: "<<a<<endl;

    PosInt c;
    c = a + b;
    cout<<"a + b: ";
    cout<<c;
    cout<<endl;

    PosInt d;
    d = a.add(b);
    cout<<"a + b: ";
    cout<<d;
    cout<<endl;
    cout << "=============END===========" << endl;
    // return 0;


    c = b.sub(a);
    if (c.Error()){
        cout<<"b - a: "<<endl;
        cout<<c.ErrorDescr(c.Error())<<endl;
        cout<<"Object is reset to default values"<<endl;
        c.Clear();
    }
    else
        cout<<"b - a: "<<c.Get()<<endl;
    c = a.sub(b);
    cout<<"a - b: "<<c.Get()<<endl;
    cout << "=============END===========" << endl;
    return 0;
}

/*
a: [9]
b: [4]
Testing Prefix ++: Here is a: [9], and here is ++a: [10]
here is a after prefix ++: [10]
resetting a: 
Testing Postfix ++: Here is a: [9], and here is a++: [9]
here is a after post ++: [10]
a + b: [14]
=============END===========
*/