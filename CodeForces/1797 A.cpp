#include<bits/stdc++.h>                                 //DRINK WATER

#define int long long
#define double long double

#define war() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std;


signed main(){
    //war();
    int t;  cin>>t;
    while(t--){
        int n,m;    cin>>n>>m;
        int x1,y1,x2,y2;    cin>>x1>>y1>>x2>>y2;
        int k1,k2;

        if((x1==1 & y1==1) || (x1==1 & y1==m) || (x1==n & y1==1) || (x1==n & y1==m)){
           k1=2;
           }
        else if(((x1>1 & x1<n) & (y1==1 || y1==m)) || ((x1==1 || x1==n) &(y1>1 & y1<m ))){
            k1=3;
        }
        else{
            k1=4;
        }


        if((x2==1 & y2==1) || (x2==1 & y2==m) || (x2==n & y2==1) || (x2==n & y2==m)){
           k2=2;
           }
        else if(((x2>1 & x2<n) & (y2==1 || y2==m)) || ((x2==1 || x2==n) &(y2>1 & y2<m ))){
            k2=3;
        }
        else{
            k2=4;
        }

        cout<<min(k1,k2)<<"\n";

    }
return 0;
}