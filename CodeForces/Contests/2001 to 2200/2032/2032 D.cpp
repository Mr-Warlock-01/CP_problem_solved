#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;  cin>>t;
    while(t--){
        int n;  cin>>n;

        vector<int>par(n);
        priority_queue<int,vector<int>,greater<int>>pq;
        pq.push(1);

        int i=2;
        for( ;i<n; i++){
            cout<<"? 1 "<<i<<endl;
            int x;  cin>>x;
            pq.push(i);
            if(x==0){par[i]=1;  pq.pop(); break;}
        }
        i++;
        while(i<n){
            if(pq.size()==1){break;}
            cout<<"? "<<pq.top()<<" "<<i<<endl;
            int x;  cin>>x;
            if(x==0){par[i]=pq.top();   pq.push(i); i++;}
            pq.pop();
        }

        while(i<n){par[i]=i-1; i++;}

        cout<<"! ";
        for(int i=1; i<n; i++){cout<<par[i]<<" ";}
    }
}