class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int tank = 0;
        int goalpost = 0;
        int pos = 0;
        bool reset = true;

        while (true) {
            if (pos == n) {
                pos = 0;
            }
            if (pos == goalpost && !reset) {
                return pos;
            }
            reset = false;

            tank += gas[pos] - cost[pos];
            if (tank < 0) {
                if (pos < goalpost || pos == n - 1) {
                    return -1;
                }
                tank = 0;
                goalpost = pos + 1;
                reset = true;
            }
            ++pos;
        }
    }
};