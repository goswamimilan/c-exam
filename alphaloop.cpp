#include<iostream>

using namespace std;

int main(){
    
    char i;
    cout<<"enter char :-";
    cin>>i;
    
    
    do
    {
        cout<<" "<<i;

        i=i+4;
    } while (i<='z');
    
    return 0;
}