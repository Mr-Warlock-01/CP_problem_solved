#include<bits/stdc++.h>

#define int long long
#define double long double

#define war() ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);

using namespace std;

signed main(){
    war();
    int t;  cin>>t;
    while (t--){
        string s;   cin>>s;
        int z=s.length();

        int ans1=INT_MAX;
        int one=0;
        int zero=0;
        for(int i=0; i<z; i++){
            for(int j=0; j<i; j++){
                if(s[j]=='1'){
                    zero++;
                }
            }
            for(int j=i; j<z; j++){
                if(s[j]=='0'){
                    one++;
                }
            }

            ans1=min(ans1,zero+one);
            zero=0;
            one=0;
            if(ans1==0){
                break;
            }
        }

        /////

        int ans2=INT_MAX;
        for(int i=0; i<z; i++){
            if(ans1==0){break;}
            for(int j=0; j<i; j++){
                if(s[j]=='0'){
                    zero++;
                }
            }
            for(int j=i; j<z; j++){
                if(s[j]=='1'){
                    one++;
                }
            }
            ans2=min(ans2,zero+one);
            zero=0;
            one=0;
            if(ans2==0){
                break;
            }
        }
        cout<<min(ans1,ans2)<<"\n";

    }
return 0;
}