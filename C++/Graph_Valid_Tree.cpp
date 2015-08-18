class Solution {
public:
    bool validTree(int n, vector<pair<int, int>>& edges) {
        /* BFS */
        if (edges.size() != n-1) return false;
        vector<vector<int>> adj_table (n, vector<int>());
        vector<bool> visited(n, false);
        queue<int> q;
        int cur = 0;
        for (pair<int, int> &e : edges) {
            adj_table[e.first].push_back(e.second);
            adj_table[e.second].push_back(e.first);
        }
        q.push(0);
        while (!q.empty()) {
            cur = q.front();
            q.pop();
            visited[cur] = true;
            for (int v : adj_table[cur]) {
                if (!visited[v]) {
                    q.push(v);
                }
            }
        }
        for (bool isVisited : visited) {
            if (!isVisited) return false;
        }
        return true;
    }
};
