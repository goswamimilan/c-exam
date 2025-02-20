#include<iostream>

using namespace std;

int main(){

    int n,mil;
    cout<<"enter any number :- ";
    cin>>n;

    for(mil=0;n>0;mil++){

            n=n/10;
    }

    cout<<"total number of digit :- "<<mil;

    return 0;
}