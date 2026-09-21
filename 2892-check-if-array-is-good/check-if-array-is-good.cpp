class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n = *max_element(nums.begin(), nums.end());

        unordered_set<int> st;

        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == n) {
                continue;
            }

            if(st.find(nums[i]) != st.end()) {
                return false;
            }

            st.insert(nums[i]);
        }

        if(st.size() != n - 1) {
            return false;
        }

        int count = 0;

        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == n) {
                count++;
            }
        }

        if(count == 2) {
            return true;
        }
        else {
            return false;
        }
    }
};