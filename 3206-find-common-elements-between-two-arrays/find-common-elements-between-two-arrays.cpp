class Solution {
public:
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> map1;
        unordered_map<int, int> map2;

        for(int i = 0; i < nums1.size(); i++) {
            map1[nums1[i]]++;
        }

        for(int i = 0; i < nums2.size(); i++) {
            map2[nums2[i]]++;
        }

        int count1 = 0;
        int count2 = 0;

        for(int i = 0; i < nums1.size(); i++) {
            if(map2[nums1[i]] > 0) {
                count1++;
            }
        }

        for(int i = 0; i < nums2.size(); i++) {
            if(map1[nums2[i]] > 0) {
                count2++;
            }
        }

        return {count1, count2};
    }
};