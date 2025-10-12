24:16 mins
// MAP STL
int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;
        map<int, int> m;
        int n = nums.size(), ans = 1, tAns = 1;
        for(int i=0; i<n; i++)
            m[nums[i]]++;
        for(auto x=next(m.begin()); x != m.end(); x++){
            if((x->first) - (prev(x)->first) > 1)
                ans = 1;
            else{
                ans++;
                tAns = max(ans, tAns);
            }
        }
        return tAns;
    }

15:30 mins
// unordered MAP STL

int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> m;
        int n = nums.size();
        for(int i=0; i<n; i++){
            int a = nums[i];
            if(m.count(a)) continue;
            if(!m.count(a-1) && !m.count(a+1))
                m.insert({a, 1});
            else if(m.count(a-1) && m.count(a+1)){
                int len1 = m[a-1];
                int len2 = m[a+1];
                int newCount = len1+len2+1;
                m[a-len1] = newCount;
                m[a+len2] = newCount;
                m[a] = newCount; 
            }
            else if(!m.count(a-1) && m.count(a+1)){
                int newCount = m[a+1]+1;
                m[a] = newCount;
                m[a+newCount-1] = newCount;
            }
            else{
                int newCount = m[a-1]+1;
                m[a] = newCount;
                m[a-newCount+1] = newCount;
            }
        }
        int ans = 0;
        for(auto x:m)
            ans = max(x.second, ans);
        return ans;
    }

// unordered_set

int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        int n = nums.size();
        for(int i=0; i<n; i++)
            s.insert(nums[i]);
        int maxStreak = 0;
        for(int i=0; i<n; i++){
            int x = nums[i], streak=1;
            if(s.find(x-1) == s.end()){
                while(s.find(++x) != s.end())
                    streak++;
            }
            maxStreak = max(streak, maxStreak);
        }
        return maxStreak;
    }

[OR]

int longestConsecutive(vector<int>& nums) {
        int ans = 0;
        unordered_set<int> s(nums.begin(), nums.end());
        for(auto &x: s){
            if(s.count(x - 1)) continue;
            int count = 0, curr = x;
            while(s.count(curr++)) count++;
            ans = max(ans, count);
        }
        return ans;
    }
