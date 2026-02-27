#include<bits/stdc++.h>

#define int long long
#define double long double

#define war() ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);

using namespace std;


signed main(){
    war();
    int t; cin>>t;
    while(t--){

        int n,k,a,b;   cin>>n>>k>>a>>b;
        if(a>b){swap(a,b);}

        pair<int,int>arr[n];

        for(int i=0;i<n;i++){cin>>arr[i].first>>arr[i].second;}

        pair<int,int> aa ={arr[a-1].first, arr[a-1].second };
        pair<int,int> bb ={arr[b-1].first, arr[b-1].second };

        if(a<=k & b<=k)   {cout<<"0\n";}

        else if(a<=k & b>k) {
            int ans=10000000000;
            for(int i=0;i<k; i++){
                int z= abs(arr[i].first - bb.first) + abs(arr[i].second - bb.second);
                ans=min(ans,z);
            }
            cout<<ans<<"\n";
        }

        else{
            int ans= abs(aa.first - bb.first) + abs(aa.second - bb.second);
            int ans1=10000000000;
            int ans2=10000000000;

            for(int i=0;i<k; i++){
                int z= abs(arr[i].first - aa.first) + abs(arr[i].second - aa.second);
                ans1=min(ans1,z);
            }

            for(int i=0;i<k; i++){
                int z= abs(arr[i].first - bb.first) + abs(arr[i].second - bb.second);
                ans2=min(ans2,z);
            }

            int ans3=ans1+ans2;

            ans=min(ans,ans3);
            cout<<ans<<"\n";
        }

    }
return 0;
}