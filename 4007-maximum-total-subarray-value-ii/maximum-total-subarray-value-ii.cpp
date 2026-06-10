class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {

        int n = nums.size();

        auto get_prev_indices = [&](const vector<int>& arr, auto comp) {
            vector<int> prev(n, -1);
            stack<int> s;
            for (int i = 0; i < n; ++i) {
                while (!s.empty() && !comp(arr[s.top()], arr[i])) {
                    s.pop();
                }
                if (!s.empty()) {
                    prev[i] = s.top();
                }
                s.push(i);
            }
            return prev;
        };

        auto get_next_indices = [&](const vector<int>& arr, auto comp) {
            vector<int> next_idx(n, n);
            stack<int> s;
            for (int i = n - 1; i >= 0; --i) {
                while (!s.empty() && !comp(arr[s.top()], arr[i])) {
                    s.pop();
                }
                if (!s.empty()) {
                    next_idx[i] = s.top();
                }
                s.push(i);
            }
            return next_idx;
        };

        auto calc_total_sum = [&]() {
            auto L_g = get_prev_indices(nums, [](int a, int b) { return a > b; });
            auto R_ge = get_next_indices(nums, [](int a, int b) { return a >= b; });
            
            long long total_max_sum = 0;
            for (int i = 0; i < n; ++i) {
                total_max_sum += (long long)nums[i] * (i - L_g[i]) * (R_ge[i] - i);
            }
            
            auto L_l = get_prev_indices(nums, [](int a, int b) { return a < b; });
            auto R_le = get_next_indices(nums, [](int a, int b) { return a <= b; });

            long long total_min_sum = 0;
            for (int i = 0; i < n; ++i) {
                total_min_sum += (long long)nums[i] * (i - L_l[i]) * (R_le[i] - i);
            }
            
            return total_max_sum - total_min_sum;
        };

        auto check_less = [&](int m) {
            long long count = 0;
            long long sum_diff = 0;
            int l = 0;
            
            deque<int> min_q;
            deque<int> max_q;
            
            vector<pair<int, int>> max_stk;
            vector<long long> max_stk_ps;
            vector<pair<int, int>> min_stk;
            vector<long long> min_stk_ps;
            
            for (int r = 0; r < n; ++r) {
                int v = nums[r];
                
                // Update max_stk
                int prev_idx = -1;
                while (!max_stk.empty() && max_stk.back().second <= v) {
                    max_stk.pop_back();
                    max_stk_ps.pop_back();
                }
                if (!max_stk.empty()) {
                    prev_idx = max_stk.back().first;
                }
                long long term = (long long)(r - prev_idx) * v;
                long long new_ps = (max_stk_ps.empty() ? 0 : max_stk_ps.back()) + term;
                max_stk.push_back({r, v});
                max_stk_ps.push_back(new_ps);
                
                // Update min_stk
                prev_idx = -1;
                while (!min_stk.empty() && min_stk.back().second >= v) {
                    min_stk.pop_back();
                    min_stk_ps.pop_back();
                }
                if (!min_stk.empty()) {
                    prev_idx = min_stk.back().first;
                }
                term = (long long)(r - prev_idx) * v;
                new_ps = (min_stk_ps.empty() ? 0 : min_stk_ps.back()) + term;
                min_stk.push_back({r, v});
                min_stk_ps.push_back(new_ps);
                
                while (!max_q.empty() && nums[max_q.back()] <= v) {
                    max_q.pop_back();
                }
                max_q.push_back(r);
                while (!min_q.empty() && nums[min_q.back()] >= v) {
                    min_q.pop_back();
                }
                min_q.push_back(r);
                
                while (!max_q.empty() && !min_q.empty() && nums[max_q.front()] - nums[min_q.front()] >= m) {
                    l++;
                    if (!max_q.empty() && max_q.front() < l) {
                        max_q.pop_front();
                    }
                    if (!min_q.empty() && min_q.front() < l) {
                        min_q.pop_front();
                    }
                }
                
                count += (r - l + 1);
                
                if (l <= r) {
                    auto it_max = lower_bound(max_stk.begin(), max_stk.end(), make_pair(l, INT_MIN));
                    int k_max = distance(max_stk.begin(), it_max);
                    int i_k_max, v_k_max;
                    long long ps_k_max;
                    
                    if (it_max != max_stk.end()) {
                        i_k_max = max_stk[k_max].first;
                        v_k_max = max_stk[k_max].second;
                        ps_k_max = max_stk_ps[k_max];
                    } else {
                        i_k_max = max_stk.back().first;
                        v_k_max = max_stk.back().second;
                        ps_k_max = max_stk_ps.back();
                    }

                    long long sum_max_l_r = (long long)(i_k_max - l + 1) * v_k_max + (max_stk_ps.back() - ps_k_max);

                    auto it_min = lower_bound(min_stk.begin(), min_stk.end(), make_pair(l, INT_MIN));
                    int k_min = distance(min_stk.begin(), it_min);
                    int i_k_min, v_k_min;
                    long long ps_k_min;

                    if (it_min != min_stk.end()) {
                        i_k_min = min_stk[k_min].first;
                        v_k_min = min_stk[k_min].second;
                        ps_k_min = min_stk_ps[k_min];
                    } else {
                        i_k_min = min_stk.back().first;
                        v_k_min = min_stk.back().second;
                        ps_k_min = min_stk_ps.back();
                    }
                    
                    long long sum_min_l_r = (long long)(i_k_min - l + 1) * v_k_min + (max_stk_ps.back() == 0 ? 0 : min_stk_ps.back() - ps_k_min);

                    sum_diff += sum_max_l_r - sum_min_l_r;
                }
            }

            return make_pair(count, sum_diff);
        };

        long long total_sum = calc_total_sum();
        
        int low = 0, high = 1000000000;
        int ans_val = 0;
        long long n_total = (long long)n * (n + 1) / 2;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            auto [c_less, _] = check_less(mid);
            if (n_total - c_less >= k) {
                ans_val = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        
        auto [c_less_ans_val1, s_less_ans_val1] = check_less(ans_val + 1);
        long long count_gt = n_total - c_less_ans_val1;
        long long sum_gt = total_sum - s_less_ans_val1;
        
        long long result = sum_gt + (long long)(k - count_gt) * ans_val;
        return result;
    }
};