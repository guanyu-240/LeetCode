/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    /*
     * For each point, let it be (0, 0).
     * Calculate the angle of every other point relative to the point.
     */
    int maxPoints(vector<Point> &points) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int len = points.size();
        if (len <= 2) {
            return len;
        }
        unordered_map<double, int>angleCount;
        unordered_map<double, int>::iterator it;
        int samePoints = 0;
        int x = 0, y = 0;
        double angle = 0;
        int ret = 0, maxCurRound = 0;
        for (int i = 0; i < len; i ++) {
            maxCurRound = 0;
            samePoints = 0; 
            angleCount.clear();
            for (int j = 0; j < len; j ++) {
                x = points[j].x - points[i].x;
                y = points[j].y - points[i].y;
                if (x == 0 && y == 0) {
                    samePoints ++;
                }
                else{
                    angle = 1.0/(1.0 + (double)(y*y)/(double)(x*x)); // to maximize the accuracy of the angle value
                    if ((x < 0 && y > 0) || (x > 0 && y < 0)) {
                        angle *= -1;
                    }
                    it = angleCount.find(angle);
                    if (it == angleCount.end()){
                        angleCount[angle] = 1;
                        maxCurRound = max(maxCurRound, 1);
                    }
                    else {
                        it->second = it->second + 1;
                        maxCurRound = max(maxCurRound, it->second);
                    }
                }
            }
            maxCurRound += samePoints;
            ret = max(ret, maxCurRound);
        }
        return ret;
    }
};
