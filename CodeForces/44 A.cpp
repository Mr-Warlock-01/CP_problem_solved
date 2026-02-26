#include<bits/stdc++.h>

//#define int long long
//#define double long double

#define war() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std;
int main(){
    //war();
    //int t;  cin>>t;
    //while(t--)
    //{
      int n;    cin>>n;
      pair<string,string>arr[n];
      for(int i=0; i<n; i++){
        cin>>arr[i].first>>arr[i].second;
        }
        sort(arr,arr+n);
        int s=unique(arr,arr+n)-arr;
        cout<<s<<'\n';
    //}
return 0;
}