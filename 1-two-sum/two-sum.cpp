class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       vector<int> ans;
       unordered_map<int,int> mp;
       for(int i = 0 ; i<nums.size() ; i++){
        int rem = target - nums[i];
        if(mp.find(rem) != mp.end()){
            ans.push_back(mp[rem]);
            ans.push_back(i);
        }
        else{
            mp[nums[i]]=i;
        }
       }
       return ans;
    }
};