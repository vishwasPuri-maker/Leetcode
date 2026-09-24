class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        unordered_map<int, int> map;
        vector<int> ans;

        for(int i = 0; i < digits.size(); i++) {
            map[digits[i]]++;
        }

        for(int i = 100; i < 1000; i += 2) {
            int x = i;

            int a = x % 10;
            x = x / 10;

            int b = x % 10;
            x = x / 10;

            int c = x;

            if(map[a] > 0) {
                map[a]--;

                if(map[b] > 0) {
                    map[b]--;

                    if(map[c] > 0) {
                        ans.push_back(i);
                    }

                    map[b]++;
                }

                map[a]++;
            }
        }

        return ans;
    }
};