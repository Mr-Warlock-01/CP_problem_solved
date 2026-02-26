#include <iostream>
using namespace std;
int main(){
    int a,b,c;
    cin>>a>>b>>c;
    if(a<1 || a>10){
        return 0;
    }
    if(b<1 || b>10){
        return 0;
    }
    if(c<1 || c>10){
        return 0;
    }
    int z=0;
    if((a+b+c)>z){
        z=a+b+c;
    }
    if((a*b)+c >z){
        z=(a*b)+c >z;
    }
    if(((a+b)*c) >z){
        z=(a+b)*c;
    }
    if(a+(b*c)>z){
        z=a+(b*c);
    }
    if(a*(b+c)>z){
        z=a*(b+c);
    }
    if(a*b*c>z){
        z=a*b*c;
    }
    cout<<z;



return 0;
}