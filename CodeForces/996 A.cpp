#include <iostream>
using namespace std;
int main(){
    int x;
    cin>>x;
    if((x<1) || (x>1000000000)){
        return 0;
    }
    int n=0;
    int y;
    y=x/100;
    n=n+y;
    x=x%100;
    y=x/20;
    n=n+y;
    x=x%20;
    y=x/10;
    n=n+y;
    x=x%10;
    y=x/5;
    n=n+y;
    x=x%5;
    y=x;
    n=n+y;
    cout<<n;
return 0;
}