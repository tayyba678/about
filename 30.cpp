#include <iostream>
using namespace std;
int findGreatest(int no1, int no2, int no3);
main(){
    cout<<"Enter the first number: ";
    int n1,n2,n3,b;
    cin>>n1;
    cout<<"Enter the second number: ";
    cin>> n2;
     cout<<"Enter the third number: ";
    cin>> n3;
   b=findGreatest(n1, n2, n3);
    cout<<"The greatest number among "<<n1<<" "<<n2<<" and "<<n3 <<" is "<<b;
    }
int findGreatest(int no1, int no2, int no3)
{
    int a;
    if(no1>=no2)
    {
        if(no1>=no3)
    {
         a=no1;
    }
    }
    if(no2>=no1)
    {
        if(no2>=no3)
    {
         a=no2;
    }
    } 
    if(no3>=no1)
    {
        if(no3>=no2)
    {
        a=no3;
    }
    }
    
	
    return a;
}
