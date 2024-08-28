#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    char ch[1000] = "au";
    int lastOccured[257] = {-1};
    for(int i=0; i<=256; i++)
        lastOccured[i] = -1;
    int cMax=1, tMax=1;
    lastOccured[ch[0]] = 0;
    int n = strlen(ch);
    for(int i=1; i<n; i++){
        int lastOccurence = lastOccured[ch[i]];
        if(lastOccurence == -1 || (i-cMax) > lastOccurence)
            cMax++;
        else
            cMax = i-lastOccurence;
        tMax = max(cMax, tMax);
        lastOccured[ch[i]-'a'] = i;
    }
    cout<<tMax<<endl;

    return 0;
}
