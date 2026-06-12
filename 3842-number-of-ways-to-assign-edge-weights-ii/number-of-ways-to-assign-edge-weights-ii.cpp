class Solution {
public:
    static const int MOD = 1e9 + 7;
    static const int LOG = 17;
    
    int n;
    vector<vector<int>> adj;
    vector<int> depth;
    vector<array<int, 17>> up; 
    
    void dfs(int node, int parent, int d) {
        depth[node] = d;
        up[node][0] = parent;
        for (int j = 1; j < LOG; j++) {
            up[node][j] = up[up[node][j-1]][j-1];
        }
        for (int neighbor : adj[node]) {
            if (neighbor != parent) {
                dfs(neighbor, node, d + 1);
            }
        }
    }
    
    int lca(int u, int v) {
        if (depth[u] < depth[v]) swap(u, v);
        int diff = depth[u] - depth[v];
        // Bring u to same depth as v
        for (int j = 0; j < LOG; j++) {
            if ((diff >> j) & 1) {
                u = up[u][j];
            }
        }
        if (u == v) return u;
        // Lift both until LCA
        for (int j = LOG - 1; j >= 0; j--) {
            if (up[u][j] != up[v][j]) {
                u = up[u][j];
                v = up[v][j];
            }
        }
        return up[u][0];
    }
    
    long long power(long long base, long long exp, long long mod) {
        long long result = 1;
        base %= mod;
        while (exp > 0) {
            if (exp & 1) result = result * base % mod;
            base = base * base % mod;
            exp >>= 1;
        }
        return result;
    }
    
    vector<int> assignEdgeWeights(vector<vector<int>>& edges, vector<vector<int>>& queries) {
        n = edges.size() + 1;
        adj.resize(n + 1);
        depth.resize(n + 1, 0);
        up.resize(n + 1);
        
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        
        // Initialize ancestors to self (for root's parent)
        for (int i = 0; i <= n; i++) up[i].fill(1); // root's parent = root (node 1)
        
        dfs(1, 1, 0);
        
        vector<int> answer;
        answer.reserve(queries.size());
        
        for (auto& q : queries) {
            int u = q[0], v = q[1];
            int l = lca(u, v);
            int pathLen = depth[u] + depth[v] - 2 * depth[l];
            
            if (pathLen == 0) {
                answer.push_back(0);
            } else {
                long long ways = power(2, pathLen - 1, MOD);
                answer.push_back((int)ways);
            }
        }
        
        return answer;
    }
};