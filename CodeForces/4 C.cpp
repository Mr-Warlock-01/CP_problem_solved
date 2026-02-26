#include<bits/stdc++.h>

#define int long long
#define double long double

#define war() ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);

using namespace std;


signed main(){
    war();
    int n;  cin>>n;
    map<string,int> x;
    for(int i=0; i<n; i++){
        string s;   cin>>s;
        if(x[s]==0){
            x[s]++;
            cout<<"OK\n";
        }
        else{
            cout<<s<<x[s]<<"\n";
            x[s]++;
        }
    }

return 0;
}