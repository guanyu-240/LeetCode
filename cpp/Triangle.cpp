class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int size = triangle.size();
        if (size == 0){
            return 0;
        }
        int minPaths[size];
        int i, j;
        for (i = size - 1; i >= 0; i --){ // scan from bottom to top
            // store the shortest path to every node of this level into minPaths
            for (j = 0; j <= i; j ++){
                if (i == size - 1) {
                    minPaths[j] = triangle[i][j];
                }
                else {
                    minPaths[j] = min(minPaths[j], minPaths[j + 1]) + triangle[i][j];
                }
            }
        }
        return minPaths[0];
    }
};
