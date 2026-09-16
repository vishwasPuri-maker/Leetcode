class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {

        int freq[26] = {0};

        for(int i = 0; i < tasks.size(); i++) {
            freq[tasks[i] - 'A']++;
        }

        int maxFreq = 0;

        for(int i = 0; i < 26; i++) {
            maxFreq = max(maxFreq, freq[i]);
        }

        int result = (maxFreq - 1) * (n + 1);

        for(int i = 0; i < 26; i++) {
            if(freq[i] == maxFreq) {
                result++;
            }
        }

        return max((int)tasks.size(), result);
    }
};