#include<bits/stdc++.h>                                 //DRINK WATER

//#define int long long
//#define double long double

#define war() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std;

bool check(pair<int,int> &a1, pair<int,int> &a2){
    if(a1.first > a2.first){
        return true;
    }
    else if(a1.first == a2.first){
        if(a1.second < a2.second){
            return true;
        }
        else{
            return false;
        }
    }
    else{
        return false;
    }
}

int main(){
    //war();
    int n,k;  cin>>n>>k;
    pair<int,int>arr[n];
    for(int i=0; i<n;i++){
        cin>>arr[i].first>>arr[i].second;

    }

    sort(arr,arr+n,check);
    pair<int,int>find_position = {arr[k-1].first, arr[k-1].second};
    int ans=0;
    for(int i=n-1; i>=0; i--){
        if((arr[i].first == find_position.first) & (arr[i].second == find_position.second)){
            ans++;
        }
    }
    cout<<ans<<'\n';
return 0;
}