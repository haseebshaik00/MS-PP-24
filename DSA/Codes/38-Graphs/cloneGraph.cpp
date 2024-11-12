Node* cloneGraph(Node* node) {
        if(node == NULL) return NULL;
        unordered_map<int, pair<Node*, bool>> visited;
        Node* n = new Node(node->val);
        queue<Node*> q;
        q.push(node);
        visited[n->val] = make_pair(n, true);
        vector<Node*> v;
        while(!q.empty()){
            Node* temp = q.front();
            q.pop();
            for(auto x: temp->neighbors){
                if(!visited[x->val].second){
                    q.push(x);
                    Node* newNode = new Node(x->val);
                    visited[x->val] = make_pair(newNode, true);
                }
                v.push_back(visited[x->val].first);
            }
            visited[temp->val].first->neighbors = v;
            v.clear();
        }
        return n;
    }