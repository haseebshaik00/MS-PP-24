bool canAttendMeetings(vector<Interval>& intervals) {
        int end = INT_MIN;
        sort(intervals.begin(), intervals.end(), [](const Interval &a, const Interval &b){
            return a.start < b.start;
        });
        for(auto &x: intervals){
            if(x.start < end) return false;
            end = max(end, x.end);
        }
        return true;
    }