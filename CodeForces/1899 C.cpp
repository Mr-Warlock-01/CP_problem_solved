#include<bits/stdc++.h>                                 //DRINK WATER

#define int long long
#define double long double
#define endl "\n"

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define uniq(x) (unique(x.begin(), x.end()) - x.begin())

#define war() ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);


using namespace std;

signed main(){
    war();
    int t;  cin>>t;
    while(t--){
        int n;  cin>>n;
        int arr[n];     for(int i=0; i<n; i++){cin>>arr[i];}
        int sum=arr[0];
        int ans=sum;    int a1,a2;
        for(int i=1; i<n; i++){
            a1=(abs(arr[i-1]))%2;
            a2=(abs(arr[i]))%2;
            if(a1==a2 || sum<0){sum=0;}
            sum+=arr[i];
            ans=max(ans,sum);
        }
        cout<<ans<<endl;

    }
return 0;
}