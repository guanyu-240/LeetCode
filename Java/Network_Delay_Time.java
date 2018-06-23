class Solution {
    public int networkDelayTime(int[][] times, int N, int K) {
        Map<Integer, Map<Integer, Integer>> graph = new HashMap();
        // Initialize graph
        for (int[] time : times) {
            Map<Integer, Integer> paths = graph.get(time[0]);
            if (paths == null) {
                paths = new HashMap();
                paths.put(time[1], time[2]);
                graph.put(time[0], paths);
            } else {
                Integer dist = paths.get(time[1]);
                if (dist == null || dist > time[2]) {
                    paths.put(time[1], time[2]);
                }
            }
        }
        
        Map<Integer, Integer> distances = new HashMap();
        Queue<Integer> toProcess = new LinkedList<Integer>();
        toProcess.add(K);
        distances.put(K, 0);
        while (!toProcess.isEmpty()) {
            int cur = toProcess.remove(), dist = distances.get(cur);
            Map<Integer, Integer> paths = graph.get(cur);
            if (paths != null) {
                for (Map.Entry<Integer, Integer> entry : paths.entrySet()) {
                    Integer distTmp = distances.get(entry.getKey());
                    if (distTmp == null || distTmp > dist + entry.getValue()) {
                        distances.put(entry.getKey(), dist + entry.getValue());
                        toProcess.add(entry.getKey());
                    }
                }
            }
        }
             
        if (distances.size() < N) {
            return -1;
        }
        
        int maxDist = 0;
        for (int d : distances.values()) {
            maxDist = Math.max(maxDist, d);
        }
        
        return maxDist;
    }
}
