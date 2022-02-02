#include <bits/stdc++.h>

using namespace std;

int subSeq(int idx, vector<int> v, int n, int sum, int curr_total){
    if(idx>=n){
        if(sum==curr_total){
            return 1;
        }
        
        return 0;
    }
    
    curr_total += v[idx];
    int l = subSeq(idx+1, v, n, sum, curr_total);
    curr_total -= v[idx];
    int r = subSeq(idx+1, v, n, sum, curr_total);
    return l+r;
}

int main()
{
    int n;
    cin>>n;
    vector<int> v;
    int sum=0;
    
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        v.push_back(a);
    }
    cin>>sum;
    int curr_total=0;
    int idx = 0;
    
    cout<<subSeq(idx,v,n, sum, curr_total);

    return 0;
}
