class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        unordered_map<int, vector<int>> posMap;
        for (int i = 0; i < n; ++i) {
            posMap[nums[i]].push_back(i);
        }
        
        vector<int> results;
        results.reserve(queries.size());
        
        for (int qIdx : queries) {
            int targetVal = nums[qIdx];
            const vector<int>& indices = posMap[targetVal];
            if (indices.size() == 1) {
                results.push_back(-1);
                continue;
            }
            
           
            auto it = lower_bound(indices.begin(), indices.end(), qIdx);
            int pos = distance(indices.begin(), it);
            
            
            int leftNeighbor, rightNeighbor;
            if (pos == 0) leftNeighbor = indices.back();
            else leftNeighbor = indices[pos - 1];
            
            
            if (pos == indices.size() - 1) rightNeighbor = indices.front();
            else rightNeighbor = indices[pos + 1];
            
            auto getDist = [&](int i, int j) {
                int d = abs(i - j);
                return min(d, n - d);
            };
            
            results.push_back(min(getDist(qIdx, leftNeighbor), getDist(qIdx, rightNeighbor)));
        }
        
        return results;
    }
};