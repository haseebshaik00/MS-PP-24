    #include<bits/stdc++.h>
    using namespace std;

    int main(){
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int n, w;
        cin>>n>>w;
        vector<int> v(w), dp(w+1, INT_MAX);
        dp[0] = 0;
        for(int i=0; i<w; i++)
            cin>>v[i];
        for(int i=1; i<=w; i++){
            if(v[i-1] == -1)
                continue;
            for(int j=i; j<=w; j++)
                if(j-i >= 0) // dp[j - i] != INT_MAX
                    dp[j] = min(dp[j], v[i-1] + dp[j-i]);
        }
        if(dp[w]==INT_MAX) cout<<-1;
        else cout<<dp[w];

        return 0;
    }