//1st way

#include <bits/stdc++.h>

using namespace std;

void subSeq(int idx, vector<int> v, vector<int> &t, int n, int sum){
    if(idx>=n){
        int curr_total = 0;
        for(int i=0;i<t.size();i++){
            curr_total+=t[i];
        }
        if(curr_total == sum){
            for(int i=0;i<t.size();i++){
                cout<<t[i]<<" ";
            }
            cout<<endl;
        }
        
        
        return;
    }
    
    t.push_back(v[idx]);
    
    subSeq(idx+1, v, t, n, sum);
    t.pop_back();
    
    subSeq(idx+1, v, t, n, sum);
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
    subSeq(idx,v,t,n, sum);

    return 0;
}



// 2nd way


#include <bits/stdc++.h>

using namespace std;

void subSeq(int idx, vector<int> v, vector<int> &t, int n, int sum, int curr_total){
    if(idx>=n){
        if(sum==curr_total){
            for(int i=0;i<t.size();i++){
                cout<<t[i]<<" ";
            }
            cout<<endl;
        }
        
        return;
    }
    
    t.push_back(v[idx]);
    curr_total += v[idx];
    subSeq(idx+1, v, t, n, sum, curr_total);
    t.pop_back();
    curr_total -= v[idx];
    subSeq(idx+1, v, t, n, sum, curr_total);
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
