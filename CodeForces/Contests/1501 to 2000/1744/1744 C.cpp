#include<bits/stdc++.h>                                 //DRINK WATER

//#define int long long
//#define double long double

#define war() ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);

using namespace std;



signed main(){
    int t;  cin>>t;
    while(t--){
        int n;  string s;   char c;         cin>>n>>c>>s;
        if(c=='g'){cout<<"0\n"; continue;}
        s=s+s;      n=2*n;
        int cou=-1, ans=0;
        for(int i=0; i<n; i++){
            if(s[i]==c & cou==-1){cou=0;}
            else if(cou>=0){
                if(s[i]!='g'){cou++;}
                else{cou++;     ans=max(ans,cou);       cou=-1;}
            }
        }
        cout<<ans<<"\n";
    }
return 0;
}