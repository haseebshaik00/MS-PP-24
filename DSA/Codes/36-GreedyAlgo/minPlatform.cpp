int findPlatform(vector<int>& arr, vector<int>& dep) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
    	sort(dep.begin(), dep.end());
    	int i=1, j=0, platformNeeded=1, maxPlatforms=1;
    	while(i<n && j<n){
    	    if(arr[i] <= dep[j]){
    	        platformNeeded++;
    	        i++;
    	    }
    	    else{
    	        platformNeeded--;
    	        j++;
    	    }
    	    maxPlatforms = max(platformNeeded, maxPlatforms);
    	}
    	return maxPlatforms;
    }