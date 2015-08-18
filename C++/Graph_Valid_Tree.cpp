class Solution {
public:
    bool validTree(int n, vector<pair<int, int>>& edges) {
        if (edges.size() != n-1) return false;
        int vertexes[n];
        fill_n(vertexes, n, 0);
        for (pair<int, int> &e : edges) {
            vertexes[e.first] ++;
            vertexes[e.second] ++;
        }
        /* Check if the graph has any isolated edge */
        for (pair<int, int> &e : edges) {
            if (vertexes[e.first] == 1 && vertexes[e.second] == 1 && n > 2) {
                return false;
            }
        }
        /* Check if the graph has any isolated vertex */
        for (int v = 0; v < n; v++) {
            if (vertexes[v] == 0 && n != 1) return false;
        }
        return true;
    }
};
