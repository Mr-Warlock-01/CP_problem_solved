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
        int n,k;    cin>>n>>k;
        string s;   cin>>s;
        int ans=0;
        for(int i=0; i<n; i++){
            if(s[i]=='B'){
                ans++;
                i+=(k-1);
            }
        }
        cout<<ans<<endl;



    }
return 0;
}