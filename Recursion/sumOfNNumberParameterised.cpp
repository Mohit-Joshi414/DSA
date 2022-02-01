#include <bits/stdc++.h>

using namespace std;

void sumOfNNumber(int n, int sum){
    if(n<1){
        cout<<"The sum of first N natural number: "<<sum;
        return;
    }
    
    return sumOfNNumber(n-1, n+sum);
    
}

int main()
{
    int n;
    cin>>n;
    sumOfNNumber(n, 0);

    return 0;
}
