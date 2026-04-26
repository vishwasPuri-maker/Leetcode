class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        vector<int> result;
        if(n==0){
            return result;
        }
        int count = 1;
        int x=0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            if(i<n-1 && nums[i]==nums[i+1]){
                count=count+1;
            }
            else{
                if (count > n / 3) {
                    result.push_back(nums[i]);
                }
                count=1;
            }
        }
        return result;
    }
};