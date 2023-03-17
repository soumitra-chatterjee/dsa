class Node {
public:
    bool isEnd;
    vector<Node*> children;
    Node() {
        isEnd = false;
        children = vector<Node*> (26, nullptr);
    }
};
class Trie {
    Node* root = nullptr;
public:
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* tmp = root;
        for(char c: word) {
            int charIndex = c - 'a';
            if(tmp->children[charIndex] == nullptr) { 
                tmp->children[charIndex] = new Node();
            }
            tmp = tmp->children[charIndex];
        }
        tmp->isEnd = true;
    }
    
    bool search(string word) {
        Node* tmp = root;
        for(char c: word) {
            int charIndex = c - 'a';
            if(tmp->children[charIndex] == nullptr) {
                return false;
            }
            tmp = tmp->children[charIndex];
        }
        if(tmp->isEnd == true) {
            return true;
        }
        return false;
    }
    
    bool startsWith(string prefix) {
        Node* tmp = root;
        for(char c: prefix) {
            int charIndex = c - 'a';
            if(tmp->children[charIndex] == nullptr) {
                return false;
            }
            tmp = tmp->children[charIndex];
        }
        return true;
    }
};

