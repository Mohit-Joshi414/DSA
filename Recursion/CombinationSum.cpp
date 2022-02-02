#include <bits/stdc++.h>

using namespace std;

void combinationSum(int idx, vector<int> v, vector<int> &t, int n, int target){
    if(idx>=n){
        if(target==0){
            for(int i=0;i<t.size();i++){
                cout<<t[i]<<" ";
            }
            cout<<endl;
        }
        
        return;
    }
    
    if(v[idx]<=target){
        t.push_back(v[idx]);
        combinationSum(idx, v, t, n, target-v[idx]);
        t.pop_back();    
    }
    
    
    combinationSum(idx+1, v, t, n, target);
}

int main()
{
    int n;
    cin>>n;
    vector<int> v;
    int target=0;
    
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        v.push_back(a);
    }
    cin>>target;
    int idx = 0;
    vector<int> t;
    combinationSum(idx,v,t,n, target);

    return 0;
}
