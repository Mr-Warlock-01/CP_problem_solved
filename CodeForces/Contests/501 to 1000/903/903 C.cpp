#include<bits/stdc++.h>

#define int long long
#define double long double

#define war() ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);


using namespace std;


signed main(){
    war();
    int n;  cin>>n;
    map<int,int>arr;    //int 1= box size   int 2= box number
    for(int i=0; i<n; i++){
        int a;  cin>>a;
        arr[a]++;
    }
    int ans=0;
    for(auto u: arr){
        ans=max(ans,u.second);
    }
    cout<<ans;
return 0;
}