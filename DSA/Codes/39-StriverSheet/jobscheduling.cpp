static bool comp(Job a, Job b){
        return a.profit > b.profit;
    }
    
    vector<int> JobScheduling(Job jobs[], int n) {
        sort(jobs, jobs+n, comp);
        int maxDeadline = 0;
        for(int i=0; i<n; i++)
            maxDeadline = max(maxDeadline, jobs[i].deadline);
        vector<int> v(maxDeadline+1, -1);
        int count=0, profit=0;
        for(int i=0; i<n; i++){
            for(int j=jobs[i].deadline; j>0; j--){
                if(v[j] == -1){
                    v[j] = jobs[i].id;
                    profit += jobs[i].profit;
                    count++;
                    break;
                }
            }
        }
        return {count, profit};
    }