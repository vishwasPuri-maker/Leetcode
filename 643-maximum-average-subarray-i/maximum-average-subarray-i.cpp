class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double prevSum = 0;
        int n = nums.size();
        double maxAvg = INT_MIN;

        for(int i = 0; i < k; i++){
            prevSum += nums[i];
        }

        maxAvg = prevSum;

        int first = 1;
        int last = k;
        double currSum = 0;

        while(last < n){
            currSum = prevSum + nums[last] - nums[first - 1];

            maxAvg = max(maxAvg, currSum);

            prevSum = currSum;
            first++;
            last++;
        }

        return maxAvg / k;
    }
};