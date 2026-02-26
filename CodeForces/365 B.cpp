#include<bits/stdc++.h>

#define int long long
#define double long double

#define war() ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);

using namespace std;


signed main(){
    war();
    int n;  cin>>n;
    int arr[n];
    if(n==1 || n==2){cout<<n; return 0;}
    for(int i=0; i<n; i++){cin>>arr[i];}
    int ans=0;
    int ha=2;
    for(int i=2; i<n; i++){
        if(arr[i]==arr[i-1]+arr[i-2]){
            ha++;
        }
        else{
            ans=max(ans,ha);
            ha=2;
            }
    }
    ans=max(ans,ha);
    cout<<ans;
return 0;
}