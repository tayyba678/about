#include<iostream>
using namespace std;
string checkSpeed(float n);
main()
{
    string h;
    cout<<"Enter the speed: ";
    float s;
    cin>>s;
   h= checkSpeed(s);
   cout<< h;
}
string checkSpeed(float n)
{
    string a;
    if(n<=10)
    {
        a="slow";
    }
     if(n>10&&n<=50)
    {
        a="average";
    }
     if(n>50&&n<=150)
    {
        a="fast";
    }
    if(n>150&&n<=1000)
    {
        a="ultra-fast";
    }if(n>=1000)
    {
        a="extremely fast";
    }
    return a;

}


