#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    char ch;
    cin>>ch;
    queue<char> q;
    int freq[26] = {0};
    while(ch != '.'){
        q.push(ch);
        freq[ch-'a']++;
        while(!q.empty()){
            int idx = q.front()-'a';
            if(freq[idx]>1)
                q.pop();
            else{
                cout<<q.front()<<" ";
                break;
            }
        }
        if(q.empty())
            cout<<"-1 ";
        cin>>ch;
    }

    return 0;
}
