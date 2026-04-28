//https://toph.co/arena?practice=6942de81788370566f6b9370#!/p/6937fd4d495ce2269631bd7f

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll LLMin = -1e15;
const ll mod = 1e9 + 7;

#define int ll
#define double long double
#define pb push_back
#define endl "\n"
const double PI=acos(-1);

#define all(x) x.begin(), x.end()

double theta(double x, double y){
    if(x==0){
        if(y>0){return 90.0;}
        else{
            return 270.0;
        }
    }
    if(y==0){
        if(x>0){return 0.0;}
        else{
            return 180.0;
        }
    }

    double ans=180.0/PI;
    if(x>0 && y>0){
        ans=ans*atan2(y,x);
    }
    else if(x<0 && y>0){
        ans*=atan2(-x,y);
        ans+=90.0;
    }
    else if(x<0 && y<0){
        ans*=atan2(-y,-x);
        ans+=180.0;
    }
    else{
        ans*=atan2(x,-y);
        ans+=270.0;
    }
    return ans;
}
#define ff first
#define ss second

vector<pair<int,int>>range;

double three_sixty=360.0;
void xxx(vector<pair<double,int>>&v, double angle_dif, double rad, double area){
    int sz=v.size();
    int zzz=v.size();
    for(int i=0; i<sz; i++){
        v.pb({v[i].ff+360.0, v[i].ss});
    }
}
vector<pair<double,int>>vv;

const int N = 2*(6e5 +21);


int arr1[N],arr2[N];
pair<pair<int,int>,pair<int,int>>tree1[4*N],tree2[4*N];    //{ans,sum},{left,right}

void build1(int node, int st, int en){
    if(st==en){
        tree1[node].ff.ff=arr1[st];
        tree1[node].ff.ss=arr1[st];
        tree1[node].ss.ff=arr1[st];
        tree1[node].ss.ss=arr1[st];
        return;
    }
    int mid=((en-st)/2)+st;
    build1(2*node, st, mid);
    build1(2*node+1, mid+1, en);
    tree1[node].ff.ff=max({tree1[2*node].ff.ff, tree1[2*node+1].ff.ff, tree1[2*node].ss.ss+ tree1[2*node+1].ss.ff});
    tree1[node].ff.ss=tree1[2*node].ff.ss+tree1[2*node+1].ff.ss;
    tree1[node].ss.ff=max(tree1[2*node].ss.ff, tree1[2*node].ff.ss+tree1[2*node+1].ss.ff);
    tree1[node].ss.ss=max(tree1[2*node+1].ss.ss, tree1[2*node+1].ff.ss+tree1[2*node].ss.ss);
}

pair<pair<int,int>,pair<int,int>> query1(int node, int st, int en, int l, int r){
    if(st>r || en<l){return {{LLMin,0},{LLMin,LLMin}};}
    else if(st>=l && en<=r){return tree1[node];}
    int mid=((en-st)/2)+st;
    pair<pair<int,int>,pair<int,int>> q1= query1(2*node, st, mid, l, r);
    pair<pair<int,int>,pair<int,int>> q2= query1(2*node+1, mid+ 1, en, l, r);
    
    int ans=max({q1.ff.ff, q2.ff.ff, q1.ss.ss+q2.ss.ff});
    int sum=q1.ff.ss+q2.ff.ss;
    int left=max(q1.ss.ff, q1.ff.ss+q2.ss.ff);
    int right=max(q2.ss.ss, q2.ff.ss+q1.ss.ss);
    return {{ans,sum},{left,right}};
}

void build2(int node, int st, int en){
    if(st==en){
        tree2[node].ff.ff=arr2[st];
        tree2[node].ff.ss=arr2[st];
        tree2[node].ss.ff=arr2[st];
        tree2[node].ss.ss=arr2[st];
        return;
    }
    int mid=((en-st)/2)+st;
    build2(2*node, st, mid);
    build2(2*node+1, mid+1, en);
    tree2[node].ff.ff=max({tree2[2*node].ff.ff, tree2[2*node+1].ff.ff, tree2[2*node].ss.ss+ tree2[2*node+1].ss.ff});
    tree2[node].ff.ss=tree2[2*node].ff.ss+tree2[2*node+1].ff.ss;
    tree2[node].ss.ff=max(tree2[2*node].ss.ff, tree2[2*node].ff.ss+tree2[2*node+1].ss.ff);
    tree2[node].ss.ss=max(tree2[2*node+1].ss.ss, tree2[2*node+1].ff.ss+tree2[2*node].ss.ss);
}

