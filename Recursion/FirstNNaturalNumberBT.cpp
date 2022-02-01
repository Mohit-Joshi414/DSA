#include <bits/stdc++.h>

using namespace std;

void firstNNumberBT(int n){
    if(n<1){
        return;
    }
    
    firstNNumberBT(n-1);
    cout<<n<<" ";
}

int main()
{
    int n;
    cin>>n;
    firstNNumberBT(n);

    return 0;
}
