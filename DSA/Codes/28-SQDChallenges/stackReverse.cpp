#include<bits/stdc++.h>
using namespace std;

void transfer(stack<int> &s1, stack<int> &s2, int n){
	for(int i=0; i<n; i++){
		s2.push(s1.top());
		s1.pop();
	}
}

void reverseStack(stack<int> &s){
	stack<int> s1;
	int n = s.size(), d;
	for(int i=0; i<n; i++){
		d = s.top();
		s.pop();
		transfer(s, s1, n-1-i);
		s.push(d);
		transfer(s1, s, n-1-i);
	}
}

void insertAtBottom(stack<int> &s, int d){
	if(s.empty()){
		s.push(d);
		return;
	}
	int x = s.top();
	s.pop();
	insertAtBottom(s, d);
	s.push(x);
}

void reverseStackRec(stack<int> &s){
	if(s.empty())
		return;
	int d = s.top();
	s.pop();
	reverseStackRec(s);
	insertAtBottom(s, d);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, d;
	cin>>n;
	stack<int> s;
	for(int i=0; i<n; i++){
		cin>>d;
		s.push(d);
	}
	reverseStackRec(s);
	while(!s.empty()){
		cout<<s.top()<<endl;
		s.pop();
	}

	return 0;
}