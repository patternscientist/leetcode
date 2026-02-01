class Trie {
public:
    unordered_set<string> prefixes;
    unordered_set<string> elements;

    Trie() {
        
    }
    
    void insert(string word) {
        elements.insert(word);
        string prefix = "";
        for (char c : word){
            prefix.push_back(c);
            prefixes.insert(prefix);
        }
    }
    
    bool search(string word) {
        return elements.count(word);
    }
    
    bool startsWith(string prefix) {
        return prefixes.count(prefix);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */