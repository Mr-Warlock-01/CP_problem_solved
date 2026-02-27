#include<bits/stdc++.h>

//#define int long long
//#define double long double

#define war() ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);

using namespace std;


signed main(){
    string s;   cin>>s;
    int z=s.length();
    vector<char>v;
    int ans=0;

    for(int i=0; i<z; i++){
        if(v.empty()==1){   v.push_back(s[i]);}
        else if(*(v.end()-1)==s[i]){    v.pop_back();   ans++;}
        else{v.push_back(s[i]);}
    }

        if(ans%2==1){cout<<"Yes";}
        else{cout<<"No";}

return 0;
}