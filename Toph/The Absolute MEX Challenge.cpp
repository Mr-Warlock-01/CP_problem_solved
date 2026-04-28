// https://toph.co/arena?practice=67beea7dbd06f0757a979cf7#!/p/67b8c1c3a1421e6d6b46d160

#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>


using namespace __gnu_pbds;
using namespace std;

typedef long long ll;
#define endl '\n'

template <typename T> using o_set = tree < T , null_type, less <T> , rb_tree_tag, tree_order_statistics_node_update>;

// order_of_key (value) -> chotokoita 
// find_by_order(index) -> returns the value in the index



void solve(int test) {
    int n;  cin>>n;
    int x=(n + 1)/2;
    
    vector<int>v;
    v.push_back(1);
    v.push_back(1+x);

    for(int i=n; i>=2; i--){
        if(i==(x+1)){continue;}
        v.push_back(i);
    }

    for(int i=0; i<n; i++){
        cout<<v[i]<<" "; 
    }cout<<endl;
}




int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1;
    cin >> t;

    for (int T = 1; T <= t; T++) {
        solve(T);
    }
return 0;
}