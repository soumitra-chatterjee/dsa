
class Solution {
public:
    int pathSum(TreeNode* root, int targetSum) {
        if(root == nullptr) {
            return 0;
        }
        int count = 0;
        long sum = 0;
        findSum(root, count, targetSum);
        return count + pathSum(root->left, targetSum) + pathSum(root->right, targetSum);
    }
    
    void findSum(TreeNode* root, int& count, long sum) {
        if(root == nullptr) {
            return;
        }
        sum -= root->val;
        if(sum == 0) {
            count ++;
        }
        findSum(root->left, count, sum);
        findSum(root->right, count, sum);
    }
};

class Solution {
public:
    int pathSum(TreeNode* root, int targetSum) {
        if(root == nullptr) {
            return 0;
        }
        return findSum(root, targetSum) + pathSum(root->left, targetSum) + pathSum(root->right, targetSum);
    }
    
    int findSum(TreeNode* root, long target) {
        if(root == nullptr) {
            return 0;
        }
        int leftCount = findSum(root->left, target - root->val);
        int rightCount = findSum(root->right, target - root->val);
        int res = leftCount + rightCount;
        if(root->val == target) {
            res++;
        }
        
        return res;
    }
};
