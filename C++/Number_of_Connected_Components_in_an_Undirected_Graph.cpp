class Solution {
public:
    int countComponents(int n, vector<pair<int, int>>& edges) {
        int root[n];
        for (int v = 0; v < n; ++v) { root[v] = v; }
        int r1 = -1, r2 = -1;
        int ret = n;
        for (pair<int, int> &e : edges) {
            r1 = find(root, n, e.first);
            r2 = find(root, n, e.second);
            if (r1 != r2) {
                root[r2] = r1;
                ret --;
            }
        }
        return ret;
    }
    
    int find(int root[], int n, int x) {
        while (root[x] != x) {
            x = root[x];
        }
        return x;
    }
};
