#include<bits/stdc++.h>

#define int long long
#define double long double

#define war() ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);

using namespace std;



signed main(){

    string s;   cin>>s;
    int si=s.size();        //size
    int c=0;                 //count
    int ans=0;

    vector<char>aa;


    for(int i=0; i<si; i++){
        if(s[i]=='<' || s[i]=='{' || s[i]=='[' || s[i]=='('){
            c++;
            aa.push_back(s[i]);
           }
        else{
            c--;
            if(c<0){break;}
            if( (aa[c]=='<' & s[i]=='>') || (aa[c]=='(' & s[i]==')') || (aa[c]=='{' & s[i]=='}') || (aa[c]=='[' & s[i]==']') ){  aa.pop_back();   }
            else{
                ans++;
                aa.pop_back();
            }
        }
    }
    if(c==0){cout<<ans;}
    else{cout<<"Impossible";}

return 0;
}