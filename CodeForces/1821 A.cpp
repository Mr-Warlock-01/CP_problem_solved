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
        string s;   cin>>s;
        int sz=s.length();
        int ans=1;
        for(int i=0; i<sz; i++){
            if(i==0 & s[i]=='?'){
                ans=9;
            }
            else if(i==0 & s[i]=='0'){
                ans=0;
                break;
            }
            else if(i>0 & s[i]=='?'){
                ans*=10;
            }
        }
        cout<<ans<<endl;

    }
return 0;
}