// Using an extra array in the first approach, we
// return the (k-1) index element in our inOrder traversal
// In the second approach
// instead of using an array, we directly return 
// the element that falls on kth inOrder Traversal


class Solution1 {
   vector<int> arr;
public:
    int kthSmallest(TreeNode* root, int k) {
        inOrder(root);
        return arr[k-1];
    }
private:
    void inOrder(TreeNode* root) {
        if(root != nullptr) {
            inOrder(root->left);
            arr.push_back(root->val);
            inOrder(root->right);
        } 
    }
};


class Solution2 {  
public:
    int kthSmallest(TreeNode* root, int &k) {
        if(root == nullptr) {
            return 0;
        }
        int leftValue = kthSmallest(root->left, k);
        if(leftValue != 0) {
            return leftValue;
        }
        k--;
        if(k == 0) {
            return root->val;
        }
        int rightValue = kthSmallest(root->right, k);
        if(rightValue != 0) {
            return rightValue;
        }
        return 0;
    }
};
