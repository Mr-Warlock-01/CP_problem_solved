#include<bits/stdc++.h>                                 //DRINK WATER

#define int long long
#define double long double
#define endl "\n"

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define uniq(x) (unique(x.begin(), x.end()) - x.begin())

#define war() ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
#define file() freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);


using namespace std;


const double PI=acos(-1);

int gcd (int a, int b) {if (b == 0){return a;} else{return gcd(b, a % b);}}
int lcm (int a, int b) {return ((a / gcd(a, b)) * b);}








signed main(){
    war();
    int t;  cin>>t;
    while(t--){
        int n;  cin>>n;
        int arr[n+1];
        priority_queue<pair<int,int>> pq;
        pq.push({n,-1});

        for(int i=1; i<=n ; i++){
            int l = (pq.top().second)*(-1);
            int r = l + (pq.top().first) - 1;
            int z;
            if((l+r)%2==0){ z = (l+r)/2;  }
            else{           z = (l+r-1)/2;  }
            arr[z]=i;       pq.pop();

            int aa=(z-l);
            int cc=(r-z);

            if(aa > 0)   {pq.push({ aa , (-1)*l });      }
            if(cc > 0)   {pq.push({ cc , (-1)*(z+1) });   }


        }


        for(int i=1; i<=n; i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;

    }
return 0;
}