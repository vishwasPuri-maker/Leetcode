class Solution {
public:
    struct Node {
        long long cnt;
        long long wav;
    };

    string s;
    Node dp[20][11][11][2][20];
    bool vis[20][11][11][2][20];

    Node dfs(int pos, int prev2, int prev1,
             bool started, int len, bool tight) {

        if (pos == s.size()) {
            return {1, 0};
        }

        if (!tight && vis[pos][prev2][prev1][started][len]) {
            return dp[pos][prev2][prev1][started][len];
        }

        int limit = tight ? s[pos] - '0' : 9;

        Node ans = {0, 0};

        for (int d = 0; d <= limit; d++) {

            bool ntight = tight && (d == limit);

            if (!started && d == 0) {
                Node nxt = dfs(pos + 1, 10, 10, false, 0, ntight);

                ans.cnt += nxt.cnt;
                ans.wav += nxt.wav;
            }
            else {

                if (!started) {
                    Node nxt = dfs(pos + 1, 10, d, true, 1, ntight);

                    ans.cnt += nxt.cnt;
                    ans.wav += nxt.wav;
                }
                else {

                    int add = 0;

                    if (len >= 2) {
                        if ((prev1 > prev2 && prev1 > d) ||
                            (prev1 < prev2 && prev1 < d)) {
                            add = 1;
                        }
                    }

                    Node nxt = dfs(pos + 1,
                                   prev1,
                                   d,
                                   true,
                                   len + 1,
                                   ntight);

                    ans.cnt += nxt.cnt;
                    ans.wav += nxt.wav + 1LL * add * nxt.cnt;
                }
            }
        }

        if (!tight) {
            vis[pos][prev2][prev1][started][len] = true;
            dp[pos][prev2][prev1][started][len] = ans;
        }

        return ans;
    }

    long long solve(long long x) {
        if (x < 0) return 0;

        s = to_string(x);
        memset(vis, 0, sizeof(vis));

        return dfs(0, 10, 10, false, 0, true).wav;
    }

    long long totalWaviness(long long num1, long long num2) {
        return solve(num2) - solve(num1 - 1);
    }
};