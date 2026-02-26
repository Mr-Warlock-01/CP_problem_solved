#include<bits/stdc++.h>

#define int long long
#define double long double

#define war() ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);

using namespace std;

signed main(){
    //war();
    int n;  cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    sort(arr,arr+n);
    int si= unique(arr,arr+n)- arr;

    for(int i=0; i<si; i++){
        if(arr[i]!=(i+1)){
            cout<<i+1;
            return 0;
        }
    }
    cout<<si+1;
}