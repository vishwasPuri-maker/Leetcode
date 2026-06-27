class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long, int> cnt;
        for (int x : nums) cnt[x]++;
        int ans = cnt[1] - ((cnt[1] % 2) ^ 1);
        cnt.erase(1);

        for (auto &[v, _] : cnt) {
            long long x = v;
            int len = 0;
            while (cnt.count(x) && cnt[x] > 1) {
                len += 2;
                x = x * x;
            }
            len += cnt.count(x) ? 1 : -1;

            ans = max(ans, len);
        }

        return ans;
    }
};