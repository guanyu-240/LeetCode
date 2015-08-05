class WordDistance {
public:
    unordered_map<string, vector<int>> word_idx;
    WordDistance(vector<string> words) {
        for (int i = 0; i < words.size(); ++i) {
            word_idx[words[i]].push_back(i);
        }
    }

    int shortest(string word1, string word2) {
        vector<int> idx1 = word_idx[word1], idx2 = word_idx[word2];
        vector<int>::iterator it1 = idx1.begin(), it2 = idx2.begin();
        int ret = INT_MAX;
        while (it1 != idx1.end() && it2 != idx2.end()) {
            ret = min(ret, abs(*it1 - *it2));
            if (*it1 > *it2) ++it2;
            else ++it1;
        }
        return ret;
    }
};


// Your WordDistance object will be instantiated and called as such:
// WordDistance wordDistance(words);
// wordDistance.shortest("word1", "word2");
// wordDistance.shortest("anotherWord1", "anotherWord2");
