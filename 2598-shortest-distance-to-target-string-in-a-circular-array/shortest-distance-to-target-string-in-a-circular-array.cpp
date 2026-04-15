class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n = words.size();
        int minDistance = n; 
        bool found = false;

        for (int i = 0; i < n; i++) {
            if (words[i] == target) {
                found = true;
                int dist = abs(i - startIndex);
                minDistance = min({minDistance, dist, n - dist});
            }
        }

        return found ? minDistance : -1;
    }
};