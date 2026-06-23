class Solution {
public:
    int zigZagArrays(int n, int l, int r) {
        const long long MOD = 1000000007LL;
        int m = r - l + 1;
        long long steps = (long long)n - 2;        
       
        if (steps * (long long)m <= 50000000LL) {
            vector<long long> up(m), down(m), nup(m), ndown(m);
            for (int i = 0; i < m; i++) { up[i] = i; down[i] = m - 1 - i; }
            for (long long s = 0; s < steps; s++) {
                long long acc = 0;
                for (int i = 0; i < m; i++) { nup[i] = acc; acc += down[i]; if (acc >= MOD) acc -= MOD; }
                acc = 0;
                for (int i = m - 1; i >= 0; i--) { ndown[i] = acc; acc += up[i]; if (acc >= MOD) acc -= MOD; }
                swap(up, nup); swap(down, ndown);
            }
            long long ans = 0;
            for (int i = 0; i < m; i++) ans = (ans + up[i] + down[i]) % MOD;
            return (int)ans;
        }
        int d = m;
        auto mul = [&](const vector<vector<long long>>& X, const vector<vector<long long>>& Y) {
            vector<vector<long long>> Z(d, vector<long long>(d, 0));
            for (int i = 0; i < d; i++)
                for (int k = 0; k < d; k++) {
                    long long x = X[i][k]; if (!x) continue;
                    const auto& Yr = Y[k]; auto& Zr = Z[i];
                    for (int j = 0; j < d; j++) Zr[j] = (Zr[j] + x * Yr[j]) % MOD;
                }
            return Z;
        };
        vector<vector<long long>> A(d, vector<long long>(d, 0)), R(d, vector<long long>(d, 0));
        for (int i = 0; i < d; i++) for (int k = 0; k < d; k++) if (k + i >= m) A[i][k] = 1;
        for (int i = 0; i < d; i++) R[i][i] = 1;
        for (long long e = steps; e > 0; e >>= 1) { if (e & 1) R = mul(R, A); A = mul(A, A); }

        long long sum = 0;                            
        for (int i = 0; i < d; i++) {
            long long v = 0;
            for (int k = 0; k < d; k++) v = (v + R[i][k] * (long long)k) % MOD;
            sum = (sum + v) % MOD;
        }
        return (int)((2 * sum) % MOD);
    }
};