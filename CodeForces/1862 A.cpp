#include<bits/stdc++.h>
using namespace std;
signed main(){
    int t;      cin>>t;
    for(int tc=0; tc<t; tc++){
        int n,q;    cin>>n>>q;
        int arr[n+1];
        arr[0]=0;
        for(int i=1; i<=n; i++){
            long long z;  cin>>z;
            arr[i]=arr[i-1 ]+z;
        }

        for(int i=0; i<q; i++){
            int l,r,k;  cin>>l>>r>>k;
            int x = (arr[n]+arr[l-1]) - arr[r];
            int A = (l- (r-1))*k;
            int sum = x+A;

            if(sum%2==0){
                cout<<"NO\n";
            }
            else{
                cout<<"YES\n";
            }
        }
    }

return 0;
}