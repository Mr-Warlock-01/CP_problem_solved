#include<bits/stdc++.h>
using namespace std;
int main(){
int ub;
cin>>ub;

vector <int> v;

for(int i=2;i<=ub; i++){
    int r=sqrt(i);
    int zzz=0;
    for(int j=2; j<=r; j++){
        if(i%j==0){
            zzz++;
        }
    }
    if(zzz==0){
        v.push_back(i);
    }
}

int s=v.size();
int ans=0;
for(int i=6; i<=ub; i++){
    int co=0;
    for(int j=0; j<s; j++){
        if(i%v[j]==0){
            co++;
        }
    }
    if(co==2){
        ans++;
    }

}

cout<<ans<<endl;

return 0;
}