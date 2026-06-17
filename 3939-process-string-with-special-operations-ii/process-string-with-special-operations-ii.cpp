class Solution {
public:
    char processStr(string s, long long k) {
        long long len = 0;

        for (int i = 0; i < s.size(); i++) {
            char c = s[i];

            if (c == '*') {
                len = max(0LL, len - 1);
            }
            else if (c == '#') {
                len *= 2;
            }
            else if (c == '%') {
                continue;
            }
            else {
                len++;
            }
        }

        if (k >= len) {
            return '.';
        }

        for (int i = s.size() - 1; i >= 0; i--) {
            char c = s[i];

            if (c == '*') {
                len++;
            }
            else if (c == '#') {
                len /= 2;

                if (k >= len) {
                    k -= len;
                }
            }
            else if (c == '%') {
                k = len - 1 - k;
            }
            else {
                len--;

                if (k == len) {
                    return c;
                }
            }
        }

        return '.';
    }
};