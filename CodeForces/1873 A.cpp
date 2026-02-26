#include<bits/stdc++.h>                                 //DRINK WATER

#define int long long
#define double long double
#define endl "\n"

#define war() ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);

using namespace std;

signed main(){
    war();
    int t;  cin>>t;
    while(t--){
        char a,b,c; cin>>a>>b>>c;
        int sum=0;
        if(a=='a'){ sum++;}
        if(b=='b'){ sum++;}
        if(c=='c'){ sum++;}
        if(sum==1 || sum==3){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }





    }
return 0;
  }