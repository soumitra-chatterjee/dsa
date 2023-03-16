
class ConstructBinaryTreeFromInorderAndPreorder {
    vector<int> _in;
    vector<int> _post;
    unordered_map<int, int> index;
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        _in = inorder;
        _post = postorder;
        TreeNode* root = nullptr;
        int N = inorder.size();
        for(int i = 0; i < N; i++) {
            index[inorder[i]] = i;
        }
        return dfs(root, 0, N-1, N-1);
    }

    TreeNode* dfs(TreeNode* root, int l, int r, int post_index) {
        if(l > r) {
            return nullptr;
        }
        int root_index = index[_post[post_index]];
        root = new TreeNode(_in[root_index]);
        
        int left_size = root_index - l;
        int right_size = r - root_index;

        root->left = dfs(root->left, l, root_index-1, post_index - right_size -1);
        root->right = dfs(root->right, root_index+1, r, post_index - 1);

        return root;
    }
};
