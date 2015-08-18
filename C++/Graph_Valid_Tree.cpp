class Solution {
public:
    bool validTree(int n, vector<pair<int, int>>& edges) {
        if (edges.size() != n-1) return false;
        vector<unordered_set<int>> adj_table (n, unordered_set<int>());
        vector<bool> visited(n, false);
        queue<int> q;
        int cur = 0;
        for (pair<int, int> &e : edges) {
            adj_table[e.first].insert(e.second);
            adj_table[e.second].insert(e.first);
        }
        q.push(0);
        while (!q.empty()) {
            cur = q.front();
            if (visited[cur]) return false;
            q.pop();
            visited[cur] = true;
            for (int v : adj_table[cur]) {
                adj_table[v].erase(cur);
                q.push(v);
            }
        }

        return true;
    }
};
