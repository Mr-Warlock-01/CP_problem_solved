#include<bits/stdc++.h>

#define int long long
#define double long double

#define war() ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);

using namespace std;



signed main(){
    war();
    int t;  cin>>t;
    while(t--){
        int n;  cin>>n;
        int arr[n][n-1];        int ans[n];
        for(int i=0; i<n; i++){
            for(int j=0; j<n-1; j++){
                cin>>arr[i][j];
            }
        }
        int k;
        if(arr[0][n-2]== arr[1][n-2]){  k=arr[0][n-2];}
        else if(arr[0][n-2]== arr[2][n-2]){  k=arr[0][n-2];}
        else{  k=arr[1][n-2];}
        int ok;
        for( int i=0 ;i<n; i++){
            if(arr[i][n-2]!=k){
                ok=i;
                break;
            }
        }

        for(int i=0 ;i<n-1; i++){
            cout<<arr[ok][i]<<" ";
        }
        cout<<k<<"\n";

    }
return 0;
}