#include<bits/stdc++.h>                                 //DRINK WATER

#define int long long
#define double long double

#define war() ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);

using namespace std;


signed main(){
    int t;  cin>>t;
    while(t--){
        int n,k;    cin>>n>>k;
        
        int a1[n][n];  int a2[n][n];
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                int p=n-i-1;
                int q=n-j-1;
                cin>>a1[i][j];
                a2[p][q]=a1[i][j];
            }
        }
        if(n==1){cout<<"Yes\n"; continue;}
        int ok=0;   int haha=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(a1[i][j]!=a2[i][j]){
                    haha++;
                    if(haha==2){
                        ok++;
                        haha=0;
                    }
                }
            }
        }

        if(ok>k){
            cout<<"NO\n";
        }
        else if(k==ok){
            cout<<"YES\n";
        }
        else{
            if((k-ok)%2==0){
                cout<<"YES\n";
            }
            else{
                if(n%2==1){
                    cout<<"Yes\n";
                }
                else{
                    cout<<"No\n";
                }
            }
        }





    }
return 0;
}