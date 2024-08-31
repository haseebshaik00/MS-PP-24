int checkRedundancy(string s1) {
		int n = s1.length(), c;
		stack<char> s;
		for(int i=0; i<n; i++){
			char c = s1[i];
			if(s.empty() || c!=')') s.push(c);
			else{
			    c=0;
				while(s.top()!='('){
					if(s.top() == '*' || s.top() == '/' || s.top() == '+' || s.top()=='-') c=1;
					s.pop();
				}
				if(c==0) return 1;
				s.pop();
			}
		}
		return 0;
    }