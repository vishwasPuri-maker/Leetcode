class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        unordered_set<int> set;

        for(int i =0 ; i<nums.size() ; i++){
            if(set.find(nums[i])!=set.end()){
                ans.push_back(nums[i]);
            }
            else{
                set.insert(nums[i]);
            }
        }
        return ans;
    }
};