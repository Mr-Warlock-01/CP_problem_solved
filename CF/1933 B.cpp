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

void pikachu(int T){         ///MAIN  (DRINK WATER)
    int n;  cin>>n;
    int mod_1=0, mod_2=0;
    int a,sum=0;
    for(int i=0; i<n; i++){
        cin>>a;   sum+=a;
        if(a%3==1){mod_1++;}
        else if(a%3==2){mod_2++;}
    }
    if(sum%3==0){cout<<"0"<<endl;}
    else if(sum%3==2){cout<<"1"<<endl;}
    else if(sum%3==1 && mod_1!=0 ){cout<<"1"<<endl;}
    else{cout<<"2"<<endl;}

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