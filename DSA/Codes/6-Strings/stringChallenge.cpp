#include<bits/stdc++.h>
using namespace std;

string extractToken(string s, int k){
    char *token = strtok((char*)s.c_str(), " ");
    while(k>1){
        token = strtok(NULL, " ");
        k--;
    }
    return (string)token;
}

int toInt(string a){
    int x=0, p=1;
    for(int i=a.length()-1; i>=0; i--){
        x += (a[i] - '0')*p;
        p *= 10;
    }
    return x;
}

bool numComp(pair<string, string> a, pair<string, string> b){
    string first = a.second;
    string second = b.second;
    return stoi(first) < stoi(second);
    // return toInt(first) < toInt(second);
}

bool lexComp(pair<string, string> a, pair<string, string> b){
    string first = a.second;
    string second = b.second;
    return a<b;
}

bool reverseComp(pair<string, string> a, pair<string, string> b){
    string first = a.second;
    string second = b.second;

    return a<b;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin>>n;
    cin.ignore();
    string str[n], sortOrder, boolMapping;
    for(int i=0; i<n; i++)
        getline(cin, str[i]);
    cin>>k>>boolMapping>>sortOrder;

    pair<string, string> sPair[n];

    for(int i=0; i<n; i++){
        string token = extractToken(str[i], k);
        sPair[i].first = str[i];
        sPair[i].second = token;
    }

    (sortOrder == "numeric")? sort(sPair, sPair+n, numComp) : sort(sPair, sPair+n, lexComp);

    if(boolMapping == "true"){
        for(int i=0; i<n/2; i++)
            swap(sPair[i], sPair[n-1-i]);
    }

    for(int i=0; i<n; i++){
        string s = sPair[i].first;
        cout<<s<<endl;
    }

    return 0;
}
