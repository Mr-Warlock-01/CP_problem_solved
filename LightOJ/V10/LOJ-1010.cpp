#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;    cin>>T;
    for(int TT=1; TT<=T; TT++){
        int n,m;    cin>>n>>m;
        if(n>m){swap(n,m);}
        cout<<"Case "<<TT<<": ";
        if(n==1){cout<<m<<endl;}
        else if(n==2){
            int z=m%4;
            int ans=(4*(m/4));
            if(z==1){ans+=2;}
            if(z>=2){ans+=4;}
            cout<<ans<<endl;
        }
        else{
            int ans=((n*m)+1)/2;
            cout<<ans<<endl;
        }
    }
}
