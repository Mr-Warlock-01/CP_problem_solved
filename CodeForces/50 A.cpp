#include <iostream>
using namespace std;
int main(){
    int M, N;
    cin>>M>>N;
    if ((M<=16)&&(M>=1)&&(N<=16)&&(N>=1) && (M<=N)){
        cout<<((M*N)/2);
    }
    return 0;

}