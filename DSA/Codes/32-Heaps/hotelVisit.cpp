int main(){
	int q,k;
	cin>>q>>k;
	priority_queue<pair<int,int>,vector<pair<int,int>>,function<bool(pair<int,int >,pair<int,int >)>> pq(check);
	pair<int,int> p;
	int t;
	while(q--){
		cin>>t;
		if(t==1){
			cin>>p.first>>p.second;
            if(pq.size()<k){
		        pq.push(p);
            }
            else if(check(p,pq.top())){
				pq.pop();
				pq.push(p);
			}
		}
		else{
			cout<<(pq.top().first*pq.top().first)+(pq.top().second*pq.top().second)<<endl;
		}
	}
	return 0;
}