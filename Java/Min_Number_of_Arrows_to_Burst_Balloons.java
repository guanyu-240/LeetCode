public class Solution {
    public int findMinArrowShots(int[][] points) {
        if (points == null || points.length == 0) {
            return 0;
        }
        Arrays.sort(points, new Comparator<int[]>() {
            public int compare(int[] p1, int[] p2) {
                if (p1[0] == p2[0]) {
                    return p1[1] - p2[1];
                } else {
                    return p1[0] - p2[0];
                }
            }
        });
        int arrows = 1;
        int[] range = {points[0][0], points[0][1]};
        for (int i = 1; i < points.length; ++i) {
            if (points[i][0] <= range[1]) {
                range[0] = points[i][0];
                range[1] = Math.min(points[i][1], range[1]);
            } else {
                range[0] = points[i][0];
                range[1] = points[i][1];
                arrows ++;
            }
        }
        return arrows;
    }
}
