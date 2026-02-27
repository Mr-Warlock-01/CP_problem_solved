#include <iostream>
using namespace std;
int main(){
    int s1,s2,s3,s4;
        cin>>s1>>s2>>s3>>s4;

        if((s1<1) || (s1>1000000000)){
            return 0;
        }
        else if((s2<1) || (s2>1000000000)){
            return 0;
        }
        else if((s3<1) || (s3>1000000000)){
            return 0;
        }
        else if((s4<1) || (s4>1000000000)){
            return 0;
        }

    int x=0;
    if(s2==s1){
        x++;
    }
    if((s3==s2) || (s3==s1)){
        x++;
    }
    if((s4==s3) || (s4==s2) ||(s4==s1)){
        x++;
    }
    cout<<x;


return 0;
}