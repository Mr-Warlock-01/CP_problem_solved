#include<bits/stdc++.h>

#define int long long
#define double long double

#define war() ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);

using namespace std;


signed main(){
    war();
    int n;  cin>>n;
    int arr1[n],arr2[n];
    for(int i=0; i<n; i++){
        cin>>arr1[i];
        arr2[arr1[i]-1]=i+1;
    }
    int ans=0;
    for(int i=1; i<n; i++ ){
        ans+=(abs(arr2[i]-arr2[i-1]));
    }
    cout<<ans;
return 0;
}