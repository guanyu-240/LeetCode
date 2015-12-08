// Java Iterator interface reference:
// https://docs.oracle.com/javase/8/docs/api/java/util/Iterator.html
class PeekingIterator implements Iterator<Integer> {
    private Iterator<Integer> it;
    private Integer nextVal;
	public PeekingIterator(Iterator<Integer> iterator) {
	    // initialize any member here.
	    this.it = iterator;
	    nextVal = it.hasNext() ? it.next() : null;
	}

    // Returns the next element in the iteration without advancing the iterator.
	public Integer peek() {
        return nextVal;
	}

	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	@Override
	public Integer next() {
	    Integer ret = nextVal;
	    nextVal = it.hasNext() ? it.next() : null;
	    return ret;
	}

	@Override
	public boolean hasNext() {
	    return nextVal != null;
	}
}
