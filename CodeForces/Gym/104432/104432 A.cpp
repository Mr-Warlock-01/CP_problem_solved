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
        int arr[n];
        for(int i=0; i<n; i++){cin>>arr[i];}

        int x=arr[0];

        for(int i=1; i<n; i++){ x=__gcd(x,arr[i]);}

        if(x==1){cout<<"0\n";}
        else if(x%2==1){cout<<"2\n";}
        else{
            for(int i=3;i<INT_MAX; i=i+2){
                if(__gcd(x,i)==1){  cout<<i<<"\n";    break;}
            }
        }
    }
return 0;
}