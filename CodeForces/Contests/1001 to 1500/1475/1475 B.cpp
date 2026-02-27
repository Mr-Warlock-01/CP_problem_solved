#include <iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    if(t<1 || t>10000){
        return 0;
    }

    for(int i=0; i<t;i++){
        int n;
        cin>>n;
        if(n<0 ||n>1000000){
            return 0;
        }
        int div=n/2020;
        int rem=n%2020;
        if(div>=rem){
            cout<<"YES";
        }
        else{
            cout<<"NO";
        }
        cout<<"\n";
    }
return 0;
}