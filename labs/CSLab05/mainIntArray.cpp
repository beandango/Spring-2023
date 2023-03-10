#include <iostream>

using namespace std;
#include "IntArray.h"
#include "IntArray.cpp"

int main()
{
    using namespace ComputerScience;
    IntArray a(3);

    //test >>
    cout<<"test operator >>"<<endl;
    cout<<"enter "<<a.size()<<" integers separated by emtpy space ";
    cin>>a;

    //test <<
    cout<<endl;
    cout<<"test operator <<" << endl;
    cout<<"echo enetered values: "<<a<<endl;

    //test [] operator
    cout<<endl;
    cout<<"test operator [] by settig the first element to 22"<<endl;
    //set first elem to 22
    a[0] = 22;
    cout<<"after first element changed to 22, the array is "<<a<<endl;

    //test copy constructor
    cout<<endl;
    cout<<"test copy constructor"<<endl;
    cout<<"IntArray b(a):"<<endl;
    IntArray b(a);
    cout<<"a: "<<a<<endl;
    cout<<"b: "<<b<<endl;

    //test assignment
    cout<<endl;
    cout<<"test assignment c = a"<<endl;
    IntArray c(1);
    c = a;
    cout<<"a: "<<a<<endl;
    cout<<"c: "<<c<<endl;

    //test "IntArray operator+ (const IntArrays r) const;
    cout << endl;
    cout << "test c = a + b;" << endl;
    b[2] = 100;
    c = a + b;
    cout<<"a: "<<a<<endl;
    cout<<"b: "<<b<<endl;
    cout<<"c: "<<c<<endl;

    //test "IntArray operator+ (int) const;" 
    cout << endl;
    cout << "test c = a + 230" << endl;
    c = a + 230;
    cout << "a: " << a << endl;
    cout << "c = a + 230: " << c << endl;

    //test "IntArrays operator+= (const IntArrays r);"
    cout << endl;
    cout << "test a += c" << endl;
    cout << "a: " << a << endl;
    cout << "c: " << c << endl;
    a += c;
    cout << "after a += c, a is " << a << endl;

    //test IntArrays operator+= (int);
    cout << endl;
    cout << "test a += 600" << endl;
    cout << "a: " << a << endl;
    a += 600;
    cout<<"after a += 600, a is " << a << endl;

    //test "friend IntArray operator+ (int, const IntArrays);" cout << endl;
    cout << "test c = 710+ a" << endl;
    cout << "a: " << a << endl;
    c = 710+ a;
    cout << "after c = 710+ a, c is " << c << endl; 

}