#include<bits/stdc++.h>

#define int long long
#define double long double

#define war() ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);

using namespace std;

signed main(){
    war();
    int n;  cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){cin>>arr[i];}


    int _25=0;
    int _50=0;

    for(int i=0; i<n; i++){
        if(arr[i]==25){
            _25++;
        }
        else if(arr[i]==50){
            _50++;
            _25--;
        }
        else{
            if(_50>0){
                _50--;
                _25--;
            }
            else{
                _25=_25-3;
            }
        }

        if(_25<0){
            cout<<"NO";
            return 0;
        }
    }
    cout<<"YES";
    return 0;

}