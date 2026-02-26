#include<bits/stdc++.h>                                         //DRINK WATER

using namespace std;

#define endl "\n"
#define int long long
#define double long double
#define ull unsigned long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define uniq(x) (unique(x.begin(), x.end()) - x.begin())
#define war() ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
#define deci(x) cout << fixed << setprecision(x);

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




int xxx(int a, int x, int l){
    int aaa=1;
    for(int i=1; i<=x; i++){
        aaa*=a;
        if(aaa>l)return -1;
    }
    return aaa;
}
void pikachu(int T){         ///MAIN  (DRINK WATER)
    int  a,b,l;     cin>>a>>b>>l;
    vector<int>v;   int ans_1, ans_2, ans;
    for(int i=0; i<21; i++){
        for(int j=0; j<21; j++){
            ans_1=xxx(a,i,l);
            ans_2=xxx(b,j,l);
            ans=ans_1*ans_2;
            if(ans>l || ans_1==-1 || ans_2==-1){break;}
            else if(l%ans==0){v.push_back(l/ans);}
        }
    }
    sort(all(v));
    ans=uniq(v);
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