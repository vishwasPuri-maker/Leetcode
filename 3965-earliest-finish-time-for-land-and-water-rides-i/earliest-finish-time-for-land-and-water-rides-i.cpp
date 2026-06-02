class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int n= landStartTime.size();
        int m= waterStartTime.size();

        int ans= INT_MAX;
        int minLand= INT_MAX;

        for(int i=0 ;i<n;i++){
            minLand= min(minLand , landStartTime[i]+landDuration[i]);
        }

        for(int i=0;i<m;i++){
            int finish= max(minLand , waterStartTime[i]) + waterDuration[i];
            ans=min(ans, finish);
        }
         int waterLand= INT_MAX;

        for(int i=0 ;i<m;i++){
            waterLand= min(waterLand , waterStartTime[i]+waterDuration[i]);
        }

        for(int i=0;i<n;i++){
            int finish= max(waterLand , landStartTime[i]) + landDuration[i];
            ans=min(ans, finish);
        }

        return ans;

    }
};