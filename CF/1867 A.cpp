#include<bits/stdc++.h>

#define int long long
#define double long double

#define war() ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);


using namespace std;


signed main(){
    war();
    int t;  cin>>t;
    while(t--){
        int n;  cin>>n;
        pair<int, int>a[n];
        int b[n];

        for(int i=0; i<n; i++){
            int x;  cin>>x;
            a[i].first=x;
            a[i].second=i;
        }
        sort(a,a+n);
        int num=n;
        for(int i=0; i<n; i++){
            b[a[i].second]=num;
            num--;
        }
        for(int i=0;i<n;i++){
            cout<<b[i]<<" ";
        }
        cout<<"\n";

    }

return 0;
}