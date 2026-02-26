#include<bits/stdc++.h>

#define int long long
#define double long double

#define war() ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);

using namespace std;


signed main(){
    war();
    int t; cin>>t;
    while(t--){
        int n,x,y;  cin>>n>>x>>y;
        int xx=n/x;     int yy=n/y;     
        int lcm=(x*y)/__gcd(x,y);
        int zz=n/lcm;
        xx-=zz;     yy-=zz;
        int x1 = (xx*((2*n)-(xx-1)))/2;
        int y1 = (yy*(yy+1))/2;
        cout<<x1-y1<<"\n";
    }
return 0;
}