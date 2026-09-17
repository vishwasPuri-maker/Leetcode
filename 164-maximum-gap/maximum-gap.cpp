class Solution {
public:
    int maximumGap(vector<int>& nums) {
        sort(nums.begin() , nums.end() );
        int n = nums.size();
        int maxDifference = INT_MIN;
        if(n<2){
            return 0;
        }
        for(int i =0 ; i< n-1 ; i++){
            int subtract = nums[i+1] - nums[i];
            maxDifference = max(maxDifference,subtract);
        }
        return maxDifference ;
    }
};