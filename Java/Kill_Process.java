class Solution {
    public List<Integer> killProcess(List<Integer> pid, List<Integer> ppid, int kill) {
        LinkedList<Integer> res = new LinkedList();        
        if (pid.size() != ppid.size()) {
            return res;
        }
        
        // Construct Process Tree
        Map<Integer, List<Integer>> pMap = new HashMap();
        Iterator<Integer> pidIt = pid.iterator(), ppidIt = ppid.iterator();
        while (pidIt.hasNext()) {
            int child = pidIt.next(), parent = ppidIt.next();
            List<Integer> children = pMap.get(parent);
            if (children == null) {
                children = new LinkedList<Integer>();
                pMap.put(parent, children);
            }
            
            children.add(child);
        }
        
        Queue<Integer> toKill = new LinkedList<Integer>();
        toKill.add(kill);
        while (!toKill.isEmpty()) {
            kill = toKill.remove();
            res.add(kill);
            List<Integer> children = pMap.remove(kill);
            if (children != null) {
                for (int child : children) {
                    toKill.add(child);
                }
            }
        }
        
        return res;
    }
}
