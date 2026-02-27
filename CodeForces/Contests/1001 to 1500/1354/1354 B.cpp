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
        string s;   cin>>s;
        int sz=s.length();
        if(sz<3){cout<<"0"<<endl;   continue;}

        int last1=0, last2=0, last3=0;


        bool exist2=0;
        int z=1;
        for(z; z<sz; z++){
            if(s[z]!=s[z-1]){
                last1 = s[z];
                last2 = s[z-1];
                exist2=1;
                break;
            }
        }

        if(!exist2){cout<<"0"<<endl;    continue;}

        int lol=2;
        int ans=LONG_LONG_MAX;
        bool exist3=0;
        z++;
        for(int i=z; i<sz; i++){
            if(s[i]!=last1 & s[i]!=last2){
                lol++;  exist3=1;  last2=last1;   last1=s[i];
                ans=min(lol,ans);
                lol=2;
            }
            else if(s[i]==last1){lol++;}
            else{last2=last1;   last1=s[i]; lol=2;}
        }
        if(exist3){cout<<ans<<endl;}
        else{cout<<"0"<<endl;}

    }
return 0;
}