class LevelSum {
    const int INF = 1e6;
public:
    int maxLevelSum(TreeNode* root) {
        int level = 1, res = 0;
        int maxLevelSum = -INF;
        queue<TreeNode*> q;
        q.push(root);
        while(q.empty() == false) {
            int k = q.size();
            int levelSum = 0;
            while(k--) {
                TreeNode* cur = q.front();
                q.pop();
                levelSum += cur->val;
                if(cur->left != nullptr) {
                    q.push(cur->left);
                }
                if(cur->right != nullptr) {
                    q.push(cur->right);
                }
            }
            if(levelSum > maxLevelSum) {
                res = level;
                maxLevelSum = levelSum;
            }
            level++;
        } 
        return res;
    }
};

