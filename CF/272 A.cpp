#include<iostream>
using namespace std;
int main(){
    int n;
    int sum=0,x;
    cin>>n;
    if(n<1 || n>100){
        return 0;
    }
    for(int i=0; i<n; i++){

        cin>>x;
        sum=sum +x;
    }
    n++;
    int num=0;

    for(int i=1; i<=5; i++){
        if(((sum+i)%n)==1){
            num++;
        }
    }
    cout<<5-num;

return 0;
}