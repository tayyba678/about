#include<iostream>
using namespace std;
main(){
cout<<"Enter the current world population: ";
int n;
cin>> n;
cout<<"Enter the monthly birth rate (number of birth per month): ";
int m;
cin>> m;
int d,l;
cin>> l;
d=n+m*100*l;
cout<<"The population in three decades will be: "<<d;
}