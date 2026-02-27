#include <iostream>
using namespace std;
int main(){
    int a,b;
    cin>>a>>b;
    if(a<1 || a>1000){
        return 0;
    }
    if(b<2 || b>1000){
        return 0;
    }
    int hour=0;
    int in_hand=0;

    while(a!=0){

        hour+=a;
        int z= a/b;
        in_hand = in_hand + a-(z*b);
        a=z;
        if(in_hand>=b){
            a++;
            in_hand-=b;
        }

    }
//hour += a;

cout<<hour;

return 0;
}