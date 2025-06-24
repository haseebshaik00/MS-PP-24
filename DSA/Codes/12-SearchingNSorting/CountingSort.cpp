#include<bits/stdc++.h>
using namespace std;

void countingSort(int a[], int n){
	// taken care of negative elements
	int maxE = *max_element(a, a+n), minE = *min_element(a, a+n);
	int range = maxE-minE+1;
	int freq[range]={0}, output[n];
	for(int i=0; i<n; i++)
		freq[a[i]-minE]++;
	for(int i=1; i<range; i++)
		freq[i] += freq[i-1];
	for(int i=n-1; i>=0; i--)
		output[--freq[a[i]-minE]] = a[i];
	for(auto x:output)
		cout<<x<<" ";
}

// gfg soln
string countSort(string arr) {
        int count[26]={0}, n=arr.length();
        vector<char> output(n);; string s="";
        for(auto &x: arr) count[x-'a']++;
        for(int i=1; i<26; i++) count[i]+=count[i-1];
        for(int i=n-1; i>=0; --i){
            char c = arr[i];
            output[count[c-'a']-1] = c;
            count[c-'a']--;
        }
        for(auto &x: output) s += x;
        return s;
    }

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin>>n;
	int a[n];
	memset(a, 0, n);
	for(int i=0; i<n; i++)
		cin>>a[i];
	countingSort(a, n);

	return 0;
}
