#include <bits/stdc++.h>

using namespace std;

int sumOfNNumber(int n){
    if(n == 0){
        return 0;
    }
    
    return n+sumOfNNumber(n-1);
    
}

int main()
{
    int n;
    cin>>n;
    cout<<"The sum of first N natural number: "<<sumOfNNumber(n);

    return 0;
}
