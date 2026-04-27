class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        // Brute force 
        // int n = nums.size();
        // vector<int> result;
        // if(n==0){
        //     return result;
        // }
        // int count = 1;
        // int x=0;
        // sort(nums.begin(),nums.end());
        // for(int i=0;i<n;i++){
        //     if(i<n-1 && nums[i]==nums[i+1]){
        //         count=count+1;
        //     }
        //     else{
        //         if (count > n / 3) {
        //             result.push_back(nums[i]);
        //         }
        //         count=1;
        //     }
        // }
        // return result;

        // Here we write optimal 


        //Now this is best approach 
        int n=nums.size();
        int count1=0;
        int count2=0;
        int element1=0;
        int element2=0;
        for(int i=0;i<n;i++){
            if(count1==0 && nums[i]!=element2){
                count1=1;
                element1=nums[i];
            }
            else if(count2==0 && nums[i]!=element1){
                count2=1;
                element2=nums[i];
            }
            else if(element1==nums[i]){
                count1++;
            }
            else if(element2==nums[i]){
                count2++;
            }
            else{
                count1--;
                count2--;

            }
        }
        vector<int> result;
        count1=0;
        count2=0;
        int x=n/3;
        for(int i=0; i<n;i++){
            if(nums[i]==element1){
                count1++;
            }
            else if(nums[i]==element2){
                count2++;
            }
        }
        if(count1>x){
            result.push_back(element1);
        }
        if(count2>x){
            result.push_back(element2);
        }
        return result;
    }
};