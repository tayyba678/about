#include <iostream>
using namespace std;
float discount(string day, string month, float am);
main(){
    cout<<"Ente Purchase Day: ";
    string d,m;
    float am, payable;
    cin>> d;
    cout<<"Ente Purchase Month: ";
    cin>> m;
    cout<<"Ente Purchase Amount: ";
    cin>> am;
    payable= discount(d,m,am);
    cout<<"Payable Amount after discount: "<<payable;
}
float discount(string day, string month, float am)
{
    float disc=am;
    if(day=="Sunday"||month=="October")
    {
        disc=am-(am*0.1);
    }
    return disc;
}