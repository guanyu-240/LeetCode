public class MovingAverage {
    private Queue<Integer> numbers;
    private int size;
    private long sum;
    /** Initialize your data structure here. */
    public MovingAverage(int size) {
        this.numbers = new LinkedList<Integer>();
        this.size = size;
        this.sum = 0;
    }
    
    public double next(int val) {
        if (size == 0) return 0;
        if (numbers.size() == size) {
            sum -= numbers.poll();
        }
        sum += val;
        numbers.add(val);
        return sum/(1.0*numbers.size());
    }
}

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage obj = new MovingAverage(size);
 * double param_1 = obj.next(val);
 */
