class Solution {
public:
    int maxSum(vector<int>& nums) {
        int maxnumFordidgit[10] = {0};
        int ans = -1;

        for(auto num : nums){
            int maxD = 0;
            int temp = num;

            while(temp){
                maxD = max(maxD,temp%10); 
                temp = temp/10;
            }

            if(maxnumFordidgit[maxD]){
                ans = max(ans ,maxnumFordidgit[maxD]+num );
            }
            if(num > maxnumFordidgit[maxD]){
                maxnumFordidgit[maxD] = num;
            }

        }
        return ans;
    }
};