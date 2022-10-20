class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> A;
        vector<int> tmp;
        dfs(A, tmp, root, targetSum);
        return A;
    }
private:
    void dfs(vector<vector<int>>& A, vector<int>& tmp, TreeNode* root, int sum) {
        // base case
        if(root == nullptr) {
            return;
        }
        sum -= root->val;
        tmp.push_back(root->val); 
        if(root->left == nullptr && root->right == nullptr) { // leaf node
            if(sum == 0) {
                A.push_back(tmp);
            }
        }
        // recursion
        dfs(A, tmp, root->left, sum);
        dfs(A, tmp, root->right, sum);
        // backtrack
        tmp.pop_back();
    }
};
