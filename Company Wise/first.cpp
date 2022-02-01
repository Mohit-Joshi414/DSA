#include <bits/stdc++.h>

using namespace std;

bool sortByVal(const pair<int, int>& a,const pair<int, int>& b)
{
   if (a.second == b.second) 
       return a.first < b.first;
 
   return a.second > b.second;
}

vector<int> sortByFreq (vector < int >a)
{
  vector<int> res;
  int n = a.size ();
  unordered_map <int, int> m;
  vector<pair<int, int>> v;
  for (int i = 0; i < n; ++i)
    {
      m[a[i]]++;
    }

  copy (m.begin (), m.end (), back_inserter (v));
  sort (v.begin (), v.end (), sortByVal);

  for (int i = 0; i < v.size (); ++i)
    while (v[i].second--)
      {
	res.push_back (v[i].first);
      }

  return res;
}



int
main ()
{
  int n;
  cin >> n;
  vector < int >v, v1;
  map < int, int >m;
  for (int i = 0; i < n; i++)
    {
      int a;
      cin >> a;
      v.push_back (a);
    }
 vector<int>res;
   res = sortByFreq(v);
 
   for(int i = 0;i < res.size(); i++)
         cout<<res[i]<<" ";

  return 0;
}
