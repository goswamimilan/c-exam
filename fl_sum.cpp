#include<iostream>

using namespace std;

int main(){

    int n,firstDigit,lastDigit,origin,sum;

    // origin=n;
    cout<<"Enter The Value :-";
    cin>>n;
    lastDigit=n%10;

    while(n>=10){

        n=n/10;
    }

    firstDigit=n;
    sum=firstDigit+lastDigit;

    cout<<sum;


    return 0;
}