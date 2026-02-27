#include<bits/stdc++.h>                                 //DRINK WATER

#define int long long
#define double long double
#define endl "\n"

#define war() ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);

using namespace std;

signed main(){
    war();
    int t=1;  cin>>t;
    while(t--){
        int x,n;  cin>>x>>n;
        int ans=0;
        for(int i=1; (i*i)<=x; i++){
            if((x%i==0) && ((x/i)>=n) ){
              ans = i;
            }
            if((x%i==0) && (i>=n) ){
              ans = x/i; break;
            }  
        }
      cout<<ans<<endl;
    }       
return 0;
}