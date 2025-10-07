int leastInterval(vector<char>& tasks, int n) {
        int freq[26]; memset(freq, 0, sizeof(freq));
        priority_queue<int> pq;
        queue<pair<int,int>> q;
        int time = 0;
        for(auto &x: tasks) freq[x-'A']++;
        for(int i=0; i<26; ++i) if(freq[i]) pq.push(freq[i]);
        while(!pq.empty() || !q.empty()){
            while(!q.empty() && q.front().second <= time){
                pq.push(q.front().first);
                q.pop();
            }
            if(pq.empty()){ ++time; continue;};
            int curr = pq.top(); pq.pop();
            --curr; ++time;
            if(curr) q.push({curr, time+n});
        }
        return time;
    }