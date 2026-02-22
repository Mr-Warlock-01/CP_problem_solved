#include<bits/stdc++.h>                                 //DRINK WATER

#define int long long
#define double long double
#define endl "\n"

#define war() ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);

using namespace std;

signed main(){
    war();
for(int t=1;;t++){
    int s;  cin>>s;
    int z=s;
    int ans=-1;
    if(z==0){
        return 0;
    }

    for(; z>0;z--){
        int sum=0;
        for(int i=1; i<=sqrt(z);i++){
            if(z%i==0){
                sum+=i;
                if(z/i!=i){
                    sum+=(z/i);
                }
            }
            if(sum>s){
                break;
            }
        }
        if(sum==s){
            ans=z;
            break;
        }
    }
    cout<<"Case "<<t<<": "<<ans<<endl;
}
}
