#include<bits/stdc++.h>                                 //DRINK WATER

#define int long long
#define double long double

#define war() ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);

using namespace std;

signed main(){      //a coins of  n, b coins of 1
    war();
    int t;  cin>>t;
    while(t--){
        string s;  cin>>s;
        int jump=1;int ans=0;
        int z=s.length();
        for(int i=0 ;i<z; i++){
            if(s[i]=='L'){
                jump++;
                ans=max(ans,jump);
            }
            else{jump=1;}
        }
        cout<<max(ans,jump)<<"\n";


    }
return 0;
}