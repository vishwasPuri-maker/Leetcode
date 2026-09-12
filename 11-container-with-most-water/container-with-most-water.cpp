class Solution {
public:
    int maxArea(vector<int>& nums) {
       int i =0;
       int j = nums.size()-1;
       int maxValue = INT_MIN;
       while(i<j){
        int width = j-i;
        int height = min(nums[i],nums[j]);
        int area = height * width ;
        maxValue = max(maxValue , area);
        if(nums[i]<nums[j]){
            i++;
        }
        else{
            j--;
        }
       }
       return maxValue;
    }
};