pair<pair<int,int>,pair<int,int>> query2(int node, int st, int en, int l, int r){
    if(st>r || en<l){return {{LLMin,0},{LLMin,LLMin}};}
    else if(st>=l && en<=r){return tree2[node];}
    int mid=((en-st)/2)+st;
    pair<pair<int,int>,pair<int,int>> q1= query2(2*node, st, mid, l, r);
    pair<pair<int,int>,pair<int,int>> q2= query2(2*node+1, mid+ 1, en, l, r);
    
    int ans=max({q1.ff.ff, q2.ff.ff, q1.ss.ss+q2.ss.ff});
    int sum=q1.ff.ss+q2.ff.ss;
    int left=max(q1.ss.ff, q1.ff.ss+q2.ss.ff);
    int right=max(q2.ss.ss, q2.ff.ss+q1.ss.ss);
    return {{ans,sum},{left,right}};
}




void solve(int test){
    int n;
    
    double radius,area; cin>>n>>radius>>area;
    vector<pair<double,int>>pos;
    range.clear();

    int ans=0;
    for(int i=0; i<n; i++){
        int x,y,val;    cin>>x>>y>>val;
        pos.pb({theta(x,y),val});

    }
    if(pos.size()==0){
        cout<<"0"<<endl; return;
    }
    if(pos.size()==1){
        cout<<abs(pos[0].ss)<<endl; return;
    }
    sort(all(pos));

    vv.clear();
    double x=pos[0].ff;
    int y=pos[0].ss;

    for(int i=1; i<(int)pos.size(); i++){
        if(x==pos[i].ff){
            y+=pos[i].ss;
        }
        else{
            vv.pb({x,y});
            x=pos[i].ff;
            y=pos[i].ss;
        }
    }
    vv.pb({x,y});


    if(vv.size()==1){
        cout<<abs(vv[0].ss)<<endl; return;
    }

    double mx_angle_fid=(360.0*area)/(PI*radius*radius);
    mx_angle_fid = min(three_sixty,mx_angle_fid);
    
    int vb = vv.size();
    xxx(vv, mx_angle_fid, radius, area);

    int size_lagbe=vv.size()-1;
    
    for(int i=0; i<=size_lagbe; i++){
        arr1[i]=vv[i].ss;
        arr2[i]=-vv[i].ss;
    }

    for(int i=0; i<vb; i++){
        int l = i, r = i + vb -1;
        int ind=i;
        while(l<=r){
            int mid = (l+r) >> 1;
            if(vv[mid].ff - vv[i].ff <= mx_angle_fid){
                ind = mid;
                l = mid+1;
            }
            else r = mid-1;
        }
        if(ind != -1){
            range.pb({i, ind});
        }
    }


    build1(1, 0, size_lagbe);
    build2(1, 0, size_lagbe);



    //for(auto u:vv) cout << u.ff << " " << u.ss << endl;
    for(auto [l,r]:range){
        //cout<<l<<" "<<r<<endl;
        if(l>r || r>size_lagbe){continue;}
        auto aaaa=query1(1, 0, size_lagbe, l, r);
        auto bbbb=query2(1, 0, size_lagbe, l, r);
        ans = max({ans,aaaa.ff.ff, bbbb.ff.ff});
        //cout << max(ret.ans[0], ret.ans[1]) << endl;
    }
    cout<<ans<<endl;
    return;
}


signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cout << fixed << setprecision(40);
    int tt = 1;
    cin >> tt;

    for(int i=1; i<=tt; i++){
        solve(i);
    }



    return 0;
}