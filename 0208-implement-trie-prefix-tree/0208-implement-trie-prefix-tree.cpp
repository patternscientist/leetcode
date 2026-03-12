class Trie {
    struct Node{
        int end = false;
        array<Node*,26> nxt{}; // don't forget the curly brackets!
        Node() = default;
    };

    Node* root;

public:
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* cur = root;
        for (char ch : word){
            int i = ch-'a';
            if (!cur->nxt[i])
                cur->nxt[i] = new Node();
            cur = cur->nxt[i];
        }
        cur->end = true;
    }
    
    bool search(string word) {
        Node* cur = root;
        for (char ch : word){
            int i = ch-'a';
            if (!cur->nxt[i])
                return false;
            cur = cur->nxt[i];
        }
        return cur->end;
    }
    
    bool startsWith(string prefix) {
        Node* cur = root;
        for (char ch : prefix){
            int i = ch-'a';
            if (!cur->nxt[i])
                return false;
            cur = cur->nxt[i];
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