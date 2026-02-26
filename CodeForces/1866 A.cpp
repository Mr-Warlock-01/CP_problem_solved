#include<bits/stdc++.h>

#define int long long
#define double long double

#define war() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std;
signed main(){
    int n;  cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int x=abs(arr[0]);
    for(int i=1; i<n; i++){
        x=min(x,abs(arr[i]));
    }
    cout<<x;

return 0;
}