#include<bits/stdc++.h>                                 //DRINK WATER
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define int long long
#define double long double
#define ull unsigned long long
#define endl "\n"

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define uniq(x) (unique(x.begin(), x.end()) - x.begin())

#define war() ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);

const double PI=acos(-1);
const int MOD= 1e9+7;

int gcd (int a, int b){if(b==0){return a;} else{return gcd(b,a%b);}}
int lcm (int a, int b){return ((a/gcd(a,b))*b);}
bool isPalindrome(string s) {int i=0, j=s.size()-1; for(i, j; i<=j; i++, j--){if(s[i]!=s[j]) return 0;} return 1;}
bool IsPrime(int n) {for(int i=2; i*i<= n; i++)if ((n%i)==0){return false;} return true;}
bool isPowerofTwo(int n){return (n && !(n & (n - 1)));}
//int lastbit(int n){bitset<64>x(n); for(int i=63; i>=0; i--)if(x[i]==1)return i; return 0;}
//int PowMod(int x, int n){int ret = 1; int a = x; while (n > 0) {if (n & 1) ret = 1ll * ret * a % MOD; a = 1ll * a * a % MOD; n >>= 1;} return ret;}
int digitSum(int a) {int sum=0; for(int i=a; i>0; i/=10){sum+=(i%10);} return sum;}
int fact(int n){if(n==0)return 1; int res=1; for(int i=2; i<=n; i++){res*=i;} return res;}
//int nCr(int n, int r){return fact(n)/(fact(r)*fact(n-r));}


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

template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;              // .order_of_key(x)         // *.find_by_order(x)
template <typename T> using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag,tree_order_statistics_node_update>;

#define YES {cout<<"YES"<<endl;}
#define NO  {cout<<"NO"<<endl;}

///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE

int lol(int n){
    return ((n*(n-1))/2);
}

void pikachu(){         //solve
    int n;  cin>>n;
    int arr[n];     for(int i=0; i<n; i++){cin>>arr[i];}
    int flag=LONG_MAX,   index=0;

    for(int i=1; i<101; i++){
        int sum=0;
        for(int j=0; j<n; j++){
            int haha=abs(arr[j]-i)-1;
            if(haha>0){sum+=haha;}
        }
        if(sum<flag){index=i;   flag=sum;}
    }
    cout<<index<<" "<<flag;
}




signed main(){
    war();
    int tc=1;
    //cin>>tc;
    while(tc--){
        pikachu();
    }
return 0;
}