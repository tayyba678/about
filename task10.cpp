#include<iostream>
using namespace std;
bool areSameNumber(int n1, int n2, int n3);
main(){
    cout<<"Enter trhe first number: ";
    int m,n,o;
    bool h;
    cin>> m;
    cout<<"Enter trhe second number: " ;
    cin>> n;
    cout<<"Enter trhe third number: " ;
    cin>> o;
    h=areSameNumber(m,n,o);
    cout<<h;
}
bool areSameNumber(int n1, int n2, int n3)
{
    bool g;
    if(n1==n2&&n1==n3)
    {
        g=1;
    }
     
    if(n1==n2&&n1!=n3)
    {
        g=0;
    }
    
    if(n1!=n2&&n1==n3)
    {
        g=0;
    }
    
    if(n1!=n2&&n1!=n3)
    {
        g=0;
    }
    return g;
}
