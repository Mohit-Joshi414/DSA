#include <bits/stdc++.h>

using namespace std;

void subSeq(int idx, vector<int> v, vector<int> &t, int n){
    if(idx>=n){
        if(t.size()==0){
            cout<<"{}";
        }
        else{
            for(int i=0;i<t.size();i++){
                cout<<t[i]<<" ";
            }
        }
        cout<<endl;
        return;
    }
    
    t.push_back(v[idx]);
    subSeq(idx+1, v, t, n);
    t.pop_back();
    subSeq(idx+1, v, t, n);
}

int main()
{
    int n;
    cin>>n;
    vector<int> v;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        v.push_back(a);
    }
    int idx = 0;
    vector<int> t;
    subSeq(idx,v,t,n);

    return 0;
}
