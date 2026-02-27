#include<bits/stdc++.h>                                 //DRINK WATER

#define int long long
#define double long double

#define war() ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);

using namespace std;

signed main(){
    war();
    int t;  cin>>t;
    while(t--){
        int n;  cin>>n;
        int  x;  cin>>x;
        int arr[n];     for(int i=0;i<n; i++){cin>>arr[i];}
        sort(arr,arr+n);
        int ok=0;
        int ans=0;
        for(int i=n-1; i>=0; i--){
            if(arr[i]>x){
                ok+= (arr[i]-x);
                ans++;
            }
            else if(arr[i]<x){
                ok+= (arr[i]-x);
                ans++;
                if(ok<0){
                    ans--;
                    break;
                }
                if(ok==0){
                    break;
                }
            }
            else{ans++;}
        }
        cout<<ans<<"\n";
    }
return 0;
}