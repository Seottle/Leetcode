class Trie {
public:
    bool isEnd = false;
    Trie* next[26];
    /** Initialize your data structure here. */
    Trie() {
        memset(next, 0, sizeof(next));
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie* node = this;
        for(int i = 0; i < word.size(); ++i) {
            if(node -> next[word[i] - 'a'] == 0) {
                node -> next[word[i] - 'a'] = new Trie();
            }
            node = node -> next[word[i] - 'a'];
        }
        node -> isEnd = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie* node = this;
        for(int i = 0; i < word.size(); ++i) {
            node = node -> next[word[i] - 'a'];
            if(node == NULL) {
                return false;
            }
        }
        return node -> isEnd;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trie* node = this;
        for(int i = 0; i < prefix.size(); ++i) {
            node = node -> next[prefix[i] - 'a'];
            if(node == NULL) {
                return false;
            }
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