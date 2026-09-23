class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        unordered_map<int,int> map;
        vector<int> ans;
        for(int i = 0 ; i<nums.size() ; i++){
            map[nums[i]]++;
        }

        for(auto x : map){
            if(x.second==2){
                ans.push_back(x.first);
            }
        }

        for(int i =1 ; i<=nums.size() ; i++){
            if(map[i]==0){
                ans.push_back(i);
            }
        }
        return ans;
    }
};