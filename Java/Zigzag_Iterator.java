public class ZigzagIterator {
    private Iterator<Integer> it1, it2, tmp;

    private void switchIterator() {
        tmp = it1;
        it1 = it2;
        it2 = tmp;
    }
    public ZigzagIterator(List<Integer> v1, List<Integer> v2) {
        it1 = v1.iterator();
        it2 = v2.iterator();
        if (!it1.hasNext()) {
            switchIterator();
        }
    }

    public int next() {
        int ret = it1.next();
        if (it2.hasNext()) {
            switchIterator();
        }
        return ret;
    }

    public boolean hasNext() {
        return it1.hasNext();
    }
}

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i = new ZigzagIterator(v1, v2);
 * while (i.hasNext()) v[f()] = i.next();
 */
