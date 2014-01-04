class Solution {
public:
    /*
    Idea: always keeping track of maximum distance covered by a specific number of steps.
    Originally, 0 steps will cover the distance of 0
    */
    int jump(int A[], int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int numSteps = 0;
        int distCovered = 0;
        int distCoveredNext = 0;
        for (int i = 0; i < n; i ++){
            if (distCovered >= n - 1){
                return numSteps;
            }
            if (i > distCovered){ 
                // if position i is not covered, one more step are needed to cover the current point
                // the maximum 'one more step' distance is already calculated before, therefore what should
                // do in this case is to increment the step count by 1 and update the distance
                distCovered = distCoveredNext;
                numSteps ++;
            }
            // update maximum distance of one more step
            distCoveredNext = max(distCoveredNext, A[i] + i);
        }
        return numSteps;
    }
};
