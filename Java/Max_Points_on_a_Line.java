/**
 * Definition for a point.
 * class Point {
 *     int x;
 *     int y;
 *     Point() { x = 0; y = 0; }
 *     Point(int a, int b) { x = a; y = b; }
 * }
 */
public class Solution {
    public int maxPoints(Point[] points) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int len = points.length;
        if (len <= 2) return len;
        HashMap <Double, Integer> angleCount = new HashMap<Double, Integer>();
        int samePoints = 0;
        int ret = 0;
        int x = 0, y = 0;
        double angle = 0;
        int maxCurRound = 0;
        for (int i = 0; i < len; i ++) {
            samePoints = 0;
            maxCurRound = 0;
            angleCount.clear();
            for (int j = 0; j < len; j ++) {
                x = points[j].x - points[i].x;
                y = points[j].y - points[i].y;
                if (x == 0 && y == 0) samePoints ++;
                else {
                    angle = (double)x*x/((double)x*x + (double)y*y);
                    if ((x > 0 && y < 0) || (x < 0 && y > 0)) {
                        angle *= -1;
                    }
                    Integer count = angleCount.get(angle);
                    if (count != null) {
                        angleCount.put(angle, count + 1);
                        maxCurRound = Math.max(count+1, maxCurRound);
                    }
                    else {
                        angleCount.put(angle, 1);
                        maxCurRound = Math.max(1, maxCurRound);
                    }
                }
            }
            maxCurRound += samePoints;
            ret = Math.max(maxCurRound, ret);
        }
        return ret;
    }
}
