class Solution {
public:
    int minMoves(vector<int>& nums) {
        // int moves = 0;

        // while (true) {
        //     int mn = INT_MAX;
        //     int mx = INT_MIN;
        //     int maxIndex = -1;

        //     for (int i = 0; i < nums.size(); i++) {
        //         if (nums[i] > mx) {
        //             mx = nums[i];
        //             maxIndex = i;
        //         }
        //         mn = min(mn, nums[i]);
        //     }

        //     if (mn == mx) {
        //         break; 
        //     }

        //     for (int i = 0; i < nums.size(); i++) {
        //         if (i != maxIndex) {
        //             nums[i]++;
        //         }
        //     }

        //     moves++;
        // }

        // return moves;
        // This will get Time limit exeed that's why we use another approach 

        int minn=INT_MAX;
        for(int i=0;i<nums.size();i++){
            minn=min(minn,nums[i]);
        }
        int moves=0;
        for(int i=0;i<nums.size();i++){
            moves+= nums[i]-minn;
        }
        return moves;
    }
};