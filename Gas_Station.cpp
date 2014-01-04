class Solution {
public:
    /*
    Initially, choose a station as as the start station(any station is ok).
    When finding a station j where I can not reach j+1, the starting point should be updated to j+1 and make another try. 
    Because if starting from any station between the start and j, the car can not reach j+1. 
    Proof:
    Available gas when coming from k to j: sum(gas[k:j]) - sum(cost[k:j])
    Available gas when coming from start point to j: sum(gas[start:j]) - sum(cost[start: j])
    Diff = sum(gas[start:k]) - cost[start:k], which is the available gas when coming from start to k
    Since k can be passed, Diff >= 0
    Thus, the available gas when arriving j from k can not be more than the available gas when arriving from starting point to j
    Time complexity:
    The time complexity is theta(n).
    */
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int n = gas.size();
        int gasCost = 0, available = 0;
        bool canComplete = true;
        int i = 0;
        while (i < n){
            gasCost = 0;
            available = 0;
            canComplete = true;
            for (int j = i; j < i + n; j ++){
                available += gas[j%n];
                if (cost[j%n] > available){
                    canComplete = false;
                    i = j + 1;
                    break;
                }
                available -= cost[j%n];
            }
            if (canComplete == true){
                return i;
            }
        }
        return -1;
    }
};
