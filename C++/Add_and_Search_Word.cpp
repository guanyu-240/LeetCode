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


class WordDictionary {
private:
    TrieNode *root;
public:
    WordDictionary() {
        root = new TrieNode('\0', false);
    }
    // Adds a word into the data structure.
    void addWord(string word) {
        if (word.length() == 0) return;
        TrieNode *current = root;
        for (string::iterator it = word.begin(); it != word.end(); ++it) {
            current = current->addChild(*it);
        }
        current->setWordEnd(true);
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        return searchHelper(root, word, 0);
    }
    bool searchHelper(TrieNode *current, string word, int index){
        if (current != NULL && current->isWordEnd() && index == word.length()) return true;
        if (current == NULL || index == word.length()) return false;
        TrieNode *next = NULL;
        if (word[index] == '.') {
            for (char c = 'a'; c <= 'z'; c++) {
                next = current->findChild(c);
                if (searchHelper(next, word, index+1)){
                    return true;
                }
            }
        }
        else {
            next = current->findChild(word[index]);
            return searchHelper(next, word, index+1);
        }
    }
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");
