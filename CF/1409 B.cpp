#include<bits/stdc++.h>

#define int long long
#define double long double

#define war() ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);

using namespace std;


signed main(){
    war();

    int t;  cin>>t;
    while (t--){
        int a,b,x,y,n;      cin>>a>>b>>x>>y>>n;


        int aa=a,bb=b,xx=x,yy=y,nn=n;
        int sha=min(aa-xx,nn);
        aa-=sha;     nn-=sha;
        sha=min(bb-yy,nn);
        bb-=sha;     nn-=sha;
        int ans1=aa*bb;


        aa=a,bb=b,xx=x,yy=y,nn=n;
        sha=min(bb-yy,nn);
        bb-=sha;     nn-=sha;
        sha=min(aa-xx,nn);
        aa-=sha;     nn-=sha;
        int ans2=aa*bb;

        int ans=min(ans1,ans2);
        cout<<ans<<"\n";
    }
return 0;
}