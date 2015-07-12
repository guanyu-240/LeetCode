class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        /*
        Topological Sort
        */
        vector<vector<int>> adjList(numCourses, vector<int>());
        vector<int>countIncoming(numCourses, 0);
        queue<int> q;
        int tmpCourse;
        vector<int> ret;
        
        for (pair<int, int> p : prerequisites) {
            adjList[p.second].push_back(p.first);
            countIncoming[p.first] ++;
        }
        for (int i = 0; i < numCourses; i ++) {
            if (countIncoming[i] == 0) {
                q.push(i);
            }
        }
        
        while (!q.empty()) {
            tmpCourse = q.front();
            q.pop();
            ret.push_back(tmpCourse);
            for (int m : adjList[tmpCourse]) {
                countIncoming[m] --;
                if (countIncoming[m] == 0) {
                    q.push(m);
                }
            }
        }
        
        for (int i = 0; i < numCourses; i ++) {
            if (countIncoming[i] > 0) {
                ret.clear();
                break;
            }
        }
        return ret;
    }
};
