#include<bits/stdc++.h>                                         //DRINK WATER

using namespace std;

#define int long long
#define double long double
#define ull unsigned long long
#define endl "\n"
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define uniq(x) (unique(x.begin(), x.end()) - x.begin())
#define war() ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);

#ifndef ONLINE_JUDGE
#define db(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define db(x)
#endif
void _print(int t) {cerr << "= { " << t << " }";}
void _print(string t) {cerr << "= { " << t << " }";}
void _print(char t) {cerr << "= { " << t << " }";}
void _print(double t) {cerr << "= { " << t << " }";}
void _print(bool x) {cerr << (x ? "= { true }" : "= { false }");}

void pikachu(int T){         ///MAIN  (DRINK WATER)
    int n, x, y;  cin>>n>>x>>y;
    vector<int>v(n);    for(int i=0; i<n; i++){cin>>v[i];}
    map<int,map<int,int>>m;
    int ans=0;
    for(int i=0; i<n; i++){
        ans+=m[ (x- (v[i]%x))%x ][v[i]%y];
        m[v[i]%x] [v[i]%y]++;
    }
    cout<<ans<<endl;
}

signed main(){
    war();
    int tc=1;
    cin>>tc;
    for(int T=1; T<=tc; T++){
        pikachu(T);
    }
return 0;
}