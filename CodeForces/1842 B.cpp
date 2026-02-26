#include<bits/stdc++.h>

#define int long long
#define double long double

#define war() ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);


using namespace std;


signed main(){
    war();
    int t;  cin>>t;
    while(t--){
        int n,x;    cin>>n>>x;
        int arr[3][n];
        for(int i=0; i<3;i++){  for(int j=0; j<n; j++){ cin>>arr[i][j];}}

        int know=0;
        bool che=false;

        for(int i=0; i<3;i++){
            if(che==true){break;}
            for(int j=0; j<n; j++){
                if(((arr[i][j])|x)!=x){break;}
                know=know|(arr[i][j]);
                if(know==x){    che=true;   break;}
            }
        }

        if(che==1 || x==0){cout<<"YES\n";}
        else{cout<<"NO\n";}
    }
return 0;
}