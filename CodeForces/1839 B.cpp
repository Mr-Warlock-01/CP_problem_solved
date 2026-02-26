#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
    int t;  cin>>t;
    for(int tc=0; tc<t; tc++){
        int n;  cin>>n;
        pair<int, int> arr[n];
        int num[n+1];
        for(int i=0;i<=n; i++){
            num[i]=0;
        }
        for(int i=0; i<n; i++){
            int a,b;    cin>>a>>b;
            arr[i]={a,b};
            num[a]++;
        }

        sort(arr, arr+n);

        for(int i=1;i<=n;i++){num[i]+=num[i-1];}

        int max_point=0;
        int m=arr[n-1].first;
        for(int okay=1; okay<=m; okay++ ){
            int z=min( okay,(num[okay]-num[okay-1]));
            int x=num[okay]-1;
            for(int a=0; a<z; a++){
                max_point+=arr[x].second;
                x--;
            }
        }
        cout<<max_point<<"\n";
    }
return 0;
}