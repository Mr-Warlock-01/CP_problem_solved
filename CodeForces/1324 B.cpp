#include<bits/stdc++.h>                                 //DRINK WATER

#define int long long
#define double long double

#define war() ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);

using namespace std;

signed main(){      //a coins of  n, b coins of 1
    war();
    int t;  cin>>t;
    while(t--){
        int n;  cin>>n;
        int arr[n];    for(int i=0; i<n; i++){cin>>arr[i];}
        bool test=0;

        for(int i=0; i<n-2; i++){
            if(test==1){break;}
            for(int j=i+2; j<n; j++){
                if(arr[i]==arr[j]){
                    test=1;
                    break;
                }
            }
        }

        if(test==1){cout<<"YES\n";}
        else{cout<<"NO\n";}
    }
return 0;
}