class TrieNode {
private:
    char val;
    bool wordEnd;
    TrieNode* children[26];
    TrieNode* parent;
public:
    // Initialize your data structure here.
    TrieNode(char v, bool we) {
        val = v;
        wordEnd = we;
        for (int i = 0; i < 26; i++){
            children[i] = NULL;
        }
        parent = NULL;
    }
    ~TrieNode(){}
    bool isWordEnd(){ return wordEnd; }
    void setWordEnd(bool we){ wordEnd = we; }
    char getVal() { return val; }
    void setParent(TrieNode *p){ parent = p; }
    TrieNode* getParent() { return parent; }
    TrieNode* addChild(char c) {
        if (c < 'a' || c > 'z') return NULL;
        if (children[c-'a'] == NULL) {
            children[c-'a'] = new TrieNode(c, false);
            children[c-'a']->setParent(this);
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

    TrieNode *getRoot() {
        return root;
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

private:
    TrieNode* root;
};
class Solution {
private:
    unordered_set<string> existingWords;
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        existingWords.clear();
        vector<string> ret;
        int m = board.size();
        if (m == 0) return ret;
        int n = board[0].size();
        if (n == 0) return ret;
        Trie *t = new Trie();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for (string word : words) {
            t->insert(word);
        }
        
        for (int x = 0; x < m; x++) {
            for (int y = 0; y < n; y ++) {
                dfs(t->getRoot(), board, m, n, x, y, visited);
            }
        }
        
        for (string word : existingWords) {
            ret.push_back(word);
        }
        return ret;
    }
    
    void dfs(TrieNode *node, vector<vector<char>>& board, 
            int m, int n, int x, int y, vector<vector<bool>> &visited) {
        if (node == NULL || x < 0 || x >= m || y < 0 || y >= n) return;
        if (visited[x][y]) return;
        node = node->findChild(board[x][y]);
        if (node == NULL) return;
        if (node->isWordEnd()) {
            existingWords.insert(constructWord(node));
        }
        visited[x][y] = true;
        dfs(node, board, m, n, x, y+1, visited);
        dfs(node, board, m, n, x, y-1, visited);
        dfs(node, board, m, n, x+1, y, visited);
        dfs(node, board, m, n, x-1, y, visited);
        visited[x][y] = false;
    }
    
    string constructWord(TrieNode *wordEnd) {
        string ret = "";
        while (wordEnd != NULL && wordEnd->getVal() != '\0') {
            ret += wordEnd->getVal();
            wordEnd = wordEnd->getParent();
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};
