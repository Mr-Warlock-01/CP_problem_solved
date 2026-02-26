#include<bits/stdc++.h>                                 //DRINK WATER

#define int long long
#define double long double
#define endl "\n"

#define war() ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);

using namespace std;

signed main(){
    war();
    int t;  cin>>t;
    while(t--){
        int n;  cin>>n;
        string s;   cin>>s;
        int z=n-3;
        bool haha=0;
        for(int i=0; i<z;i++){
            for(int j=i+2; j<n-1; j++){
                if(s[i]==s[j]){
                    if(s[i+1]==s[j+1]){
                        haha=1;
                        break;
                    }
                }
            }
        }
        if(haha){cout<<"YES"<<endl;}
        else{cout<<"NO"<<endl;}

    }
return 0;
}