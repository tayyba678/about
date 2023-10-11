#include<iostream>
using namespace std;
bool parityAnalysis(int numb);
main(){
    cout<<"Enter a 3-digit number: ";
    int num;
    bool b;
    cin>>num;
    b=parityAnalysis(num);
    cout<<b;
}
bool parityAnalysis(int numb)
{
    int num1, num2, num3, number;
    bool a;
    num1=numb%10;
    num2=(numb/10)%10;
    num3=(numb/100)%10;
    number=num1 +num2+ num3;
if(numb%2==0)
{
    if(number%2==0)
    {
        a=1;
    }
    else{
    a=0;}
}
if(numb%2==1)
{
    if(number%2==1)
    {
       a=1;
    }
    else{
    a=0;}
}
return a;
}