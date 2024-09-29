#include <bits/stdc++.h> 
typedef pair<int, pair<int, int>> kPair;

vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    vector<int> v;
    priority_queue<kPair, vector<kPair>, greater<kPair>> p;
    for(int i=0; i<k; i++)
        p.push({kArrays[i][0], {i, 0}});
    while(!p.empty()){
        kPair curr = p.top();
        p.pop();
        int i = curr.second.first, y=curr.second.second;
        v.push_back(curr.first);
        if(y+1<kArrays[i].size())
          p.push({kArrays[i][y + 1], {i, y + 1}});
    }
    return v;
}
