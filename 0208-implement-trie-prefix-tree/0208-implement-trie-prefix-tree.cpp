class Trie {
    struct Node{
        int end = false;
        array<Node*,26> next{};
        Node() = default;
    };

    Node* root;

public:
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* cur = root;
        int i;
        for (char c : word){
            i = c - 'a';
            if (!cur->next[i]) cur->next[i] = new Node();
            cur = cur->next[i];
        }
        cur->end = true;
    }
    
    bool search(string word) {
        Node* cur = root;
        int i;
        for (char c : word){
            i = c - 'a';
            if (!cur->next[i]) return false;
            cur = cur->next[i];
        }
        return cur->end;
    }
    
    bool startsWith(string prefix) {
        Node* cur = root;
        int i;
        for (char c : prefix){
            i = c - 'a';
            if (!cur->next[i]) return false;
            cur = cur->next[i];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */