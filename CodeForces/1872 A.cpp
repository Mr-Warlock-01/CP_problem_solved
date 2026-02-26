#include<bits/stdc++.h>                                 //DRINK WATER
#define war() ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
using namespace std;
int main(){
    int t;  cin>>t;
    for(int i=0; i<t; i++){
        float a,b,c;  cin>>a>>b>>c;
        float ma=max(a,b);    float mi=min(a,b);
        if(a==b){cout<<"0\n"; continue;}
        c=c+c;
        float d=ma-mi;
        float ans=ceil(d/c);
        cout<<ans<<"\n";
    }

return 0;
}