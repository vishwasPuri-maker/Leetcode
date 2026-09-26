class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        // vector<int> ans;
        // unordered_set<int> set;

        // for(int i =0 ; i<nums.size() ; i++){
        //     if(set.find(nums[i])!=set.end()){
        //         ans.push_back(nums[i]);
        //     }
        //     else{
        //         set.insert(nums[i]);
        //     }
        // }
        // return ans;
        // Yes this is the one solution to solve this question but this is taking the extra space so now were solve this with no extra space 

        vector<int> ans;
        for(int i=0; i<nums.size() ; i++){
            int index = abs(nums[i])-1;
            if(nums[index]<0){
                ans.push_back(index+1);
            }
            nums[index] = nums[index]*-1;
        }
        return ans;
    }
};