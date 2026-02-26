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
        int SIZE; cin>>SIZE;
        string s;   cin>>s;
        int z=SIZE/3;
        bool haha=1;
        bool sha=1;
        if(z*3 !=SIZE){
            cout<<"NO"<<endl;
            continue;
        }
        int TT=0,MM=0;
        for(int i=0;i<SIZE; i++){
            if(s[i]=='T' & sha==1){
                TT++;
            }
            else if(s[i]=='T' & sha==0){
                TT--;
                MM--;
            }
            else if(s[i]=='M'){
                MM++;
            }

            if(MM<0 || MM>TT){
                haha=0; break;
            }
            if(TT==z){
                sha=0;
            }

        }
        if(haha==1){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
return 0;
  }