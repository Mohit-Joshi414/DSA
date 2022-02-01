#include <bits/stdc++.h>

using namespace std;

void firstNNumberInReverse(int i){
    if(i<1){
        return;
    }
    cout<<i<<" ";
    firstNNumberInReverse(i-1);
}

int main()
{
    int n;
    cin>>n;
    firstNNumberInReverse(n);

    return 0;
}
