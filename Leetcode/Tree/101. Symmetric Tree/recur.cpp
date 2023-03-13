class SymmetricTree {
public:
    bool isSymmetric(TreeNode* root) {
        if(root == nullptr) {
            return false;
        }
        return dfs(root->left, root->right);
    }

    bool dfs(TreeNode* a, TreeNode* b) {
        if(a == nullptr && b == nullptr) {
            return true;
        }
        if(a == nullptr || b == nullptr) {
            return false;
        }
        
        if(a->val == b->val) {
            return dfs(a->left, b->right) && dfs(a->right, b->left);
        } 

        return false;
    }
};
