int findKthLargest(vector<int>& nums, int k) {
        // max heap - O(n + k log n)
        priority_queue<int> pq(nums.begin(), nums.end());
        while(--k) pq.pop();
        return pq.top();

        // min heap of size k - O(n logk) | if k << n then O(n)
        priority_queue<int, vector<int>, greater<int>> pq; // min-heap
        for (int x : nums) {
            pq.push(x);
            if (pq.size() > k) pq.pop(); // drop smallest; keep top-k
        }
        return pq.top();

        // nth_element (average O(n), in-place)
        nth_element(nums.begin(), nums.end() - k, nums.end());
        return nums[nums.size() - k];
    }