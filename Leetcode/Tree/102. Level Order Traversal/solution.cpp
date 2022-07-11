class Solution {
public:
    vector<vector<int>> levelOrder1(TreeNode* root) {
        if(root == nullptr) {
            return {};
        }
        vector<int> tmp;
        vector<vector<int>> res;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            int n = q.size();
            while(n--) {        
                TreeNode* curr = q.front();
                q.pop();
                tmp.push_back(curr->val);
                if(curr->left != nullptr) 
                    q.push(curr->left);
                if(curr->right != nullptr) 
                    q.push(curr->right);
            }
            res.push_back(tmp);
            tmp.clear();
        }
        return res;
    }
    
    vector<vector<int>> levelOrder2(TreeNode* root) {
        if(root == nullptr) {
            return {};
        }
        vector<vector<int>> res;
        vector<int> tmp;
        queue<TreeNode*> q;
        q.push(root);
        q.push(nullptr);
        while(!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();
           
            if(curr == nullptr) {
                res.push_back(tmp);
                tmp.clear();
                if(q.size() == 0)
                    return res;
                q.push(curr);
                continue;
            }
            tmp.push_back(curr->val);
            
            if(curr -> left != nullptr) 
                q.push(curr->left);
            
            if(curr->right != nullptr) 
                q.push(curr->right);
            
            
        }
        return res;
    }
};
