//here I have used comp function to compare if nodes are at same level then take the node first who has greater value
//for storing level I used the concept of level order traversal

class Solution {
public:
    static bool comp(const pair<TreeNode*,int> &t1,const pair<TreeNode*,int> &t2)
{
     if(t1.second==t2.second)
         return t1.first->val<t2.first->val;
    return (t1.second < t2.second);
}
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
         map< int,vector<pair <TreeNode*,int> >> m;
        int hd=0;
        m[0].push_back({root,0});
         queue<pair<TreeNode*,int>> q;
        q.push({root,hd});
         q.push({NULL,NULL});
        int level=0;
        while(!q.empty()){
           pair<TreeNode*,int> temp=q.front();
            q.pop();
            if(temp.first!=NULL){
            int hd=temp.second;
            
            TreeNode* node=temp.first;
            if(node->left)
             {  q.push({node->left,hd-1});
                m[hd-1].push_back({node->left,level});
             }
            if(node->right)
              {  q.push({node->right,hd+1});
                m[hd+1].push_back({node->right,level});
              }
            }
            else{
                q.push({NULL,NULL});
                level++;
                if(q.front().first==NULL)
                  break;
            }
             
        }
        
          vector<vector<int>> v;
         int i=0;
        for(auto it=m.begin();it!=m.end();it++)
        {
            vector<int> t;
           
            sort(it->second.begin(),it->second.end(),comp);
           
            
            for(auto tree :it->second)
            { 
               t.push_back(tree.first->val);
            }
            v.push_back(t);
            
        }
        return v;
        
    }
};
