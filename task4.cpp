#include<iostream>
using namespace std;
float perimeter(char al, float n);
main(){
    cout<<"Enter the shape (s for square, c for circle, t for triangle, h for heaxgon): ";
    char ch;
    float pro;
    cin>> ch;
    cout<<"Enter the value: ";
    float num;
    cin>> num;
 pro=perimeter(ch, num);
 cout<<pro;
}
float perimeter(char al, float n)
{
    float pr;
    if(al=='s')
    {
pr=n*4;
    }
    if(al=='c')
    {
pr=n*6.28;
    }
    if(al=='t')
    {
pr=n*3;
    }
    if(al=='h')
    {
pr=n*6;
    }
    return pr;
}
