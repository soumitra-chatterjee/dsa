
class RightView {
public:
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*> q;
        if(root != nullptr) {
            q.push(root);
        }
        vector<int> res;
        while(!q.empty()) {
            int n = q.size();
            while(n--) {
                TreeNode* cur = q.front();
                q.pop();
                if(n == 0) {
                    res.push_back(cur->val);
                }
                if(cur -> left != nullptr) {
                    q.push(cur->left);
                }
                if(cur->right != nullptr) {
                    q.push(cur->right);
                }
            }
        }
        return res;
    }
};
