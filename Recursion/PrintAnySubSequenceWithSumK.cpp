#include <bits/stdc++.h>

using namespace std;

bool subSeq(int idx, vector<int> v, vector<int> &t, int n, int sum, int curr_total){
    if(idx>=n){
        if(sum==curr_total){
            for(int i=0;i<t.size();i++){
                cout<<t[i]<<" ";
            }
            return true;
        }
        
        return false;
    }
    
    t.push_back(v[idx]);
    curr_total += v[idx];
    if(subSeq(idx+1, v, t, n, sum, curr_total))
        return true;
    t.pop_back();
    curr_total -= v[idx];
    if(subSeq(idx+1, v, t, n, sum, curr_total))
        return true;
    return false;
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
    vector<int> t;
    subSeq(idx,v,t,n, sum, curr_total);

    return 0;
}
