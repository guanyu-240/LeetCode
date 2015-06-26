class TrieNode {
private:
    char val;
    bool wordEnd;
    TrieNode* children[26];
public:
    // Initialize your data structure here.
    TrieNode(char v, bool we) {
        val = v;
        wordEnd = we;
        for (int i = 0; i < 26; i++){
            children[i] = NULL;
        }
    }
    ~TrieNode(){}
    bool isWordEnd(){ return wordEnd; }
    bool setWordEnd(bool we){ wordEnd = we; }
    bool getVal() { return val; }
    TrieNode* addChild(char c) {
        if (c < 'a' || c > 'z') return NULL;
        if (children[c-'a'] == NULL) {
            children[c-'a'] = new TrieNode(c, false);
        }
        return children[c-'a'];
    }
    TrieNode* findChild(char c) {
        if (c < 'a' || c > 'z') return NULL;
        return children[c-'a'];
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode('\0', false);
    }

    // Inserts a word into the trie.
    void insert(string word) {
        if (word.length() == 0) return;
        TrieNode *current = root;
        for (string::iterator it = word.begin(); it != word.end(); ++it) {
            current = current->addChild(*it);
        }
        current->setWordEnd(true);
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode *current = root;
        for (string::iterator it = word.begin(); it != word.end(); ++it) {
            if ((current = current->findChild(*it)) == NULL){
                return false;
            }
        }
        if (current->isWordEnd()) {
            return true;
        }
        else {
            return false;
        }
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode *current = root;
        for (string::iterator it = prefix.begin(); it != prefix.end(); ++it) {
            if ((current = current->findChild(*it)) == NULL){
                return false;
            }
        }
        return true;
    }

private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");
