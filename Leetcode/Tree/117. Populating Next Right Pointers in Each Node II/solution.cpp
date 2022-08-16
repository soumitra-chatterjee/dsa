class Solution {
public:
    Node* connect(Node* root) {
        if(root == nullptr) {
            return root;
        }
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty()) 
        {
            int len = q.size();
            while(len--) 
            {
                Node* cur = q.front();
                q.pop();
                
                if(len == 0) {
                    cur -> next = nullptr;
                }
                else {
                    cur -> next = q.front();
                }
                
                if(cur -> left) {
                    q.push(cur -> left);
                }
                if(cur -> right) {
                    q.push(cur -> right);
                }
            }
        }
        return root;
    } 
};
