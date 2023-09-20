#include<iostream>
using namespace std;
main(){
cout<<"Enter the name of cricket team: ";
int T;
cin>>T;
cout<<"Enter the name of wins: ";
int w;
cin>>w;
cout<<"Enter the name of draws: ";
int d;
cin>>d;
cout<<"Enter the name of losses: ";
int l;
cin>>l;
int p;
p=w*3+d*1+l*0;
cout<<"Pakistan has obtained"<<p<<"points in the Asia Cip Tournament.";
}
