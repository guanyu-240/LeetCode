class Solution {
public:
    /*
    Idea: BFS search
    */
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int depth = 1;
        queue<string> wordsQueue;
        unordered_set<string>visited;
        wordsQueue.push(start);
        int remain = 1;
        while (!wordsQueue.empty()) {
            string word = wordsQueue.front();
            wordsQueue.pop();
            remain --;
            //visited.insert(word);
            for (int i = 0; i < word.length(); i ++) {
                char original = word[i];
                for (char c = 'a'; c <= 'z'; c ++){
                    word.replace(i, 1, 1, c);
                    if (word.compare(end) == 0) {
                        return depth + 1;
                    }
                    if (dict.find(word) != dict.end() && visited.find(word) == visited.end()){
                        string newWord(word);
                        wordsQueue.push(newWord);
                        visited.insert(newWord);
                    }
                }
                word.replace(i, 1, 1, original);
            }
            if (remain == 0) {
                remain = wordsQueue.size();
                depth ++;
            }
        }
        return 0;
    }
};
