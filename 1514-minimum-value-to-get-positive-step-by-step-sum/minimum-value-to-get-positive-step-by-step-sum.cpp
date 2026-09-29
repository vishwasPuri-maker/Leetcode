class Solution {
public:
    int minStartValue(vector<int>& nums) {
        for(int i =1 ; i<nums.size() ; i++){
            nums[i] = nums[i] + nums[i-1];
        }
        int minn = 0;
        for(int i = 0 ; i<nums.size() ; i++){
            minn = min(minn,nums[i]);
        }
        int positive = abs(minn);
        return positive+1;
    }
};