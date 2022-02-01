#include <bits/stdc++.h>

using namespace std;

void firstNNumberInReverseBT(int i, int n){
    if(i>n){
        return;
    }
    
    firstNNumberInReverseBT(i+1,n);
    cout<<i<<" ";
}

int main()
{
    int n;
    cin>>n;
    firstNNumberInReverseBT(1,n);

    return 0;
}
