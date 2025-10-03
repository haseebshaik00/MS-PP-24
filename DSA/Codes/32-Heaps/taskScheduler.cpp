int leastInterval(vector<char>& tasks, int n) {
        int freq[26], time=0; memset(freq, 0, sizeof(freq));
        for(auto &x: tasks) freq[x-'A']++;
        priority_queue<int> maxH;
        queue<pair<int, int>> q;
        for(int i=0; i<26; ++i)
            if(freq[i]>0) maxH.push(freq[i]);
        while(!maxH.empty() || !q.empty()){
            while(!q.empty()){
                if(q.front().second <= time){
                    maxH.push(q.front().first);
                    q.pop();
                }
                else break;
            }
            if(maxH.empty()){++time; continue;}
            int curr = maxH.top(); maxH.pop();
            --curr; ++time;
            if(curr) q.push({curr, time+n});
        }
        return time;
    }