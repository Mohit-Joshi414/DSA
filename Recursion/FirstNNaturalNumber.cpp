#include <bits/stdc++.h>

using namespace std;

void firstNNumber(int i, int n){
    if(i>n){
        return;
    }
    cout<<i<<" ";
    firstNNumber(i+1,n);
}

int main()
{
    int n;
    cin>>n;
    firstNNumber(1,n);

    return 0;
}
