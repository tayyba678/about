#include<iostream>
using namespace std;
string checkTitle(int age, char b);
main()
{
cout<<"Enter yor age: ";
int age;
string h;
char c;
cin>> age;
cout<<"Enter your gender (m/f): ";
cin>> c;
h=checkTitle(age, c);
cout<<"Your personal title is: "<<h;
}
string checkTitle(int age , char b)
{
    string  g;
    if(age>=16&&b=='m')
    {
        g="Mr.";
    }
     if(age<16&&b=='m')
    {
        g="Master";
    }
     if(age>=16&&b=='f')
    {
        g="Ms.";
    }
     if(age<16&&b=='f')
    {
        g="Miss";
    }
    return g;
}