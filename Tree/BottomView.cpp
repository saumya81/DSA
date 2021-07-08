// Given a binary tree, print the bottom view from left to right.
// A node is included in bottom view if it can be seen when we look at the tree from bottom.



vector <int> bottomView(Node *root) {
        // Your Code Here
        map<int,vector<Node*>> m;
        queue<pair<Node*,int>> q;
        q.push({root,0});
        m[0].push_back(root);
        while(!q.empty())
        {
            Node* n=q.front().first;
            int hd=q.front().second;
            q.pop();
            if(n->left)
            {
                q.push({n->left,hd-1});
                m[hd-1].push_back(n->left);
            }
            if(n->right)
            {
                q.push({n->right,hd+1});
                m[hd+1].push_back(n->right);
            }
            
        }
        vector<int> v;
        for(auto it=m.begin();it!=m.end();it++)
        {
            v.push_back(it->second.back()->data);
        }
        return v;
        
        
    }
