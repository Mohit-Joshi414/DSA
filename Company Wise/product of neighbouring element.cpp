#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int> v,v1;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        v.push_back(a);
    }
    
    for(int i=0;i<n;i++){
        if(i==0){
            v1.push_back(v[i+1]);
        }
        else if(i==n-1){
            v1.push_back(v[i-1]);
        }
        else{
            v1.push_back(v[i-1]*v[i+1]);
        }
    }
    int l = v1.size();
    for(int i=0;i<l;i++){
        cout<<v1[i]<<" ";
    }
    return 0;
}


i/p - 1 :-

6
2 3 5 2 1 7

o/p - 1 :-

3 10 6 5 14 1