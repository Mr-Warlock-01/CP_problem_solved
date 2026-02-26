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
        string s;       cin>>s;
        int z=s.length();
        bool check=0;
        int index;
        for (int i = z; i>0; i--){
            if(s[i]+s[i-1]>105){
                 check=1;
                 index =i-1;
                 break;
            }
        }
        if(check==1){
             for(int i=0; i<index; i++){
                  cout<<s[i];
             }
             cout<<s[index]+s[index+1]-96;
             for(int i=index+2; i<z; i++){
                  cout<<s[i];
             }
             cout<<endl;
        }
        else{
              cout<<s[0]+s[1]-96;
              for(int i=2; i<z; i++){
                  cout<<s[i];
             }
             cout<<endl;
        }

    }
return 0;
  }