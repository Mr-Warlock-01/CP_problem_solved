// https://toph.co/p/prime---prime---prime

#include<bits/stdc++.h>
using namespace std;
#define ll              long long
#define int ll



void solve(int T){
    int n;  cin>>n;
    if(n==1){cout<<"2"<<endl; return;}
    if(n==2){cout<<"2 7"<<endl; return;}
    if(n==3){cout<<"3 6 7"<<endl; return;}

    //OR =11111111111011111111111111111
    //AND=00000000000000000000000000010
    //XOR= depends

    int xor_need=536739839^2;
    cout<<"536739839 2 ";
    if(n%2==1){
        xor_need^=499999931;
    }
    else{
        xor_need^=499999993;
    }

    n-=3;

    int z=1;
    int x=1;
    while(n--){
        int ok=(z<<18)|(x<<2)|2;
         xor_need^=ok;
         cout<<ok<<" ";
         x++;
         if(x>10000){
            x=1; z++;
         }
    }
    cout<<xor_need<<endl;
}



    

int32_t main(){             //DRINK WATER
    //read();   write();
    /////////////////////////////////////

    /////////////////////////////////////
    int tc=1;
    //cin>>tc;
    for(int T=1; T<=tc; T++){
        solve(T);
    }
return 0;
} 

/*

     /\_/\
    (= ._.)
    / >  \> Mr_Warlock
   /      \

*/  