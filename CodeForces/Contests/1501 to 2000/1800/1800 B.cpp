#include<bits/stdc++.h>                                 //DRINK WATER

//#define int long long
//#define double long double

#define war() ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);

using namespace std;



signed main(){
    int t;  cin>>t;
    while(t--){
        int n,k;    cin>>n>>k;
        string s;   cin>>s;
        int up[26];    for(int i=0; i<26; i++){up[i]=0;}
        int lo[26];    for(int i=0; i<26; i++){lo[i]=0;}

        for(int i=0; i<n; i++){
            if(s[i]>='A' & s[i]<='Z'){
                up[s[i]-65]++;
            }
            else{
                lo[s[i]-97]++;
            }
        }
        int ans=0;
        for(int i=0; i<26; i++){
            int haha=min(up[i],lo[i]);
            up[i]-=haha;
            lo[i]-=haha;
            ans+=haha;
        }

        for(int i=0; i<26; i++){
            if(k==0){break;}
            int haha=(up[i])/2;
            haha=min(haha,k);
            ans+=haha;
            k-=haha;
        }


        for(int i=0; i<26; i++){
            if(k==0){break;}
            int haha=(lo[i])/2;
            haha=min(haha,k);
            ans+=haha;
            k-=haha;
        }

        cout<<ans<<" ";

    }
return 0;
}