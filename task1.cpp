#include<iostream>
using namespace std;
void greaterNumber(int num1, int num2);
main(){
    cout<<"Enter the first number: ";
    int num1, num2;
    cin>> num1;
    cout<<"Enter the second number: ";
    cin>> num2;
greaterNumber(num1, num2);
}
void greaterNumber(int num1, int num2)
{
    if(num1>num2)
    {
    cout<<"true";
    }
    if(num1<num2)
    {
        cout<<"false";
    }
     if(num1=num2)
    {
    cout<<"equal";
    }
}
