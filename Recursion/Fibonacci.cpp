#include <bits/stdc++.h>

using namespace std;

int fibnoccai(int n){
    if(n<=1){
        return n;
    }
    
    return fibnoccai(n-1)+fibnoccai(n-2);
}

int main()
{
    int n;
    cin>>n;
    
    cout<<fibnoccai(n);

    return 0;
}
